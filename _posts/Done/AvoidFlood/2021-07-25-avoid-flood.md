---
title: Avoid Flood in The City
layout: post
tags:
- cpp
- dfs-with-backtracking
- std-unordered-map
- std-set
- binary-search-tree

---

<https://leetcode.com/problems/avoid-flood-in-the-city/>{:target="_blank"}

### Source

```cpp

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
                    // TODO: use Binary Search Tree to find the valid dry day
                    for (; itDryDay!=end(setDryDays); ++itDryDay) {
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

```

### GitHub

- [AvoidFlood](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/AvoidFlood>){:target="_blank"}

![AvoidFlood]({{ "/assets/img/posting/avoid_flood.png" | relative_url }})
