#if 0
#define TEST
#endif // 1
#if 0
#define SPLIT_DEBUG
#endif // 1

#include "../../ProbSolvStart.h"

class ProbSolv
{
    vi m_viNums;
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
        vstr vstrNums = _SplitString(line, string("\r, []"));
        for(auto str : vstrNums){
            m_viNums.push_back(std::stoi(str));
        }

        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){
        vstr vstrNums;
        int numZeros = 0;
        for(auto num: m_viNums){
            vstrNums.push_back(std::to_string(num));
            if (num == 0) numZeros++;
        }
        string answer = "";
        if (numZeros == m_viNums.size()){
            answer += vstrNums[0];
            cout << answer;
            return;
        }
        std::sort(vstrNums.begin(), vstrNums.end(), [](const string &a, const string &b){
            string aFirst = a+b;
            string bFirst = b+a;
            return std::stoi(aFirst) > std::stoi(bFirst);
        });
        for (auto str : vstrNums){
#ifdef TEST
            answer += " ";
#endif
            answer += str;
        }
        cout << answer;
    } // _Solve()

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
