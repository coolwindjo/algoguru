---
title: 1945. Sum of Digits of String After Convert
layout: post
tags:
- cpp
- easy

---

<https://leetcode.com/problems/sum-of-digits-of-string-after-convert/>{:target="_blank"}

### Source

```cpp

    int getLucky(string s, int k) {
        string strNums;
        FOR (i, s.length()) {
            const int n = s[i] - 'a' + 1;
            strNums += to_string(n);
        }
        int ans = 0;
        FOR (i, k) {
            int sum = 0;
            FOR (j, strNums.length()) {
                sum += strNums[j] - '0';
            }
            ans = sum;
            strNums = to_string(ans);
        }

        return ans;
    }

```

### GitHub

- [GetLucky](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/GetLucky>){:target="_blank"}
