---
title: 11. Container With Most Water
layout: post
tags:
- cpp
- two-pointers
- tree
---

<https://leetcode.com/problems/container-with-most-water/>{:target="_blank"}

### Source

```cpp

    int maxArea(vector<int>& height) {
        int maxA = 0;
        /*/  brute force
        FOR(i, height.size()) {
            const int hI = height[i];
            FOR_INC(j, i+1, height.size()) {
                const int hJ = height[j];
                const int area = std::min(hI, hJ) * (j-i);
                if (area > maxA) {
                    maxA = area;
                }
            }
        }
        /*/
        // Answer!
        int l = 0, r = height.size()-1;
        while(l<r) {
            const int hL = height[l];
            const int hR = height[r];
            maxA = std::max(std::min(hL, hR)*(r-l), maxA);
            if (hL < hR) l++;
            else r--;
        }
        //*/
        return maxA;
    }

```

### GitHub

- [MaxAreaContainWater](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/MaxAreaContainWater>){:target="_blank"}

![MaxAreaContainWater]({{ "/assets/img/posting/max_area_contain_water.png" | relative_url }})
