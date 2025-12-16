---
title: 35. Search Insert Position
layout: post
tags:
- cpp
- simple-implementation
- binary-search

---

<https://leetcode.com/problems/search-insert-position/>{:target="_blank"}

### Source

```cpp

    int searchInsert(vector<int>& nums, int target) {
        const int MAX_L = log2(nums.size())+3;
        int ans = -1;
        int hi=nums.size()-1, lo=0;
        int mid = 0;
        for (int i=0; (i<MAX_L) && (hi>=lo); ++i) {
            mid = (lo+hi) >> 1;
            if (nums[mid] >= target) {
                ans = mid;
                if (hi == mid) hi = mid-1;
                else hi = mid;
            }
            else {
                if (lo == mid) lo = mid+1;
                else lo = mid;
            }
        }
        if (ans < 0) ans = mid + 1;

        return ans;
    }
```

### GitHub

- [SearchInsertPosition](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/SearchInsertPosition>){:target="_blank"}
