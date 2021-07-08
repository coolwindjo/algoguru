---
title: Valid Parentheses
layout: post
tags:
- cpp
- implementation

---

<https://leetcode.com/problems/valid-parentheses/>{:target="_blank"}

### Source

```cpp

    bool isPair(const char c1, const char c2) {
        return (c1 == '(' && c2 == ')')
            || (c1 == '{' && c2 == '}')
            || (c1 == '[' && c2 == ']');
    }
    
    bool isOpening(const char c) {
        return (c == '(') || (c == '{') || (c == '[');
    }
    
    bool isValid(string s) {
        FOR(i, s.length()) {
            const char c = s[i];
            if (isOpening(c)) {
                m_S.push(s[i]);
                continue;
            }
            if (!m_S.empty()) {
                if (isPair(m_S.top(), c)) {
                    m_S.pop();
                }
                else return false;
            }
            else return false;
        }
        if (m_S.empty()) return true;
        else return false;
    }

```

### GitHub

- [ValidParentheses](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/ValidParentheses>){:target="_blank"}

![ValidParentheses]({{ "/assets/img/posting/valid-parentheses.png" | relative_url }})
