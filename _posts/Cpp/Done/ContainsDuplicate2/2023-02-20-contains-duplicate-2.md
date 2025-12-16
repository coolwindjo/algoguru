---
title: 219. Contains Duplicate II
layout: post
tags:
- cpp
- std-unordered-map

---

<https://leetcode.com/problems/contains-duplicate-ii/>{:target="_blank"}

### Source

```cpp

    bool containsNearbyDuplicate(const vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int i=0; i<nums.size(); ++i) {
            if (++hash[nums[i]] > 1) return true;
            if (i>=k) hash[nums[i-k]] = 0;
        }
        return false;
    }

```

### GitHub

- [ContainsDuplicate2](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/ContainsDuplicate2>){:target="_blank"}

![ContainsDuplicate2]({{ "/assets/img/posting/contains_duplicate_2.png" | relative_url }})
