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
#ifdef TEST1
        CoolTimer timer("maxProfit");
#endif
        cout << maxProfit(m_viP) <<endl;
#ifdef TEST1
        timer.Off();
        CoolTimer timerIF("maxProfitIF");
#endif
        cout << maxProfitIF(m_viP) <<endl;
#ifdef TEST1
        timerIF.Off();
        CoolTimer timerDP("maxProfitDP");
#endif
        cout << maxProfitDP(m_viP) <<endl;
#ifdef TEST1
        timerDP.Off();
#endif
    } // _Solve()

    int maxProfit(vector<int>& prices) {
		int profit = 0;
		FOR (i, prices.size()-1) {
			const int p = prices[i+1] - prices[i];
			if (p > 0) {
				profit += p;
			}
		}
		return profit;
    }

    int maxProfitIF(vector<int>& prices) {
		int profit = 0;
		int ud = -1;	// start with going down
		int pos = -1;
		FOR (i, prices.size()-1) {
			if (prices[i] < prices[i+1]) {
				if (ud < 0) {
					// go up
					pos = prices[i];
#ifdef TEST
					cout << "pos:" << pos << endl;
#endif
				}
				ud = 1;
			}
			else if (prices[i] > prices[i+1]) {
				if (ud > 0) {
					// go down
					if (pos >= 0) {
						profit += (prices[i] - pos);
#ifdef TEST
                        cout << "sell on " << prices[i] << " profit:" << prices[i] - pos << endl;
#endif
						pos = -1;
					}
				}
				ud = -1;
			}
			else {
                // ud = 0;  // No need!
			}
		}

		if (pos == -1) return profit;
		
		const int lastP = prices[prices.size()-1] - pos;
		if (lastP > 0) {
			profit += lastP;
		}
		
		return profit;
    }

    int maxProfitDP(vector<int>& prices) {
		const size_t n = prices.size();
        vvi dp(n, vi(n, 0));
		
		FOR(i, n) {
			if (i > 0) {
				if (dp[i][i] < dp[i-1][i-1]) {
					dp[i][i] = dp[i-1][i-1];
				}
			}
			FOR_INC(j, i+1, n) {
				const int p = prices[j] - prices[i];
				if (p > 0) {
					dp[i][j] = p;
					if (dp[j][j] < p + dp[i][i]) {
						dp[j][j] = p + dp[i][i];
					}
				}
			}
		}
		
#ifdef TEST
		PrintDP(dp);
#endif
		
		return dp[n-1][n-1];
    }
#ifdef TEST
	void PrintDP(const vvi& dp) {
		cout << "\t";
		FOR (j, dp[0].size()) {
			cout << setw(3) << j << ", ";
		}
		cout <<endl;
		FOR (i, dp.size()) {
			cout << i << "\t";
			FOR (j, dp[0].size()) {
				cout << setw(3) << dp[i][j] << ", ";
			}
			cout <<endl;
		}
	}
#endif
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