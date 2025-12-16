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
    string s_;
    string t_;
public:
    ProbSolv()
    {
        string line;
        FOR (i, 10) {
            std::getline(cin, line);
            if (line.length() > 2) break;
        }
        vstr vstrInput = _SplitString(line, "\n\t, ", "\"");
        bool isFirst = true;
        for (auto s : vstrInput) {
            if (s.length() > 1) {
                if (isFirst) {
                    s_ = s;
                    isFirst = false;
                }
                else t_ = s;
            }
        }

        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){
        std::cout << boolalpha << isIsomorphic(s_, t_);
    } // _Solve()

    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hashST;
        unordered_map<char, char> hashTS;
        bool isIsmp = true;
        for (int i = 0; i < s.size(); ++i) {
            const char c1 = s[i];
            const char c2 = t[i];
            if ((hashST.find(c1) == std::end(hashST)) && (hashTS.find(c2) == std::end(hashTS))) {
                hashST[c1] = c2;
                hashTS[c2] = c1;
            } else if (hashST[c1] == c2) {
                // Do nothing
            } else {
                isIsmp = false;
                break;
            }
        }
        return isIsmp;
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
