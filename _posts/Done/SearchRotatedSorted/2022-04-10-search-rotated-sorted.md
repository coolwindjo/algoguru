---
title: 33. Search in Rotated Sorted Array
layout: post
tags:
- cpp
- binary-search

---

<https://leetcode.com/problems/search-in-rotated-sorted-array/>{:target="_blank"}

### Source

```cpp

    int search(vector<int>& nums, int target) {
        const int MAX_L = log2(nums.size()) + 3;
        int hi=nums.size()-1;
        int lo=0;
        // /*/
        int ans=-1;
        for (int i=0; hi>=lo && i<MAX_L; ++i) {
            const int mid = (hi+lo) >> 1;
            if (nums[mid] == target) {
                ans = mid;
                break;
            }

            if (nums[mid] >= nums[lo]) {
                if (nums[mid] > target && target >= nums[lo]) {
                    hi = mid-1;
                }
                else {
                    lo = mid+1;
                }

            }
            else {
                if (nums[hi] >= target && target > nums[mid]) {
                    lo = mid+1;
                }
                else {
                    hi = mid-1;
                }
            }
        }
        /*/
        bool beforePivot =  (nums[lo]>target) ? false : true;
        if (nums[hi] < nums[lo]) {
            for (int i=0; hi>lo && i<MAX_L; ++i) {
                const int mid = (hi+lo) >> 1;

                if (nums[mid] > nums[mid+1]) {
                    if (beforePivot) hi = mid;
                    else lo = mid+1;
                    break;
                }
                else if (nums[mid] >= nums[lo]) {
                    lo = mid+1;
                }
                else {
                    hi = mid-1;
                }
            }
            if (beforePivot) lo = 0;
            else hi = nums.size()-1;
        }

        int ans = -1;
        for (int i=0; hi>=lo && i<MAX_L; ++i) {
            const int mid = (hi+lo) >> 1;
            if (nums[mid] == target) {
                ans = mid;
                break;
            }
            else if (nums[mid] > target) {
                //if (hi == mid)
                    hi = mid-1;
                //else hi = mid;  // nums[mid] == target 이 따로 존재할 경우 필요없음
            }
            else {
                //if (lo == mid)
                    lo = mid+1;
                //else lo = mid;  // nums[mid] == target 이 따로 존재할 경우 필요없음
            }
        }
        //*/

        return ans;
    }

```

### GitHub

- [SearchRotatedSorted](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/SearchRotatedSorted>){:target="_blank"}

![SearchRotatedSorted]({{ "/assets/img/posting/rotated_sorted.png" | relative_url }})
