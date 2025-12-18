---
title: 392. Is Subsequence
layout: post
tags:
- cpp
- simple-implementation
- string-manipulation

---

<https://leetcode.com/problems/is-subsequence>{:target="_blank"}

### Source

```cpp

    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true;
        bool isSubsq = false;
        int i = 0;
        for (const auto &c : t) {
            if (c == s[i]) {
                ++i;
                if (s.size() == i) {
                    isSubsq = true;
                    break;
                } else
                    continue;
            }
        }
        return isSubsq;
    }

```

### GitHub

- [IsSubsequence](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/IsSubsequence>){:target="_blank"}

![IsSubsequence]({{ "/assets/img/posting/IsSubsequence.png" | relative_url }})
