---
title: 680. Valid Palindrome II
layout: post
tags:
- cpp
- simple-implementation
- dfs
- dfs-with-backtracking
- string-manipulation

---

<https://leetcode.com/problems/valid-palindrome-ii>{:target="_blank"}

### Source

```cpp

    bool validPalindrome(string s) {
        is_valid_ = false;
        DFS(s, 0, s.size()-1, 1);
        return is_valid_;
    }
    void DFS(const string &s, const int i, const int j, const int c) {
        if (i>=j) is_valid_ = true;
        if (is_valid_) return;
        if (s[i] == s[j]) DFS(s, i+1, j-1, c);
        else if (c > 0) {
            DFS(s, i+1, j, c-1);
            DFS(s, i, j-1, c-1);
        }
        else return;
    }

    bool validPalindrome_simple(string s) {
        const int s_size = s.size();
        int skipcnt = 1;
        int tmpi=0;
        int tmpj=0;
        for (int i=0, j=s_size-1-i, lim=65432; i<j &&lim ;--lim) {
            if (s[i] == s[j]) {
                ++i;
                --j;
            }
            else if (skipcnt > 0){
                tmpi = i;
                tmpj = j;
                if (s[i+1] == s[j]) {
                    ++i;
                }
                else if (s[i] == s[j-1]) {
                    --j;
                }
                else return false;
                skipcnt--;
            }
            else if (skipcnt == 0) {
                i=tmpi;
                j=tmpj;
                --j;
                skipcnt--;
            }
            else return false;
        }
        return true;
    }

```

### GitHub

- [ValidPalindrome2](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/ValidPalindrome2>){:target="_blank"}
