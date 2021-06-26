#if 1
#define TEST
#endif // 1

#include "../../ProbSolvStart.h"

typedef vector<bool> vb;
class ProbSolv
{
    vi m_viCandies;
    int m_exN;
public:
    ProbSolv()
    {
        string line;
        FOR(i, 10){
            getline(cin, line);
            if (line.length() > 2){
                break;
            }
        }
        vstr vstrNums = _SplitString(line, "[],\n ");

        for (string strNum : vstrNums){
            m_viCandies.push_back(std::stoi(strNum));
        }
        m_exN = m_viCandies.back(); m_viCandies.pop_back();
        
        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){
        vb vbAns = kidsWithCandies(m_viCandies, m_exN);
        cout << "[";
        for (bool ans : vbAns) {
            cout << boolalpha << ans << ",";
        }
        cout << "]"<<endl;
    } // _Solve()

    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vb vbAns;
        int max = 0;
        for (const int kid : candies) {
            if (kid > max) {
                max = kid;
            }
        }
        for (const int kid : candies) {
            const int kid_with_ex = kid + extraCandies;
            vbAns.push_back((kid_with_ex >= max));
        }
        return vbAns;
    }

#if 0   // 62yy
#define SPLIT_DEBUG
#endif // 1

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