---
layout: post
tags:
- cpp
- simple-implementation
- two-pointers
- std-unordered-set
- std-unique
- std-erase
---

# LeetCode Problem Link
<https://leetcode.com/problems/remove-duplicates-from-sorted-array>{:target="_blank"}

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
- tried with stdlib
```cpp
        nums.erase(std::unique(begin(nums), end(nums)), end(nums));
        return nums.size()
```
- then start from the logic remove-element (Erase Remove Idiom) [Leetcode 27 Remove Element]({{ site.baseurl }}{% link _posts/Cpp/Done/remove-element/2025-12-19-leetcode-27-remove-element.md %}){:target="_blank"}
```cpp
        int w=0;
        for (int r=0;r<nums.size(); ++r) {
            if (nums[r] != 0) { // if an elem is not '0'(valid), then use w pointer and increase!
                nums[w++] = nums[r];
            }
        }
```
- do I need to use visit buffer? => no, this is non-deceasing series
```cpp
        std::unordered_set<int> vstd;
        for (;r<nums.size(); ++r) {
            if (vstd.find(nums[r]) == end(vstd)) {
                nums[w++] = nums[r];
                vstd.emplace(nums[r]);
            }
        }
```

# Approach
<!-- Describe your approach to solving the problem. -->
- then just remove visit buffer and use previous value comparison => nums can have minus values, so I can't use previous value
- then use previous index => ugly
```cpp
        int r=0;
        int w=0;
        int prev = -1;
        for (;r<nums.size(); ++r) {
            if (prev < 0) {
                nums[w++] = nums[r];
            }
            if (prev>=0 && (nums[prev] != nums[r])) {
                nums[w++] = nums[r];
            }
            prev = r;
        }
        return w
```
- come up with an idea that the first element is always unique!
- use latter pointer to fetch the unchanged value! => not `[r-1]`, but `[w-1]`


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
#if 1
        nums.erase(std::unique(begin(nums), end(nums)), end(nums));
        return nums.size();
#else
        int r=1;
        int w=1;
        for (;r<nums.size(); ++r) {
            if (nums[w-1] < nums[r]) {
                nums[w++] = nums[r];
            }
        }
        return w;
#endif
    }
}

```

### GitHub

- ToDo: [remove-duplicates-from-sorted-array](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/remove-duplicates-from-sorted-array>){:target="_blank"}