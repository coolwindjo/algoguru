#if 1
#define TEST
#endif // 1

#include "../../ProbSolvStart.h"

#if 0
#pragma GCC optimize("O2") 
#endif 

class ProbSolv
{
    stack<char> m_S;
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
        string strInput = line.substr(1,line.length()-2);

        _Solve(strInput);
    }
    ~ProbSolv(){}

private:
    void _Solve(string s){
        cout << boolalpha << isValid(s);
    } // _Solve()

    bool isPair(const char c1, const char c2) {
        return (c1 == '(' && c2 == ')')
            || (c1 == '{' && c2 == '}')
            || (c1 == '[' && c2 == ']');
    }
    
    bool isOpening(const char c) {
        return (c == '(') || (c == '{') || (c == '[');
    }
    
    bool isValid(string s) {
        FOR(i, s.length()) {
            const char c = s[i];
            if (isOpening(c)) {
                m_S.push(s[i]);
                continue;
            }
            if (!m_S.empty()) {
                if (isPair(m_S.top(), c)) {
                    m_S.pop();
                }
                else return false;
            }
            else return false;
        }
        if (m_S.empty()) return true;
        else return false;
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