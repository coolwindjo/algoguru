---
title: 125. Valid Palindrome
layout: post
tags:
- cpp
- simple-implementation
- string-manipulation

---

<https://leetcode.com/problems/valid-palindrome>{:target="_blank"}

### Source

```cpp

    bool isPalindrome(string s) {
        string p;
        for (auto c : s) {
            if (c >='A' && c <= 'Z') p.push_back(c-'A'+'a');
            else if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) p.push_back(c);
            else continue;
        }
        const int p_size = p.size();
        const int loop = static_cast<int>(p_size*0.5);
        for (int i=0; i<loop; ++i) {
            if (p[i] == p[p_size-1-i]) continue;
            else return false;
        }
        return true;
    }

```

### GitHub

- [ValidPalindrome](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/ValidPalindrome>){:target="_blank"}
