---
title: 205. Isomorphic Strings
layout: post
tags:
- cpp
- simple-implementation
- string-manipulation
- string-replace
- string-find
- std-unordered-map

---

<https://leetcode.com/problems/isomorphic-strings>{:target="_blank"}

### Source

```cpp

    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hashST;
        unordered_map<char, char> hashTS;
        bool isIsmp = true;
        for (int i = 0; i < s.size(); ++i) {
            const char c1 = s[i];
            const char c2 = t[i];
            if ((hashST.find(c1) == std::end(hashST)) && (hashTS.find(c2) == std::end(hashTS))) {
                hashST[c1] = c2;
                hashTS[c2] = c1;
            } else if (hashST[c1] == c2) {
                // Do nothing
            } else {
                isIsmp = false;
                break;
            }
        }
        return isIsmp;
    }

```

### GitHub

- [IsomorphicStrings](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/IsomorphicStrings>){:target="_blank"}

![IsomorphicStrings]({{ "/assets/img/posting/IsomorphicStrings.png" | relative_url }})
