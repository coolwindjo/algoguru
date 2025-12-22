---
layout: post
tags:
- cpp
- simple-implementation
- string-manipulation
- std-unordered-map

---

# LeetCode Problem Link
<https://leetcode.com/problems/ransom-note>{:target="_blank"}

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
- freq map required -> unordered_map<char, int>
```cpp
        std::unordered_map<char, int> freq;
        for (auto ch : magazine) {
            freq[ch]++;
        }
        for (auto ch : ransomNote) {
            if(freq[ch]--==0) { return false; }
        }
```
- Side Effect: `std::unordered_map`'s `operator[]` creates a new entry if the key doesn't exist, initializes it to zero, and then returns it.
- Simply trying to "check if it exists" will result in unnecessary heap allocation and insertion operations. This is a significant overhead.
- Fix: You should use `find()` or `count()`. However, the best solution here is to avoid using a map altogether.

# Approach
<!-- Describe your approach to solving the problem. -->
- lower case only so we can also use 'a' for char2int

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
array: $$O(n)$$, unordered_map: $$O(nk)$$ k<26

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
array: $$O(1)$$, unordered_map: $$O(k)$$  k<26

# Code
```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length()) return false;
#if 1
        std::array<int, 26> freq{0,};
        for (auto ch : magazine) {
            freq[ch-'a']++;
        }
        for (auto ch : ransomNote) {
            if (!freq[ch-'a']--) return false;
        }
#else
        std::unordered_map<char, int> hashmap;
        for (auto ch : magazine) {
            hashmap[ch]++;
        }
        for (auto ch : ransomNote) {
            auto it = freq.find(ch);
            if(it != end(freq)) {
                it->second--;
                if (it->second == 0) {
                    freq.erase(it);
                }
            }
            else {
                return false;
            }
        }
#endif
        return true;
    }
};
```

### GitHub

- ToDo: [ransom-note](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/ransom-note>){:target="_blank"}
