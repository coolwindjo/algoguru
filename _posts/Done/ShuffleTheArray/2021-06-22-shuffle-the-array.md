---
title: Shuffle the Array
layout: post
tags:
- cpp
- implementation

---

<https://leetcode.com/problems/shuffle-the-array/>{:target="_blank"}

### Source

```cpp

    vector<int> shuffle(vector<int>& nums, int n) {
        vi viX, viY;
        FOR(i, n){
            viX.push_back(nums[i]);
            viY.push_back(nums[n+i]);
        }
        vi viAns;
        int cnt = 0;
        FOR(i, nums.size()){
            if (i%2 == 1){
                viAns.push_back(viY[cnt]);
                cnt++;
            }
            else{
                viAns.push_back(viX[cnt]);
            }
        }
        return viAns;
    }

```

```cpp

    // Shorter (better) solution
    vector<int> shuffle(vector<int>& nums, int n) {
        vi viAns(nums.size());
        FOR(i, n){
            viAns[2*i] = (nums[i]);
            viAns[2*i+1] = (nums[n+i]);
        }
        return viAns;
    }

```

### GitHub

- [ShuffleTheArray](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/ShuffleTheArray>){:target="_blank"}
