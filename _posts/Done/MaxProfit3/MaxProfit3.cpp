#if 0
#define TEST
#endif // 1
#define TEST1

#include "../../ProbSolvStart.h"

#if 0
#pragma GCC optimize("O1") 
#endif 

typedef pair<int, int> ii;
typedef pair<int, ii> i_ii;
class ProbSolv
{
    vi m_viP;
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
        vstr vstrSplits = _SplitString(line, "[], \n");
        for (string s : vstrSplits) {
            m_viP.push_back(stoi(s));
        }
        
        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){
        // /*/
        cout << maxProfit(m_viP);
        /*/
        cout << maxProfitDP(m_viP);
        //*/
    } // _Solve()

    int maxProfit(vector<int>& prices) {
        const int NUM_TRS = 2;
        const int MAX = static_cast<int>(1e5);
        int position[NUM_TRS] = {MAX, MAX};
        int profit[NUM_TRS] = {0, 0};
        FOR (i, prices.size()) {
            position[0] = min(position[0], prices[i]);
            profit[0] = max(profit[0], prices[i]-position[0]);   // profit[0] = prices[i] - position[0]
            position[1] = min(position[1], (-profit[0] + prices[i]));
            profit[1] = max(profit[1], prices[i]-position[1]);   // profit[1] = prices[i] - (bought[1] - profit[0])
        }
        return profit[1];
    }
  
    int maxProfitDP(vector<int>& prices) {
		const size_t n = prices.size();
		i_ii max;
		FOR(i, n) {
			FOR_INC(j, i+1, n) {
				const int p = prices[j] - prices[i];
				if (max.first < p) {
					max.first= p;
					max.second.first = i;
					max.second.second= j;
				}
			}
		}
		
		i_ii nextToMax;
		FOR(i, n) {
			FOR_INC(j, i+1, n) {
				const int p = prices[j] - prices[i];
				if (nextToMax.first < p) {
					if (max.second.first == i) continue;
					if (max.second.second == j) continue;
					nextToMax.first= p;
					nextToMax.second.first = i;
					nextToMax.second.second= j;
				}
			}
		}
#ifdef TEST
		cout << max.first << ":" << max.second.first << "," << max.second.second <<endl;
		cout << nextToMax.first << ":" << nextToMax.second.first << "," << nextToMax.second.second <<endl;
#endif
		
		return max.first + nextToMax.first;
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
    cin >> numTCs; cin.ignore();
    FOR (tc, numTCs) {
        cout << "#" << tc+1 <<" ";
        ProbSolv ps;
        cout << endl;
    }
    return 0;
}