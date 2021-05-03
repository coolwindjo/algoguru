#if 1
#define TEST
#endif // 1
#if 0
#define SPLIT_DEBUG
#endif // 1

#include "../../ProbSolvStart.h"

typedef enum {
	eR=0, eD,
    eL, eU,
    eDIR_LEN
} Dir_e;
constexpr int DIR[eDIR_LEN][2] = {
    {0,1}, {1,0},
    {0,-1}, {-1,0}
};
constexpr int N_DIR[eDIR_LEN] = {eL, eU, eR, eD};

class ProbSolv
{
    int m_M;
    int m_N;
    vvi m_vviMap;
    vii m_viiPuddles;

public:
    ProbSolv()
    {
        string line;
        FOR(i, 10){
            std::getline(std::cin, line);
            if(line.length() > 2){
                break;
            }
        }

        vstr vstrInputs = _SplitString(line, string("\t[], "));

        m_M = stoi(vstrInputs[0]);
        m_N = stoi(vstrInputs[1]);

        for (int idx=2; idx<vstrInputs.size(); idx+=2){
            ii pud(stoi(vstrInputs[idx]), stoi(vstrInputs[idx+1]));
            m_viiPuddles.push_back(pud);
        }

#ifdef TEST
        cout << m_M << ", " << m_N;
        cout << " pud : ";
        for (auto pud : m_viiPuddles){
            cout << "(" << pud.first << ", " << pud.second << ") ";
        }
        cout <<endl;
#endif // TEST

        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){

    } // _Solve()

#if 1 // 48dd
    vstr _SplitString(string line, const string &delims) {
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
        while ((pos = line.find_first_of(delims, prev)) != string::npos) {
            if (pos > prev) {
                vstrSplits.push_back(line.substr(prev, pos-prev));
            }
#ifdef SPLIT_DEBUG
            for(string str : vstrSplits) {
                cout << str << " ";
            }
            cout <<endl;
#endif
            prev = pos + 1;
        }

        if (prev < line.length()) {
            vstrSplits.push_back(line.substr(prev, min(pos, line.length()) - prev + 1));
        }

        return vstrSplits;
    }
#endif

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
