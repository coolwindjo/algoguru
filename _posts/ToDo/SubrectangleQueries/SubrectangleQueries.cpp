#if 1
#define TEST
#endif // 1

#include "../../ProbSolvStart.h"

#if 0
#pragma GCC optimize("O2") 
#endif 

typedef vector<vvi> vvvi;

class ProbSolv
{
    vstr m_vstrC;
    vvi m_vviRect;
    vvi m_vviArgs;
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

        string delims("\", \n");
        m_vstrC = _SplitString(line, delims+"[]");
        
        FOR (i, 10) {
            getline(cin, line);
            if (line.length() > 2) {
                break;
            }
        }

        vstr vstrArgs = _SplitString(line, delims, "[]");
        int cnt = 0;
        int comCnt = 0;
        int rowCnt = 0;
        int consecCloses = 0;
        vvvi vvviA;
        vvviA.push_back(vvi());
        for (string str : vstrArgs) {
            if ("[" == str) {
                if (cnt < 3) {
                    cnt++;
                    continue;
                }
                consecCloses = 0;
                vvviA[comCnt].push_back(vi());
            }
            else if ("]" == str) {
                if (consecCloses == 2) {
                    vvviA.push_back(vvi());
                    comCnt++;
                    rowCnt = 0;
                    consecCloses = 0;
                }
                else {
                    rowCnt++;
                    consecCloses++;
                }

            }
            else {
                consecCloses = 0;
                vvviA[comCnt][rowCnt].push_back(stoi(str));
            }
            cnt++;
        }

        m_vviRect = vvviA[0];
        m_vviArgs = vvviA[1];

        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){

    } // _Solve()

    class SubrectangleQueries {
    public:
        SubrectangleQueries(vector<vector<int>>& rectangle) {
            
        }
        
        void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
            
        }
        
        int getValue(int row, int col) {
            
        }
    };

#if 1   // 62yy
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