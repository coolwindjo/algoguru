---
title: 338. Counting Bits
layout: post
tags:
- cpp
- easy
- radix-conversion

---

<https://leetcode.com/problems/counting-bits/>{:target="_blank"}

### Source

```cpp

    vector<int> countBits(int n) {
        vi viAns;
        FOR (i, n+1) {
            const string bin = toBin(i);
            int sum = 0;
            FOR (j, bin.length()) {
                if ('1' == bin[j]) {
                    sum++;
                }
            }
            viAns.push_back(sum);
        }
        return viAns;
    }

    string toBin(const int n) {
        if (n == 1) return "1";
        if (n == 0) return "0";
        return toBin(n/2) + to_string(n%2);
    }

```

### GitHub

- [CountBits](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/CountBits>){:target="_blank"}
