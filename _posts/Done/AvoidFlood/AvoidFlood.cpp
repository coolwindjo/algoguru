#if 1
#define TEST
#endif // 1
#if 0
#define BINARY_SEARCH
#endif // 1
#ifdef BINARY_SEARCH
#if 0
#define BINARY_SEARCH_
#endif // 1
#endif // BINARY_SEARCH

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
        unordered_map<int, int> hashLake_RainDay;
#ifdef BINARY_SEARCH_
        array<int, 98765> arrDryDays;
        int numDryDays = 0;
#else
        set<int> setDryDays;
#endif
        FOR (day, numDays) {
            if (rains[day] == 0) {
                viAns[day] = 1; // default value
#ifdef BINARY_SEARCH_
                arrDryDays[numDryDays++] = day;
#else
                setDryDays.emplace(day);
#endif
                continue;
            }

            viAns[day] = -1;
            const int fullOfWaterLake = rains[day];
            auto itLake_RainDay = hashLake_RainDay.find(fullOfWaterLake);
            if (end(hashLake_RainDay) == itLake_RainDay) {  // not found
                // first rain
                hashLake_RainDay[fullOfWaterLake] = day;
                continue;
            }

            // second rain
#ifdef BINARY_SEARCH_
            if (numDryDays == 0) {
#else
            if (setDryDays.empty()) {
#endif
                // inevitable flood
                return vi();
            }

            const int prevRainDay = itLake_RainDay->second;
            int dryDay = -1;
#ifdef BINARY_SEARCH
#ifdef BINARY_SEARCH_
            int idx = 0;
            if (arrDryDays[0] > prevRainDay) {
                // pick the first dry day
                dryDay = arrDryDays[0];
                idx = 0;
            }
            else {
                const int MAX_L = log2(numDryDays)+3;
                int hi = numDryDays-1;
                int lo = 0;
                for (int i=0; (hi>=lo) && i<MAX_L; ++i) {
                    const int mid = (hi+lo) >> 1;
                    if (arrDryDays[mid] >= prevRainDay) {
                        dryDay = arrDryDays[mid];
                        idx = mid;
                        if (hi == mid) hi = mid-1;
                        else hi = mid;
                    }
                    else {
                        if (lo == mid) lo = mid+1;
                        else lo = mid;
                    }
                }
            }

            if (dryDay < 0) return vi();

            // consume a day to be used to dry a lake
            arrDryDays[idx] = INF;
            sort(begin(arrDryDays), begin(arrDryDays)+numDryDays);
            numDryDays--;
#else
            auto itDryDay=begin(setDryDays);
            if (*itDryDay > prevRainDay) {
                // pick the first dry day
                dryDay = *itDryDay;
            }
            else {
                const int numDryDays = setDryDays.size();
                const int MAX_L = log2(numDryDays)+3;
                int hi = numDryDays-1;
                int lo = 0;
                for (int i=0; (hi>=lo) && i<MAX_L; ++i) {
                    const int mid = (hi+lo) >> 1;
                    auto itMid = next(begin(setDryDays), mid);
                    if (*itMid >= prevRainDay) {
                        dryDay = *itMid;
                        itDryDay = itMid;
                        if (hi == mid) hi = mid-1;
                        else hi = mid;
                    }
                    else {
                        if (lo == mid) lo = mid+1;
                        else lo = mid;
                    }
                }
            }

            if (dryDay < 0) return vi();

            // consume a day to be used to dry a lake
            setDryDays.erase(itDryDay);
#endif
#else
            auto itDryDay=begin(setDryDays);
            for (; itDryDay!=end(setDryDays); ++itDryDay) {
                dryDay = *itDryDay;
                if (dryDay <= prevRainDay) {
                    // invalid dry day (too early)
                    continue;
                }
                break;
            }
            if (end(setDryDays) == itDryDay) {  // not found
                // inevitable flood
                return vi();
            }

            if (dryDay < 0) return vi();

            // consume a day to be used to dry a lake
            setDryDays.erase(itDryDay);
#endif
            // dry the lake at the valid dry day
            viAns[dryDay] = fullOfWaterLake;
            // dry a lake
            hashLake_RainDay.erase(itLake_RainDay);

            // but, it rains again...
            hashLake_RainDay[fullOfWaterLake] = day;
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