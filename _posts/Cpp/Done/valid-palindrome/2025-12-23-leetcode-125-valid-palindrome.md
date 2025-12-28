---
layout: post
tags:
- cpp
- two-pointers
- string-manipulation
- std-tolower
- std-isalnum
- std-all_of
- std-transform
---

# LeetCode Problem Link
<https://leetcode.com/problems/valid-palindrome>{:target="_blank"}

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
- change all the letters to lower cases
```cpp
        std::transform(begin(s), end(s), begin(s), [](uint8_t ch) {
                return std::tolower(ch);
        });
```
- skip all the non-alphanumeric characters
```cpp
        int cnt=0;
        for (auto ch : s) {
            if (std::isalnum(ch)) {
                s[cnt++] = ch;
            }
        }
```
- check whether there is stdlib for this but `all_of` is just for checking not for change
```cpp
        std::all_of(begin(s), end(s), [&s, &cnt](uint8_t ch) {
            if (std::isalnum(ch)) {
                s[cnt++] = ch;
            }
            return true;
        });
```


# Approach
<!-- Describe your approach to solving the problem. -->
- use two pointers rather than stack
```cpp
        if (cnt <= 1) return true;
        size_t head=0;
        size_t tail=cnt-1;
        for (;head<tail; ++head, --tail) {
            if (s[head] != s[tail]) {
                return false;
            }
        }
        return true;
```
- it works, then let's remove redundant copies using cyclic decomposition
```cpp
    bool isPalindrome(string s) {
        int head = 0;
        int tail = static_cast<int>(s.length())-1;
        for(;head<tail;++head,--tail) {
            while(head<tail&& !std::isalnum(s[head])){
                ++head;
            }
            while(head<tail&& !std::isalnum(s[tail])){
                --tail;
            }
            if (std::tolower(s[head])!= std::tolower(s[tail])) {
                return false;
            }
        }
        return true;
    }
```
- lastly, improve readability with one while loop and apply string_view

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
    bool isPalindrome(string_view s) {
        int head = 0;
        int tail = static_cast<int>(s.length())-1; 
        while (head<tail) {
            if(!std::isalnum(s[head])) {
                ++head;
                continue;
            }
            if(!std::isalnum(s[tail])) {
                --tail;
                continue;
            }
            if (std::tolower(s[head++])!= std::tolower(s[tail--])) {
                return false;
            }
        }
        return true;
    }
};
```

### GitHub

- ToDo: [valid-palindrome](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/valid-palindrome>){:target="_blank"}

![valid-palindrome]({{ "/assets/img/posting/valid-palindrome.png" | relative_url }})
