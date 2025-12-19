---
layout: post
tags:
- cpp
- simple-implementation
- two-pointers
- std-erase
- std-remove
---

# LeetCode Problem Link
<https://leetcode.com/problems/remove-element>{:target="_blank"}

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
- At begins, use auxiliary space to make the logic simple.
- but, I need the space complexity $$O(1)$$!
- use two pointers!

# Approach
<!-- Describe your approach to solving the problem. -->
- tried make a simple logic
```cpp
    int removeElement(vector<int>& nums, int val) {
        int w=0;
        int r=0;
        for (; r<nums.size(); r++) {
            if (nums[r] == val) {
                if (0==w) {
                    w=r;
                }
            }
            else {
                nums[w++] = nums[r];
            }
        }
        return w;
```

- corner case is val:3, nums: [3,3]
- not possible to use guard clause => val:3, nums: [3,3] or [3,3,3]...
- tried to use flag `if (only_v) w = 0;` => val:2, nums: [2,2,3]
- then, think another way... use flag for the first discovery of val => val:3, nums: [2]
```cpp
        bool found = false;
        for (; r<nums.size(); r++) {
            if (nums[r] == val) {
                if (!found) {
                    found = true;
                    w=r;
                }
                else {
                }
            }
            else if (found) {
                nums[w++] = nums[r];
            }
            else {
                continue;
            }
        }
        return w;
```
- ok. the final put: `if (!found) w = r;`
- the same logic happens in std::erase(std::remove()) skill called Erase-Remove Idiom
```cpp
        nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size()
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
    int removeElement(vector<int>& nums, int val) {
#if 1
        nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
#else
        int w=0;
        int r=0;
        bool found = false;
        for (; r<nums.size(); r++) {
            if (nums[r] == val) {
                if (!found) {
                    found = true;
                    w=r;
                }
                else {
                }
            }
            else if (found) {
                nums[w++] = nums[r];
            }
            else {
                continue;
            }
        }
        if (!found) w = r;
        return w;
#endif
    }
};
```

### GitHub

- ToDo: [remove-element](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/remove-element>){:target="_blank"}

![remove-element]({{ "/assets/img/posting/remove-element.png" | relative_url }})
