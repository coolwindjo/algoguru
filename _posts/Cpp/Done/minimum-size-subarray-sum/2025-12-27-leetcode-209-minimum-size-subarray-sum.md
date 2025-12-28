---
layout: post
tags:
- cpp
- two-pointers
- mathematics
- big-number
- std-upper_bound
- std-deque
- binary-search
---

# LeetCode Problem Link
<https://leetcode.com/problems/minimum-size-subarray-sum>{:target="_blank"}

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
- use two-pointers for implementing a sliding window
```cpp
        long long sum = 0;
        size_t l = 0;
        size_t r = 0;
        sum+=nums[l];   // engineering standard: array accesses inside loops where index bounds checking is guaranteed
        while (l<=r && r<n) {
            if (target <= sum) {
                min_len = std::min(min_len, r-l+1);
                sum-=nums[l++];
                continue;   // redundant complicated control flow
            }
            ++r;
            if (r<n) {
                sum+=nums[r];
            }
        }
```

# Approach
<!-- Describe your approach to solving the problem. -->
- "continue" reduces readability. let's use inner while loop.
```cpp
        size_t l = 0;
        for (size_t r=0; r<n; ++r) {
            sum+=nums[r];
            while (l<=r && target <= sum) {
                min_len = std::min(min_len, r-l+1);
                sum-=nums[l++];
            }
        }
```

# Extended thought
- just wanted to practice **Binary Search** with this, then I need to make it **Monotonic**
- preprocess to make a cumulative sum array, `PrefixSum[]`
```cpp
        vector<long long> P;
        P.push_back(0);
        for (size_t i=0; i<n; ++i) {
            P.push_back(P[i] + nums[i]);    // P[k+1]-P[k]=nums[k]
        }
```
- use the **Binary Search Standard Pattern**
```cpp
        int l=0;
        for (size_t r=0; r<n; ++r) {
            int hi = r;
            int low = l;
            while (low<=hi) {
                const size_t mid = low+((hi-low) >> 1);
                if (P[r+1]-P[mid] >= target) {
                    l = mid;
                    min_len = std::min(min_len, r+1-l);
                    low = mid+1;
                }
                else {
                    hi = mid-1;
                }
            }
        }
```

- use the STD library for the same approach with a trivial mathematics trick
```cpp
        for (size_t r=0; r<n; ++r) {
            size_t l=0;
            // P[r+1]-P[l] = nums[l] + ... + nums[r] >= target
            // P[r+1]-target >= P[l]
            // {..., P[l-1], P[l], it, ...}
            auto it = std::upper_bound(begin(P), end(P), (P[r+1]-target));
            if (it != begin(P)) {
                l = std::prev(it) - begin(P);
                min_len = std::min(min_len, r+1-l);
            }
        }
```

- if the `nums` array contains **negative numbers**, like LeetCode 862, then we should filter out some elements to be considered
- in this case, the monotonic dequeue is used
```cpp
        std::deque<size_t> deq;
        size_t l = 0;
        for (size_t r=0; r<n; ++r) {
            deq.emplace_back(r);
            while ( l<=r &&
                    target <= (P[deq.back()+1]-P[deq.front()])) {
                min_len = std::min(min_len, r-l+1);
                deq.pop_front();
                l++;
            }
        }
```

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(n)$$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(1)$$

# Code
```cpp
    int minSubArrayLen(int target, vector<int>& nums) {
        const size_t n = size(nums);
        if (n == 0) return 0;
        if (target <= 0) return 0;
        size_t min_len = n+1;
        long long sum = 0;
        size_t l = 0;
        for (size_t r=0; r<n; ++r) {
            sum+=nums[r];
            while (l<=r && target <= sum) {
                min_len = std::min(min_len, r-l+1);
                sum-=nums[l++];
            }
        }
        if (n+1 == min_len) {
            return 0;
        }
        return min_len;
    }

```

### GitHub

- ToDo: [minimum-size-subarray-sum](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/minimum-size-subarray-sum>){:target="_blank"}

![minimum-size-subarray-sum]({{ "/assets/img/posting/minimum-size-subarray-sum.png" | relative_url }})
