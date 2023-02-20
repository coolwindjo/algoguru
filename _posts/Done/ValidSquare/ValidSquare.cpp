#if 1
#define TEST
#endif // 1

#include "../../ProbSolvStart.h"

#if 0
#pragma GCC optimize("O2") 
#endif 

class ProbSolv
{
    vvi m_vviPts;
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

        vstr vstrSplits = _SplitString(line, "[]=, \n");

        bool isFirst = true;
        vi viPt;
        for (string strNum : vstrSplits) {
            if (strNum[0] == 'p') {
                continue;
            }
            viPt.push_back(stoi(strNum));
            if (isFirst == true) {
                isFirst = false;
            }
            else {
                m_vviPts.push_back(viPt);
                viPt.clear();
                isFirst = true;
            }
        }
        
        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){
        cout << boolalpha << validSquare(m_vviPts[0], m_vviPts[1], m_vviPts[2], m_vviPts[3]);
    } // _Solve()

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vvi vviPts;
        vviPts.push_back(p1);
        vviPts.push_back(p2);
        vviPts.push_back(p3);
        vviPts.push_back(p4);
        int maxLen = 1;
        maxLen = calMaxDistSq(vviPts, maxLen);
        
        vvi vviEndPts = getEndPts(vviPts, maxLen);
        
        if (vviEndPts.size() < 4) {
            return false;
        }
        
        const int prod = product(vviEndPts);
        if (prod == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    
    int calMaxDistSq(const vvi& vviPts, const int initMaxLen) {
        int maxLen = initMaxLen;
        for (int i=0; i<3; ++i) {
            const vi pt1 = vviPts[i];
            for (int j=i; j<4; ++j) {
                const vi pt2 = vviPts[j];
                const int len = distSq(pt1, pt2);
                if (len > maxLen) {
                    maxLen = len;
                }
            }
        }
        return maxLen;
    }
    
    int distSq(vi pt1, vi pt2) {
        const int deltaX = (pt1[0]-pt2[0]);
        const int deltaY = (pt1[1]-pt2[1]);
        const int len = deltaX*deltaX + deltaY*deltaY;
        return len;
    }
    
    vvi getEndPts(const vvi& vviPts, const int maxDistSq) {
        vvi vviEndPts;
        for (int i=0; i<3; ++i) {
            const vi pt1 = vviPts[i];
            for (int j=i; j<4; ++j) {
                const vi pt2 = vviPts[j];
                const int len = distSq(pt1, pt2);
                if (len >= maxDistSq) {
                    vviEndPts.push_back(pt1);
                    vviEndPts.push_back(pt2);
                }
            }
        }
        return vviEndPts;
    }
    
    int product(const vvi& vviEndPts) {
        vi viPtA, viPtB;
        
        viPtA.push_back(vviEndPts[0][0] - vviEndPts[1][0]);
        viPtA.push_back(vviEndPts[0][1] - vviEndPts[1][1]);
        
        viPtB.push_back(vviEndPts[2][0] - vviEndPts[3][0]);
        viPtB.push_back(vviEndPts[2][1] - vviEndPts[3][1]);
        
        return viPtA[0]*viPtB[0] + viPtA[1]*viPtB[1];
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