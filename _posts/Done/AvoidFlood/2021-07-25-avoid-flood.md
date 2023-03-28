---
title: 1488. Avoid Flood in The City
layout: post
tags:
- cpp
- dfs-with-backtracking
- std-unordered-map
- std-set
- binary-search

---

<https://leetcode.com/problems/avoid-flood-in-the-city/>{:target="_blank"}

### Source

```cpp

    vector<int> avoidFlood(vector<int>& rains) {
        const int numDays = rains.size();
        vi viAns(numDays);
        unordered_map<int, int> hashLake_RainDay;
        set<int> setDryDays;
        FOR (day, numDays) {
            if (rains[day] == 0) {
                viAns[day] = 1; // default value
                setDryDays.emplace(day);
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
            if (setDryDays.empty()) {
                // inevitable flood
                return vi();
            }

            const int prevRainDay = itLake_RainDay->second;
            int dryDay = -1;
            auto itDryDay=begin(setDryDays);
#ifdef BINARY_SEARCH
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
                    // auto midVal = getNthElem(setDryDays, mid);
                    auto itMid = next(begin(setDryDays), mid);
                    if (*itMid >= prevRainDay) {
                        // dryDay = midVal.first;
                        dryDay = *itMid; itDryDay = itMid;
                        if (hi == mid) hi = mid-1;
                        else hi = mid;
                    }
                    else {
                        if (lo == mid) lo = mid+1;
                        else lo = mid;
                    }
                }
            }
#else
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
#endif
            if (dryDay < 0) return vi();

            // consume a day to be used to dry a lake
            setDryDays.erase(itDryDay);
            // dry the lake at the valid dry day
            viAns[dryDay] = fullOfWaterLake;
            // dry a lake
            hashLake_RainDay.erase(itLake_RainDay);

            // but, it rains again...
            hashLake_RainDay[fullOfWaterLake] = day;
        }
        return viAns;
    }

    template <typename T>
    pair<T, bool> getNthElem(set<T>& searchSet, int n) {
        pair<T, bool> result;
        if (searchSet.size() > static_cast<size_t>(n)) {
            result.first = *(next(begin(searchSet), n));
            result.second = true;
        }
        else {
            result.second = false;
        }
        return result;
    }

```

### GitHub

- [AvoidFlood](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/AvoidFlood>){:target="_blank"}

![AvoidFlood]({{ "/assets/img/posting/avoid_flood.png" | relative_url }})
