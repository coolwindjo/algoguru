---
layout: post
tags:
- cpp
- simple-implementation
- string-manipulation
---

# LeetCode Problem Link
<https://leetcode.com/problems/isomorphic-strings>{:target="_blank"}

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
- use a look up table to check the pair is correct

# Approach
<!-- Describe your approach to solving the problem. -->
- use array instead of unordered_map
- extended ascii code can be defined in 256 array
- find a invalid initial value => -1 OK
- array can be filled with `fill()`
- character functioned as index and it needs to be unsigned


# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(1)$$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(1)$$

# Code
```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        std::array<int16_t, 256> s2t;  // 000:'\0', 255: ''
        std::array<int16_t, 256> t2s;  // 000:'\0', 255: ''
        s2t.fill(-1);
        t2s.fill(-1);

        for (size_t i=0; i<s.length(); ++i){
            const uint8_t s_ch = static_cast<uint8_t>(s[i]);
            const uint8_t t_ch = static_cast<uint8_t>(t[i]);
            if (s2t[s_ch]==-1 && t2s[t_ch]==-1) {
                s2t[s_ch] = t_ch;
                t2s[t_ch] = s_ch;
            }
            else if (s2t[s_ch]!=t_ch || t2s[t_ch]!=s_ch) {
                return false;
            }
        }
        return true;
    }
};
```

### GitHub

- ToDo: [isomorphic-strings](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/isomorphic-strings>){:target="_blank"}
