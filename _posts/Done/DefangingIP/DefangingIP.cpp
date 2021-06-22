#if 1
#define TEST
#endif // 1

#include "../../ProbSolvStart.h"

class ProbSolv
{
    string strIP;
public:
    ProbSolv()
    {
        FOR(i, 10){
            getline(cin, strIP);
            if (strIP.length() > 2){
                break;
            }
        }

        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){
        string strAns = defangIPaddr(strIP);
        cout << strAns;
    } // _Solve()

    string defangIPaddr(string address) {
        vstr vstrNums;
        size_t prev = 0;
        size_t pos = 0;
        while((pos=address.find_first_of("\".", prev))!=std::string::npos){
            int wlen = pos - prev;
            if (wlen > 0) {
                vstrNums.push_back(address.substr(prev, wlen));
            }
            prev = pos + 1;
        }
        int trail = address.length() - prev;
        if (trail > 0) {
            vstrNums.push_back(address.substr(prev, trail+1));
        }

        string strAns;
        for(string num : vstrNums){
            strAns += num;
            strAns += "[.]";
        }
        strAns = strAns.substr(0, (strAns.length()-3));
        return strAns;
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