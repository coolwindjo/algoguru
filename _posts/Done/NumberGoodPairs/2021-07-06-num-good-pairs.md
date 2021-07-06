---
title: Number of Good Pairs
layout: post
tags:
- cpp
- implementation
- combination

---

<https://leetcode.com/problems/number-of-good-pairs/>

### Source

```cpp

    int numIdenticalPairs(vector<int>& nums) {
        const int N = nums.size();
        int cnt = 0;
        FOR (i, N) {
            const int selected = nums[i];
            FOR_INC (j, i+1, N) {
                if (selected == nums[j]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }

```

### GitHub

- [NumberGoodPairs](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/NumberGoodPairs>){:target="_blank"}

![NumberGoodPairs]({{ "/assets/img/posting/number_of_good_pairs.png" | relative_url }})
