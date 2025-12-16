---
title: 128. Longest Consecutive Sequence
layout: post
tags:
- cpp
- simple-implementation
- medium
- sort

---

<https://leetcode.com/problems/longest-consecutive-sequence>{:target="_blank"}

### Source

```cpp

    int longestConsecutive(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int prev = -INF;
        int max = 0;
        int cnt = 0;
#ifdef TEST
        for (const int num : nums) {cout << num <<",";}
#endif
        for (const int num : nums) {
            P_IFNOT(num >= prev, num);
            if (num == prev+1) {
                if (cnt == 0) cnt = 1;
                cnt++;
            }
            else if (num == prev) {
                // Do nothing
            }
            else {
                if (cnt > max) {
                    max = cnt;
                }
                cnt = 1;
            }
            prev = num;
        }
        if (cnt > max) {
            max = cnt;
        }
        return max;
    }

```

### GitHub

- [LongestConsecutive](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/LongestConsecutive>){:target="_blank"}
