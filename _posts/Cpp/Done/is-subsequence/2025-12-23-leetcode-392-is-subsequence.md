---
layout: post
tags:
- cpp
- two-pointers
- std-upper_bound
---

# LeetCode Problem Link
<https://leetcode.com/problems/is-subsequence>{:target="_blank"}

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
- looks similar to the [Leetcode 383 Ransom Note]({{ site.baseurl }}{% link _posts/Cpp/Done/ransom-note/2025-12-22-leetcode-383-ransom-note.md %}){:target="_blank"} but it is different because it also care about the order of subsequence => s="abc", t="axcba": false!
```cpp
        std::array<int, 26> freq = {0};
        for (auto c : t) {
            freq[c-'a']++;
        }
        for (auto c : s) {
            if (--freq[c-'a']<0) {
                return false;
            }
        }
        return true;
```
- so is it a two-pointer? no, it has no symmetrical features at all. (and actually it requires four pointers)
```cpp
        int head = 0;
        int tail = t.length()-1;
        int hd = 0;
        int tl = s.length()-1;
        while(hd<=tl && head<tail) {
            if (t[head] != s[hd]) {
                ++head;
                continue;
            }
            else if (t[tail] != s[tl]) {
                --tail;
                continue;
            }
            ++hd;
            --tl;
            ++head;
            --tail;
        }
        if (hd<tl) return false;
        if (hd==tl && s[hd]!=t[head]) return false;
        return true;
```

# Approach
<!-- Describe your approach to solving the problem. -->
- normal iteration is sufficient and much simpler!
```cpp
        int s_i = 0;
        for (int i=0;s_i<s.length() && i<t.length();++i) {
            if (s[s_i] != t[i]) {
                continue;
            }
            ++s_i;
        }
        if (s_i != s.length()) return false;
        return true;
```
- if the number of s strings is huge, then store the indices of the same letter and use them to move the pointer to the next position

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(n)$$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(1)$$

# Code
```cpp
#if 0
    bool isSubsequence(string s, string t) {
        std::vector<int> pos[26];
        for (int i=0;i<t.length();++i) {
            pos[t[i]-'a'].push_back(i);
        }
        int s_i = -1;
        for (auto c : s) {
            const auto& indices = pos[c-'a'];   // {0, 3, ...}
            auto it = std::upper_bound(begin(indices), end(indices), s_i);
            if (it == end(indices)) {
                return false;
            }
            s_i = *it;
        }
        return true;
    }
#endif
#if 1
    bool isSubsequence(string s, string t) {
        int s_i = 0;
        for (int i=0;s_i<s.length() && i<t.length();++i) {
            if (s[s_i] != t[i]) {
                continue;
            }
            ++s_i;
        }
        if (s_i != s.length()) return false;
        return true;
    }
#endif
```

### GitHub

- ToDo: [is-subsequence](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/is-subsequence>){:target="_blank"}

![is-subsequence]({{ "/assets/img/posting/is-subsequence.png" | relative_url }})
