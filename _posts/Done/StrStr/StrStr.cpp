#if 1
#define TEST
#endif // 1
#define TEST1

#include "../../ProbSolvStart.h"

#if 0
#pragma GCC optimize("O1")
#endif

class ProbSolv
{
    static constexpr int INF = 65432;
public:
    string target_;
    string pattern_;
    ProbSolv()
    {
        string line;
        for (int i=0; i<10; ++i) {
            getline(cin, line);
            if (line.length() > 2) break;
        }
        vstr vstrInput = _SplitString(line, "\n\t, ", "\"");
        bool isTarget = true;
        bool isValid = false;
        for (auto str : vstrInput) {
            if (str == "\"") {
                isValid = !isValid;
                continue;
            }
            if (isValid) {
                if (isTarget) {
                    target_ = str;
                    isTarget = false;
                } else {
                    pattern_ = str;
                }
            }

        }
        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){
        {
            CoolTimer timer("KMP");
            cout << strStr_KMP(target_, pattern_);
        }
        {
            CoolTimer timer("Rolling Hash");
            cout << strStr_Rabin_Karp(target_, pattern_);
        }
        {
            CoolTimer timer("STD");
            cout << strStr_STD(target_, pattern_);
        }
    } // _Solve()

    int strStr_STD(string haystack, string needle) {
        int idx = haystack.find(needle);
        if (idx == std::string::npos) return -1;
        return idx;
    }

    int strStr_Rabin_Karp(string haystack, string needle) {
        const int key_hash = hash(needle);
        const int key_size = needle.size();
        if (key_size <= haystack.size()) {
            for (int i=0; i<haystack.size()-key_size+1; ++i) {
                const string hs = haystack.substr(i, key_size);
                if (key_hash == hash(hs)) {
                    return i;
                }
            }
        }
        return -1;
    }
    int hash(string str) {
        int sum = 0;
        for (const auto c : str) {
            sum += c-'a';
        }
        return std::hash<std::string>{}(str)*sum;
    }

    int strStr_KMP(string haystack, string needle) {
        /*/
        vector<int> lps = kmp_prepare(needle);
        for (auto n : lps) {
            cout << n << ", ";
        }
        cout <<endl;

        return kmp_search(haystack, needle, lps);
        /*/
        vector<int> lps = longest_proper_suffix(needle);
        for (auto n : lps) {
            cout << n << ", ";
        }
        cout <<endl;

        return kmp_process(haystack, needle, lps);
        //*/
    }

    vector<int> longest_proper_suffix(const string &P) {
        const int p = P.size();
        vector<int> lps(p, 0);
        for (int i=1, len=0, lim=INF; i < p &&lim>0;--lim) {
            if (P[i] == P[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len-1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }
    int kmp_process(const string &T, const string &P, const vector<int> &lps) {
        const int t = T.size();
        const int p = P.size();
        if (t==0) return 0;

        for (int i=0, j=0, lim=INF; i < t &&lim>0;--lim) {
            if (T[i] == P[j]) {i++, j++;}
            if (j == p) return i-j;
            if (i < t && T[i] != P[j]) {
                j ? j = lps[j-1] : i++;
            }
        }

        return -1;
    }

    vector<int> kmp_prepare(const string &P) {
        const int p = P.size();
        vector<int> lps(p+1, 0);
        lps[0] = -1;
        int j=-1;
        for (int i=0, lim=INF; i < p &&lim>0;--lim) {
            for(;j>=0 && P[i] != P[j] &&lim>0;--lim) {
                j = lps[j];
            }
            ++i; ++j;
            lps[i] = j;
        }
        return lps;
    }
    int kmp_search(const string &T, const string &P, const vector<int> &lps) {
        const int t = T.size();
        const int p = P.size();
        int idx = -1;
        for (int i=0,j=0, lim=INF; i < t &&lim>0;--lim) {
            for (;j >= 0 && T[i] != P[j]&&lim>0;--lim) {
                j = lps[j];
            }
            ++i, ++j;
            if (j == p) {
                idx = i-j;
                j = lps[j];
                break;
            }
        }
        return idx;
    }

#if 0
#define SPLIT_DEBUG
#endif // 1

    vstr _SplitString(string line, const string& delims, const string& separator = "") {
#ifdef SPLIT_DEBUG
        line += "       !";
        cout << "\n1) line: " << line <<endl;
        string::iterator newEnd = unique(begin(line), end(line), [](const char& x, const char& y) {
            return x == y and x == ' ';
        });
        cout << "2) line: " << line <<endl;
        line.erase(newEnd, end(line));
        cout << "3) line: " << line <<endl;
#else
        line.erase(unique(begin(line), end(line),
                          [](const char& x, const char& y) { return x == y and x == ' '; }),
                   end(line));
#endif
        while (line[line.length() - 1] == ' ') {
            line.pop_back();
        }

        vstr vstrSplits;
        size_t prev = 0U;
        size_t pos = 0U;
        while (prev < line.length()) {
            if ((pos = line.find_first_of(delims, prev)) == string::npos) {
                pos = line.length();
            }
            const int wlen = pos - prev;
            if (wlen > 0) { // word exists before next delimiter
                size_t sub_prev = 0U;
                size_t sub_pos = 0U;
                const string sub_str = line.substr(prev, wlen);
                while ((sub_pos = sub_str.find_first_of(separator, sub_prev)) != string::npos) {
                    const int sub_wlen = sub_pos - sub_prev;
                    if (sub_wlen > 0) { // word exists before next separator
                        vstrSplits.push_back(sub_str.substr(sub_prev, sub_wlen));
                        vstrSplits.push_back(sub_str.substr((sub_prev + sub_wlen), 1));
                    } else {
                        vstrSplits.push_back(sub_str.substr(sub_prev, 1));
                    }
                    sub_prev = sub_pos + 1;
                }
                prev += sub_prev;
                const int rem_wlen = wlen - sub_prev;
                if (rem_wlen > 0) {
                    vstrSplits.push_back(line.substr(prev, rem_wlen));
                }
            }
            prev = pos + 1;
        }

        return vstrSplits;
    }

};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int numTCs = 0;
    cin >> numTCs; cin.ignore();
    FOR (tc, numTCs) {
        cout << "#" << tc+1 <<" ";
        ProbSolv ps;
        cout << endl;
    }
    return 0;
}
