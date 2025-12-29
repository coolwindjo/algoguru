---
layout: post
tags:
- cpp
- std-deque
---

# LeetCode Problem Link
<https://leetcode.com/problems/sliding-window-maximum>{:target="_blank"}

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
- at first, thought about using a map, but it was too expensive to insert and delete ($$O(\log k)$$)
- also, the key value can be duplicated and invalid indices should be removed as the window moves

# Approach
<!-- Describe your approach to solving the problem. -->
- to remove invalid items out of window, let's use queue
- also, we need to remove previous items that is smaller than new item
- a two-way modifiable queue is required for keeping only `k` items decreasing order => **Monotonic Queue**
```cpp
        typedef std::pair<int, size_t> is;
        std::deque<is> mon_q;
        for (size_t i=0; i<n; ++i) {
            while (!mon_q.empty()
                && mon_q.back().first <= nums[i]) {
                mon_q.pop_back();
            }
            mon_q.emplace_back(std::make_pair(nums[i], i));
            if (static_cast<int32_t>(mon_q.front().second) <= static_cast<int32_t>(i)-k) {
                mon_q.pop_front();
            }
            if (i>=k-1) result.push_back(mon_q.front().first);
        }
```
- if we don't sort based on the values, then we don't need the value itself => use nums[] to check the value
- we need signed values to check > or <
- for checking == or !=, we can use unsigned values
- in the initial interval where `i < k`, `i - k` underflows and becomes a large positive integer => guard clause added

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(n)$$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(k)$$

# Code
```cpp
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if (k<=0) return result;
        const size_t n = size(nums);
        if (n==0) return result;
        std::deque<size_t> deq;
        for (size_t i=0; i<n; ++i) {
            while(!deq.empty() && nums[deq.back()] <= nums[i]) {
                deq.pop_back();
            }
            deq.emplace_back(i);
            if (i>k && deq.front() == i-k) {    // gaurd clause added
                deq.pop_front();
            }
            if (i>=k-1) {
                result.push_back(nums[deq.front()]);
            }
        }
        return result;
    }
```

### GitHub

- ToDo: [sliding-window-maximum](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/sliding-window-maximum>){:target="_blank"}

![sliding-window-maximum]({{ "/assets/img/posting/sliding-window-maximum.png" | relative_url }})
