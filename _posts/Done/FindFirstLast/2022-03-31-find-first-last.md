---
title: 34. Find First and Last Position of Element in Sorted Array
layout: post
tags:
- cpp
- binary-search

---

<https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/>{:target="_blank"}

### Source

```cpp

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        const int MAX_L = log2(nums.size())+3;

        int hi=nums.size()-1;
        int lo=0;
        int min = -1;
        for (int i=0; hi>=lo && i<MAX_L; ++i) {
            // if (!W_IFNOT(hi > -1)) break;
            // if (!W_IFNOT(lo > -1)) break;
            updateHiLoForMin(nums, target, (lo+hi)>>1, hi, lo, min);
        }

        nums.push_back(INF);
        hi=nums.size()-1;
        lo=max(0, min);
        int max = -1;
        for (int i=0; hi>=lo && i<MAX_L; ++i) {
            // if (!W_IFNOT(hi >= 0)) break;
            // if (!W_IFNOT(lo >= 0)) break;
            updateHiLoForMax(nums, target, (lo+hi)>>1, hi, lo, max);
        }

        vi viAns;
        viAns.push_back(min);
        viAns.push_back(max);

        return viAns;
    }

    void updateHiLoForMin(const vi& nums, const int target, const int mid, int &hi, int &lo, int &min) {
        // if (!W_IFNOT(mid <= hi)) return;
        // if (!W_IFNOT(mid >= lo)) return;
        if (nums[mid] == target) {
            min = hi = mid;
        }
        else if (nums[mid] > target) {
            if (hi == mid) hi = mid-1;
            else hi = mid;
        }
        else {
            if (lo == mid) lo = mid+1;
            else lo = mid;
        }
    }

    void updateHiLoForMax(const vi& nums, const int target, const int mid, int &hi, int &lo, int &max) {
        // if (!W_IFNOT(mid <= hi)) return;
        // if (!W_IFNOT(mid >= lo)) return;
        if (nums[mid] == target) {
            max = lo = mid;
        }
        else if (nums[mid] < target) {
            if (lo == mid) lo = mid+1;
            else lo = mid;
        }
        else {
            if (hi == mid) hi = mid-1;
            else hi = mid;
        }
    }

```

### GitHub

- [FindFirstLast](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/FindFirstLast>){:target="_blank"}
