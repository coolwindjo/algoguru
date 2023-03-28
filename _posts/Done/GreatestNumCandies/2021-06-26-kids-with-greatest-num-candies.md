---
title: 1431. Kids With the Greatest Number of Candies
layout: post
tags:
- cpp
- easy

---

<https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/>{:target="_blank"}

### Source

```cpp

    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vb vbAns;
        int max = 0;
        for (const int kid : candies) {
            if (kid > max) {
                max = kid;
            }
        }
        for (const int kid : candies) {
            const int kid_with_ex = kid + extraCandies;
            vbAns.push_back((kid_with_ex >= max));
        }
        return vbAns;
    }

```

### GitHub

- [GreatestNumCandies](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/GreatestNumCandies>){:target="_blank"}
