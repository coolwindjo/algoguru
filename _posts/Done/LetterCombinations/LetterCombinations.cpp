#if 1
#define TEST
#endif // 1
#define TEST1

#include "../../ProbSolvStart.h"

#if 0
#pragma GCC optimize("O1") 
#endif 

typedef unordered_set<string> hashStr;

class ProbSolv
{
    string m_digits;
    unordered_map<int, string> lut {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };
        
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

        vstr vstrSplits = _SplitString(line, "\"\n ", "=");

        bool isNext = false;
        for (string s : vstrSplits) {
            if (s == "=") isNext = true;
            if (isNext) {
                m_digits = s;
            }
        }
        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){
        vstr vstrAns = letterCombinations(m_digits);
        cout << "[";
        for (auto s : vstrAns) {
            cout << "\"" << s << "\",";
        }
        cout << "]";
    } // _Solve()

    vector<string> letterCombinations(string digits) {
        hashStr hash;
        DFS(digits, 0, "", hash);
        vstr vstrAns;
        for (auto it=begin(hash); it!=end(hash); ++it) {
            vstrAns.push_back(*it);
        }
        return vstrAns;
    }
    
    void DFS(const string& digits, const int idx, const string& letComb, hashStr& hash) {
        if (digits.length() == 0) {
            return;
        }
        if (idx == digits.length()) {
            hash.insert(letComb);
            return;
        }
        
        const int num = (digits[idx] - '0');
        const string letters = lut[num];
        FOR (i, letters.length()) {
            DFS(digits, idx+1, letComb + letters.substr(i, 1), hash);
        }
    }

// 70yy
#if 0
#define SPLIT_DEBUG
#endif // 1

    vstr _SplitString(string line, const string& delims, const string& separator = "") {
#ifdef SPLIT_DEBUG
        cout << "\n1) line: " << line <<endl;
#endif
        string::iterator newEnd = unique(line.begin(), line.end(), [] (const char &x, const char &y) {
            return x==y and x==' ';
        });
#ifdef SPLIT_DEBUG
        cout << "2) line: " << line <<endl;
#endif

        line.erase(newEnd, line.end());
#ifdef SPLIT_DEBUG
        cout << "3) line: " << line <<endl;
#endif

        while (line[line.length() - 1] == ' ') {
            line.pop_back();
        }

        vstr vstrSplits;
        size_t prev = 0;
        size_t pos;
        while (prev < line.length()) {
            if ((pos = line.find_first_of(delims, prev)) == string::npos) {
                pos = line.length();
            }
            const int wlen = pos - prev;
            if (wlen > 0) {
                size_t sub_prev = 0;
                size_t sub_pos;
                const string sub_str = line.substr(prev, wlen);
                while ((sub_pos = sub_str.find_first_of(separator, sub_prev)) != string::npos) {
                    const int sub_wlen = sub_pos - sub_prev;
                    if (sub_wlen > 0) {
                        vstrSplits.push_back(sub_str.substr(sub_prev, sub_wlen));
                        vstrSplits.push_back(sub_str.substr((sub_prev+sub_wlen), 1));
                    }
                    else {
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
