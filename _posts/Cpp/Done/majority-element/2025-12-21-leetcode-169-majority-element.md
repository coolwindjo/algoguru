---
layout: post
tags:
- cpp
- simple-implementation
- std-unordered-map
- boyer-moore-voting
---

# LeetCode Problem Link
<https://leetcode.com/problems/majority-element>{:target="_blank"}

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
- approach with simple solution: counting map
```cpp
        std::unordered_map<int, int> hashmap;
        for (int i=0; i<size(nums); ++i) {
            hashmap[nums[i]]++;
        }
        int max = 0;
        int major = -1;
        for (auto it=begin(hashmap);it!=end(hashmap);it++) {
            if (it->second > max) {
                max = it->second;
                major = it->first;
            }
        }
        return major;
```
- **Space Complexity $$O(N)$$**

# Approach
<!-- Describe your approach to solving the problem. -->
- come up with an idea that kill both allies and enemies then we can start, as if, from the beginning!
- use only two additional variables' space, candidate and count (which can be decreased)

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
    int majorityElement(vector<int>& nums) {
        int cand = 0;
        int cnt = 0;
        for (size_t i=0; i<size(nums); ++i) {
            if (cnt == 0) { cand = nums[i]; ++ cnt; }
            else if (cand == nums[i]) { ++cnt; }
            else { --cnt; }
        }
        return cand;
    }
};
```

### GitHub

- ToDo: [majority-element](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/majority-element>){:target="_blank"}

![majority-element]({{ "/assets/img/posting/majority-element.png" | relative_url }})
