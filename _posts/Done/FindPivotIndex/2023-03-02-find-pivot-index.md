---
title: 724. Find Pivot Index
layout: post
tags:
- cpp
- simple-implementation

---

<https://leetcode.com/problems/find-pivot-index>{:target="_blank"}

### Source

```cpp

    int pivotIndex(vector<int>& nums) {
        int pivot = -1;
        int right_sum = 0;
        for (const auto &n : nums) {
            right_sum += n;
        }
        int left_sum = 0;
        for (int i=0; i<nums.size(); ++i) {
            right_sum -= nums[i];
            if (right_sum == left_sum) {
                pivot = i;
                break;
            }
            left_sum += nums[i];
        }
        return pivot;
    }

```

### GitHub

- [FindPivotIndex](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/FindPivotIndex>){:target="_blank"}

![FindPivotIndex]({{ "/assets/img/posting/find_pivot_index.png" | relative_url }})
