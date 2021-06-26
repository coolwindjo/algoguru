---
title: Partitioning Into Minimum Number Of Deci-Binary Numbers
layout: post
tags:
- cpp
- implementation

---

<https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/>

### Source

```cpp

    int minPartitions(string n) {
        int maxN = 0;
        FOR (i, n.length()) {
            const int num = n[i] - '0';
            if (num > maxN) {
                maxN = num;
            }
        }
        return maxN;
    }

```

### GitHub

- [MinPartitions](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/MinPartitions>){:target="_blank"}
