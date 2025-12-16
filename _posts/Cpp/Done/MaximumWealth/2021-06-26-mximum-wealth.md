---
title: 1672. Richest Customer Wealth
layout: post
tags:
- cpp
- easy

---

<https://leetcode.com/problems/richest-customer-wealth/>{:target="_blank"}

### Source

```cpp

    int maximumWealth(vector<vector<int>>& accounts) {
        int maxW = 0;
        for (vi viBanks : accounts) {
            int sumW = 0;
            for (int bank_bal : viBanks) {
                sumW += bank_bal;
            }
            if (sumW > maxW) {
                maxW = sumW;
            }
        }
        return maxW;
    }

```

### GitHub

- [MaximumWealth](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/MaximumWealth>){:target="_blank"}
