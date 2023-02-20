---
title: 409. Longest Palindrome
layout: post
tags:
- cpp
- simple-implementation
- std-unordered-map

---

<https://leetcode.com/problems/longest-palindrome/>{:target="_blank"}

### Source

```cpp

    int longestPalindrome(string s) {
        unordered_map<char, int> hashMap;
        for (char c : s) {
            hashMap[c]++;
        }
        int oneside = 0;
        int addOne = 0;
        FOR(i, hashMap.size()) {
            const char c = 'a' + i;
            const int num = hashMap[c];
            const int half = static_cast<int>(num/2);
            if (half > 0) oneside += half;
            if (num%2 > 0) addOne = 1;
        }
        return (2*oneside + addOne);
    }


```

### GitHub

- [LongestPalindrome](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/LongestPalindrome>){:target="_blank"}

![LongestPalindrome]({{ "/assets/img/posting/longest_palindrome.png" | relative_url }})
