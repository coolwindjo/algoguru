---
layout: post
tags:
- cpp
- simple-implementation
- binary-search-tree

---

<https://leetcode.com/problems/search-insert-position/>{:target="_blank"}

### Source

```cpp

   int searchInsert(vector<int>& nums, int target) {
        constexpr int MAX_LOOP = 15;
        int hi=nums.size()-1, lo=0;
        int mid = 0;
        int ans = -1;
        for (int i=0; (i<MAX_LOOP) && (hi>=lo); ++i) {
            mid = (lo+hi) >> 1;
            if (nums[mid] >= target) {
                hi = mid;
                ans = hi;
            }
            else {
                if (mid == lo) lo = mid+1;
                else lo = mid;
            }
        }
        if (ans < 0) ans = mid + 1;

        return ans;
    }

```

### GitHub

- [SearchInsertPosition](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/SearchInsertPosition>){:target="_blank"}
