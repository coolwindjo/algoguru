---
title: Max Increase to Keep City Skyline
layout: post
tags:
- cpp
- implementation

---

<https://leetcode.com/problems/max-increase-to-keep-city-skyline/>{:target="_blank"}

### Source

```cpp

    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        const int n = grid.size();
        vi viRowMax(n, 0);
        vi viColMax(n, 0);
        FOR (r, n) {
            FOR (c, n) {
                const int val = grid[r][c];
                if (val > viRowMax[r]) {
                    viRowMax[r] = val;
                }
                if (val > viColMax[c]) {
                    viColMax[c] = val;
                }
            }
        }
        
        int sum = 0;
        FOR (r, n) {
            FOR (c, n) {
                const int limit = min(viRowMax[r], viColMax[c]);
                if (limit > grid[r][c]) {
                    sum += limit - grid[r][c];
                }
            }
        }
        return sum;
    }

```

### GitHub

- [MaxIncreaseKeepingSkyline](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/MaxIncreaseKeepingSkyline>){:target="_blank"}

![MaxIncreaseKeepingSkyline]({{ "/assets/img/posting/max_increase_keeping_skyline.png" | relative_url }})
