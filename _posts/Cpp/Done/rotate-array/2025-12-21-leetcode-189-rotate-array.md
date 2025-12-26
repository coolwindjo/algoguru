---
layout: post
tags:
- cpp
- simple-implementation
- cyclic-replacement
- std::reverse
- std::rotate
- mathematics
---

# LeetCode Problem Link
<https://leetcode.com/problems/rotate-array>{:target="_blank"}

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
- I restrict myself to think only for the space complexity of $$O(1)$$.
- then, the problem becomes to be medium level.
- It shows jumping indices to move the value to the next position.

# Approach
<!-- Describe your approach to solving the problem. -->
- check whether I could jump to the previous position then, I can set aside the first value and shift the previous value to the current position and make the previous position to be the current position.
```cpp
    size_t prev(const size_t cur, const size_t k, const size_t n) noexcept {
        const size_t j = k % n;
        return ((cur+n)-j) % n;
    }
    size_t next(const size_t cur, const size_t k, const size_t n) noexcept {
        return (cur+k) % n;
    }
    void rotate(vector<int>& nums, int k) {
        const size_t n = size(nums);
        k = k % n
        if (k == 0) return;  // [1], 0
        if (n == 1) return;  // [1], 3
        int first = nums[0];
        size_t cur = 0;
        for(size_t i=0; i<n; ++i) {
            const size_t prv = prev(cur, k, n);
                nums[cur] = nums[prv];
                cur = prv;
        }
        // the last move from the value I set aside at the beginning
        nums[next(0, k, n)] = first;
    }
```
- but, there are corner cases: 'nums=[-1, -100, 3, 99], k=2' / 'nums=[1,2,3,4,5,6], k=2'
- This method requires traversing only the elements within a single cycle, rather than traversing all elements, thus necessitating movement between cycles.
- these cycles are all the same size, and the number of cycles is the result of dividing the size of the `nums` array by the size of one cycle. **the cycle size** is the **GCD (n, k)**.
```cpp
        size_t start = 0;
        int val = nums[start];
        size_t cur = start;
        for(size_t i=0; i<n; ++i) {
            const size_t prv = prev(cur, k, n);
            if (prv == start) {
                // the last move from the value I set aside at the beginning
                nums[cur] = val;
                start++;
                val = nums[start];
                cur = start;
            }
            else {
                nums[cur] = nums[prv];
                cur = prv;
            }
        }
```
- the code is "write-only code." poor readability.
    - Cognitive Load (인지 부하): prev, next, start(?), cur... 인덱스 계산이 너무 복잡합니다. 코드가 복잡하면 버그가 숨을 곳이 많아집니다.
    - Modulo Overhead: prev 함수 내부의 Modulo(%) 연산은 CPU 사이클을 많이 먹습니다. 루프마다 이를 수행하는 것은 비효율적입니다.
    - Cache Locality: 메모리를 띄엄띄엄 읽어옵니다(nums[prv]). 배열의 크기가 커질수록 Cache Miss가 발생하여 성능이 저하됩니다.

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(n)$$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(1)$$

# Code
```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const size_t n = size(nums);
        k = k % n;  // Key Logic!!
        if (k == 0) return;
        if (n == 1) return;
#if 0
#if 0
        std::rotate(begin(nums), end(nums)-(k%size(nums)), end(nums));
#else
        std::reverse(begin(nums), end(nums));
        std::reverse(begin(nums), begin(nums)+k);
        std::reverse(begin(nums)+k, end(nums));
#endif
#endif
#if 1
        size_t cycles = std::gcd(n, k);
        for (size_t start=0; start<cycles; ++start) {
            int val = nums[start];
            size_t cur = start;
            do {
                const size_t nxt = (cur + k) % n;
                int tmp = nums[nxt];
                nums[nxt] = val;
                cur = nxt;
                val = tmp;
            } while (cur != start);
        }
#endif
#if 0
        size_t start = 0;
        size_t cnt = 0;
        while (cnt<n) {
            int val = nums[start];
            size_t cur = start;
            do {
                const size_t nxt = (cur + k) % n;
                int tmp = nums[nxt];
                nums[nxt] = val;
                cur = nxt;
                val = tmp;
                ++cnt;  // cycle decomposition
            } while (cur != start);
            start++;
        }
#endif
#if 0
        size_t start = 0;
        int val = nums[start];
        size_t cur = start;
        for (size_t cnt=0; cnt < n; ++cnt) {
            const size_t prv = ((cur+n)-k) % n;
            if (prv == start) {
                nums[cur] = val;
                start++;
                val = nums[start];
                cur = start;
            }
            else {
                nums[cur] = nums[prv];
                cur = prv;
            }
        }
#endif
    }
};
```

### GitHub

- ToDo: [rotate-array](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/rotate-array>){:target="_blank"}

![rotate-array]({{ "/assets/img/posting/rotate-array.png" | relative_url }})
