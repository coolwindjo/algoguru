---
title: 1365. How Many Numbers Are Smaller Than the Current Number
layout: post
tags:
- cpp
- easy
- sort
- avoid-nested-loop

---

<https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/>{:target="_blank"}

### Source

```cpp

    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        const size_t numNums = nums.size();
        vii viiNumIdx(numNums);
        FOR (j, numNums) {
            viiNumIdx[j] = ii(nums[j], j);
        }

        sort(begin(viiNumIdx), end(viiNumIdx));

        vi viAns(numNums);
        int prev = -1;
        int numEquals = 0;
        FOR (j, numNums) {
            const int num = viiNumIdx[j].first;
            if (prev == num) {
                numEquals++;
            }
            else {
                numEquals = 0;
            }
            viAns[viiNumIdx[j].second] = j - numEquals;
            prev = num;
        }
        return viAns;
    }

```

### GitHub

- [SmallerNumbersThanCurrent](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/SmallerNumbersThanCurrent>){:target="_blank"}

![SmallerNumbersThanCurrent]({{ "/assets/img/posting/smaller_numbers_than_current.png" | relative_url }})
