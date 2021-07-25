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
        const int numDays = rains.size();
        vi viAns(numDays);
        unordered_map<int, int> hashLake;
        set<int> setDryDays;
        FOR (day, numDays) {
            if (rains[day] == 0) {
                viAns[day] = 1; // default value
                setDryDays.emplace(day);
            }
            else {
                viAns[day] = -1;
                const int rainingLake = rains[day];
                auto it = hashLake.find(rainingLake);
                if (end(hashLake) != it) {
                    // second rain
                    if (setDryDays.empty()) {
                        // inevitable flood
                        return vi();
                    }
                    const int firstRainDay = it->second;
                    auto itDryDay=begin(setDryDays);
                    for (;itDryDay!=end(setDryDays);++itDryDay) {
                        const int dryDay = *itDryDay;
                        if (dryDay <= firstRainDay) {
                            // invalid dry day (too early)
                            continue;
                        }
                        // dry the lake at the valid dry day
                        viAns[dryDay] = rainingLake;
                        setDryDays.erase(itDryDay);
                        hashLake.erase(it);

                        // but, it rains again...
                        hashLake.emplace(make_pair(rainingLake, day));
                        break;
                    }
                    if (end(setDryDays) == itDryDay) {
                        // inevitable flood
                        return vi();
                    }
                }
                else {
                    // first rain
                    hashLake.emplace(make_pair(rainingLake, day));
                }
            }
        }
        return viAns;
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