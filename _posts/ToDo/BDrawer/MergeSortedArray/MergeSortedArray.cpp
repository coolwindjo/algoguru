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
    vi nums1_;
    vi nums2_;
    int m_, n_;

public:
    ProbSolv()
    {
        string line;
        FOR (i, 10) {
            getline(cin, line);
            if (line.length() > 2) {
                break;
            }
        }
        vstr vstrSplits = _SplitString(line, "[],= \n");

        int isFirst = 2;
        bool isNum = false;
        char m_or_n = '\0';
        for (string str : vstrSplits) {
            if ((str[0] == 'm' || str[0] == 'n') && str.length() == 1) {
                m_or_n = str[0];
                isNum = true;
                continue;
            }

            if (isNum && (m_or_n == 'm')) {
                m_ = stoi(str);
                isNum = false;
            }
            else if (isNum && (m_or_n == 'n')) {
                n_ = stoi(str);
                isNum = false;
            }
            else {
                if (isFirst && (str[0] == 'n')) {
                    isFirst--;
                    continue;
                }

                if (isFirst) {
                    nums1_.push_back(stoi(str));
                }
                else {
                    nums2_.push_back(stoi(str));
                }
            }
        }

        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve() { 
        merge(nums1_, m_, nums2_, n_);
        FOR(i, nums1_.size()) {
            cout << nums1_[i] << " ";
        }
    }  // _Solve()

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;
        if (n == 0) return;
        for(int i=0; i<m+n; i++) {
            if ((nums1[i] == 0) || (nums1[i] > nums2[j])) {
                if (nums1[i] != 0 || i>=m)  {
                    for(int k=m+n-1; k>=i+1; k--) {
                        nums1[k] = nums1[k-1];
                    }
                }
                if (j<n) {
                    nums1[i] = nums2[j];
                    j++;
                }
            }
        }
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
        line.erase(newEnd-1, end(line));
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
