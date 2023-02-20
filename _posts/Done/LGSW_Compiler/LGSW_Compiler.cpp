#if 0
#define TEST
#endif // 1
#define TEST1

#include "../../ProbSolvStart.h"

#if 0
#pragma GCC optimize("O1") 
#endif 

class ProbSolv
{
    string m_line;
public:
    ProbSolv()
    {
        FOR (i, 10) {
            getline(cin, m_line);
            if (m_line.length() > 2) {
                break;
            }
        }
        
        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){

        cout << Compile(m_line);


    } // _Solve()

    string Compile(const string& code) {
        string str(code);

        typedef pair<char, int> ci;
        stack<ci> St;

#ifdef TEST
        size_t strL = str.length();
#endif
        FOR (i, str.length()) {
#ifdef TEST
            P_IFNOT(str.length()==strL, str.length());
            strL = str.length();
#endif
            const char c = str[i];
            if (c == '<') {
                St.push(ci(c, i));
            }
            else if (c == '>') {
                if (!St.empty()) {
                    const int beginIdx = St.top().second + 1;
                    string sub = str.substr(beginIdx, (i - beginIdx));
                    sub = RollOut(sub);
#ifdef TEST
                    cout << sub<<endl;
#endif
                    string prev(str.substr(0, beginIdx-1));
                    string post(str.substr(i+1, str.length()-i-1));
                    str = prev + sub + post;
#ifdef TEST
                    cout <<prev<<","<<post<<endl;
                    cout << sub <<endl;
#endif
                    // while(!St.empty()) 
                    St.pop();    // St.clear()
                }
                else {
                    return "Error: not paired!";
                }
            }
            else {}
        }
        return str;
    }

    string RollOut(const string& str) {
        const auto it = begin(str);
        const auto itLast = find_if(it, end(str), [](const char c){
            return isalpha(c);
        });
        const int dist = distance(it, itLast);
        const string strNum = str.substr(0, dist);
#ifdef TEST
        cout <<strNum;
#endif
        const int num = stoi(strNum);
        const int trL = str.length() - dist;
        const string trStr = str.substr(dist, trL);
        string result("");
        FOR (i, num) {
            result += trStr;
        }

        return result;
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