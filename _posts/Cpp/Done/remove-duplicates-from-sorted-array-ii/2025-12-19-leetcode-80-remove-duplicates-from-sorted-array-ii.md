---
layout: post
tags:
- cpp
- simple-implementation
- two-pointers
---

# LeetCode Problem Link
<https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii>{:target="_blank"}

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
- the same start with [Leetcode 26 Remove Duplicates From Sorted Array]({{ site.baseurl }}{% link _posts/Cpp/Done/remove-duplicates-from-sorted-array/2025-12-19-leetcode-26-remove-duplicates-from-sorted-array.md %}){:target="_blank"}
- the first two elements are always unique.  => corner case: [1]
```cpp
        int r=2;
        int w=2;
        for (;r<size(nums); ++r) {
            if (nums[r] > nums[r-2]) {
                nums[w++] = nums[r];
            }
        }
        return w
```
- then just use guard clause => corner case: [1,1,1,2,2,3]
```cpp
        if (nums.size() <= 2) return nums.size();
```
- then store the previous value of the r-2 to be compared with the value at the read pointer => too ugly and hard to read
```cpp
        int v = nums[0];
        for (;r<size(nums); ++r) {
            if (nums[r] > v) {
                v = nums[r-1];
                nums[w++] = nums[r];
            }
            else {
                v = nums[r-1];
            }
        }
```

# Approach
<!-- Describe your approach to solving the problem. -->
- think about the another value that not change until current visit finished
- maybe we can check previous value at the w-2.
```cpp
        int r=2;
        int w=2;
        for (;r<size(nums); ++r) {
            if (nums[r] > nums[w-2]) {  // r-2 => w-2
                nums[w++] = nums[r];
            }
        }
        return w
```

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(n)$$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(1)$$

# Code
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int r=2;
        int w=2;
        for (; r < nums.size(); r++) {
            if (nums[r] != nums[w - 2]) {
                nums[w] = nums[r];
                w++;
            }
        }
        return w;
    }
};
```

### GitHub

- ToDo: [remove-duplicates-from-sorted-array-ii](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/remove-duplicates-from-sorted-array-ii>){:target="_blank"}

![remove-duplicates-from-sorted-array-ii]({{ "/assets/img/posting/remove-duplicates-from-sorted-array-ii.png" | relative_url }})
