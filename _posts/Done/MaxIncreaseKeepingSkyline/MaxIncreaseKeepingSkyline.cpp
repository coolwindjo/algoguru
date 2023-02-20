#if 1
#define TEST
#endif // 1

#include "../../ProbSolvStart.h"

#if 0
#pragma GCC optimize("O2") 
#endif 

class ProbSolv
{
    vvi m_vviGrid;
public:
    ProbSolv()
    {
        string line;
        FOR (i, 10) {
            getline(cin,line);
            if (line.length() > 2) {
                break;
            }
        }
        
        vstr vstrSplits = _SplitString(line, ", \n", "[]");
        vi viRow;
        for (string str : vstrSplits) {
            if (str == "[") {
                continue;
            }
            else if (str == "]") {
                if (!viRow.empty()) {
                    m_vviGrid.push_back(viRow);
                }
                viRow.clear();
            }
            else {
                viRow.push_back(stoi(str));
            }
        }

        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){
        cout << maxIncreaseKeepingSkyline(m_vviGrid);
    } // _Solve()

    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        const int n = grid.size();
        vi viRowMax(n, 0);
        vi viColMax(n, 0);
        FOR (r, n) {
            FOR (c, n) {
                const int val = grid[r][c];
                if (val > viRowMax[r]) {
                    viRowMax[r] = val;
                }
                if (val > viColMax[c]) {
                    viColMax[c] = val;
                }
            }
        }
        
        int sum = 0;
        FOR (r, n) {
            FOR (c, n) {
                const int limit = min(viRowMax[r], viColMax[c]);
                if (limit > grid[r][c]) {
                    sum += limit - grid[r][c];
                }
            }
        }
        return sum;
    }

#if 0   // 70yy
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
#ifdef SPLIT_DEBUG
        cout << "4) line: " << line <<endl;
#endif

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
#ifdef SPLIT_DEBUG
            for(string str : vstrSplits) {
                cout << str << " ";
            }
            cout <<endl;
#endif
            prev = pos + 1;
        }

        return vstrSplits;
    }

};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int numTCs = 0;
    cin >> numTCs;
    FOR (tc, numTCs) {
        cout << "#" << tc+1 <<" ";
        ProbSolv ps;
        cout << endl;
    }
    return 0;
}