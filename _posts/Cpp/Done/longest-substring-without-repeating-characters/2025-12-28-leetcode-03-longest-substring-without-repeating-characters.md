---
layout: post
tags:
- cpp
- two-pointers
- std-unordered-set
---

# LeetCode Problem Link
<https://leetcode.com/problems/longest-substring-without-repeating-characters>{:target="_blank"}

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
- use two-pointers for implementing a sliding window and a hash table for checking previous occurrences
```cpp
        std::unordered_set<char> hash;
        for (size_t r=0; r<n; ++r) {
            auto it = hash.find(s[r]);
            if (it == end(hash)) {
                hash.emplace(s[r]);
                max_len = std::max(max_len, (r+1)-l);
            }
            else {
                while (l<=r && s[l] != s[r]) {
                    hash.erase(s[l++]);
                }
                ++l;
            }
        }
```

# Approach
<!-- Describe your approach to solving the problem. -->
- unordered_set is too expensive for processing 'char' type => use 256 sized array

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(n)$$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(1)$$

# Code
```cpp
    int lengthOfLongestSubstring(string s) {
        const size_t n = s.length();
        size_t max_len = 0;
        std::array<int32_t, 256> pos;
        pos.fill(-1);
        size_t l=0;
        for (size_t r=0; r<n; ++r) {
            const uint8_t s_r = static_cast<uint8_t>(s[r]);
            if (pos[s_r] < static_cast<int32_t>(l)) {
                max_len = std::max(max_len, (r+1)-l);
            }
            else {  // if it exists
                l = std::max(l, static_cast<size_t>(pos[s_r])+1);
            }
            pos[s_r] = static_cast<int32_t>(r);
        }
        return max_len;
    }
```

### GitHub

- ToDo: [longest-substring-without-repeating-characters](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/longest-substring-without-repeating-characters>){:target="_blank"}

![longest-substring-without-repeating-characters]({{ "/assets/img/posting/longest-substring-without-repeating-characters.png" | relative_url }})
