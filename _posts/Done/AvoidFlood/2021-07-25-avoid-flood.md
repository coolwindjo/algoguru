---
title: Avoid Flood in The City
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
#ifdef BINARY_SEARCH
        array<int, 98765> arrDryDays;
        int numDryDays = 0;
#else
        set<int> setDryDays;
#endif
        FOR (day, numDays) {
            if (rains[day] == 0) {
                viAns[day] = 1; // default value
#ifdef BINARY_SEARCH
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
#ifdef BINARY_SEARCH
            if (numDryDays == 0) {
#else
            if (setDryDays.empty()) {
#endif
                // inevitable flood
                return vi();
            }

            const int prevRainDay = itLake_RainDay->second;
#ifdef BINARY_SEARCH
            int dryDay = -1;
            int idx = 0;
            if (arrDryDays[0] > prevRainDay) {
                // invalid dry day (too early)
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
                if (dryDay < 0)
                    return vi();
            }

            // dry the lake at the valid dry day
            viAns[dryDay] = fullOfWaterLake;

            // consume a day to be used to dry a lake **it takes too much time
            arrDryDays[idx] = INF;
            sort(begin(arrDryDays), begin(arrDryDays)+numDryDays);
            numDryDays--;

            // dry a lake
            hashLake_RainDay.erase(itLake_RainDay);

            // but, it rains again...
            hashLake_RainDay[fullOfWaterLake] = day;

#else
            auto itDryDay=begin(setDryDays);
            for (; itDryDay!=end(setDryDays); ++itDryDay) {
                const int dryDay = *itDryDay;
                if (dryDay <= prevRainDay) {
                    // invalid dry day (too early)
                    continue;
                }

                // dry the lake at the valid dry day
                viAns[dryDay] = fullOfWaterLake;
                // consume a day to be used to dry a lake
                setDryDays.erase(itDryDay);
                // dry a lake
                hashLake_RainDay.erase(itLake_RainDay);

                // but, it rains again...
                hashLake_RainDay[fullOfWaterLake] = day;
                break;
            }

            if (end(setDryDays) == itDryDay) {  // not found
                // inevitable flood
                return vi();
            }
#endif
        }
        return viAns;
    }

```

### GitHub

- [AvoidFlood](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/AvoidFlood>){:target="_blank"}

![AvoidFlood]({{ "/assets/img/posting/avoid_flood.png" | relative_url }})
