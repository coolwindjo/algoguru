---
title: 283. Move Zeroes
layout: post
tags:
- cpp
- simple-implementation

---

<https://leetcode.com/problems/move-zeroes/>{:target="_blank"}

### Source

```cpp

    void moveZeroes(vector<int>& nums) {
        FOR(i, nums.size()) {
            const int I = nums[i];
            if (I != 0) continue;
            // I is zero
            FOR_INC(j, i+1, nums.size()) {
                const int J = nums[j];
                if (J == 0) continue;
                // J is non-zero
                nums[i] = J;
                nums[j] = 0;
                break;
            }
        }
    }

```

### GitHub

- [MoveZeros](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/MoveZeros>){:target="_blank"}

![MoveZeros]({{ "/assets/img/posting/move_zeros.png" | relative_url }})
