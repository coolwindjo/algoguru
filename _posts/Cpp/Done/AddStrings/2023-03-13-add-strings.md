---
title: 415. Add Strings
layout: post
tags:
- cpp
- simple-implementation
- string-manipulation

---

<https://leetcode.com/problems/add-strings>{:target="_blank"}

### Source

```cpp

    string addStrings(string num1, string num2) {
        std::string ans;
        int carry = 0;
        auto it1 = std::rbegin(num1), it2 = std::rbegin(num2);
        for (int i=0; i<INF; ++i) {
            bool inc1 = false;
            bool inc2 = false;
            if (it1 != std::rend(num1)) inc1 = true;
            if (it2 != std::rend(num2)) inc2 = true;

            if (!inc1 and !inc2) break;

            const int n1 = inc1? (*it1) - '0' : 0;
            const int n2 = inc2? (*it2) - '0' : 0;
            int sum = n1 + n2 + carry;
            carry = 0;
            if (sum > 9) {
                carry = 1;
                sum %= 10;
            }

            ans = std::to_string(sum) + ans;

            if (inc1) ++it1;
            if (inc2) ++it2;
        }
        if (carry > 0) ans = std::to_string(carry) + ans;
        return ans;
    }

```

### GitHub

- [AddStrings](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/AddStrings>){:target="_blank"}
