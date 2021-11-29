---
title: Running Sum of 1d Array
layout: post
tags:
- cpp
- easy

---

<https://leetcode.com/problems/running-sum-of-1d-array>{:target="_blank"}

### Source

```cpp

    vector<int> runningSum(vector<int>& nums) {
        vector<int> viAns;
        int sum = 0;
        for(int i=0; i<nums.size(); ++i){
            sum += nums[i];
            viAns.push_back(sum);
        }
        return viAns;
    }

```

### GitHub

- [RunningSumArray](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/RunningSumArray>){:target="_blank"}
