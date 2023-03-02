#if 1
#define TEST
#endif // 1

#include "../../ProbSolvStart.h"

#if 0
#pragma GCC optimize("O2")
#endif

class ProbSolv
{
    vi m_viRains;
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
        for (string strNum : vstrSplits) {
            m_viRains.push_back(stoi(strNum));
        }

        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){
        vi viAns = avoidFlood(m_viRains);
        cout << "[";
        for (int ans : viAns) {
            cout << ans << ",";
        }
        cout << "]";
    } // _Solve()

    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> hashLake;
        vi viAns;
        if (BT_DFS(viAns, hashLake, 0, rains, 0) <= 0) {
            return vi();
        }
        return viAns;
    }

    int BT_DFS(vi& viAns, unordered_map<int, int> hashLake, const int dryingLake, const vi& rains, const int day) {
        if (dryingLake > 0) {
            // post deletion
            viAns.push_back(dryingLake);
            auto it = hashLake.find(dryingLake);
            if (end(hashLake) != it) {
                hashLake.erase(it);
            }
        }

        if (day >= rains.size()) {
            // Normal finish
            return 1;
        }

        const int rainingLake = rains[day];

        if (rainingLake == 0) {
            for (auto it=begin(hashLake); it!=end(hashLake); ++it) {
                it->second++;
            }
            for (auto it=begin(hashLake); it!=end(hashLake); ++it) {
                const int dryingLake = it->first;
                int ret = 0;
                if ((ret = BT_DFS(viAns, hashLake, dryingLake, rains, day+1)) != 0) {
                    return ret;
                }
                // Back-tracking
                viAns.pop_back();
            }
            viAns.push_back(1);
        }
        else {
            int isFlooded = 0;
            if ((isFlooded = isFlooding(hashLake, rainingLake)) > 0) {
                return 0;
            }
            else if (isFlooded < 0) {
                // Inevitable flood!
                return -1;
            }
            viAns.push_back(-1);
        }

        int ret = 0;
        if ((ret = BT_DFS(viAns, hashLake, 0, rains, day+1)) != 0) {
            return ret;
        }
        // Back-tracking
        viAns.pop_back();
        return 0;
    }

    int isFlooding(unordered_map<int, int>& hashLake, const int rainingLake) {
        auto it = hashLake.find(rainingLake);
        if (end(hashLake) != it) {
            if (it->second == 0) {
                return -1;
            }
            // second rain
            return 1;
        }
        // first rain
        hashLake.emplace(make_pair(rainingLake, 0));
        return 0;
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
