---
title: LGSW Compiler
layout: post
tags:
- cpp
- implementation
- string-manipulation
- string-find_if
- string-substr
- std-stack

---

- Loop compiler <#ABC>

### Source

```cpp

    string Compile(const string& code) {
        string str(code);

        typedef pair<char, int> ci;
        stack<ci> St;
        FOR (i, str.length()) {
            const char c = str[i];
            if (c == '<') {
                St.push(ci(c, i));
            }
            else if (c == '>') {
                if (!St.empty()) {
                    const int beginIdx = St.top().second + 1;
                    string sub = str.substr(beginIdx, (i - beginIdx));
                    sub = RollOut(sub);
                    string prev(str.substr(0, beginIdx-1));
                    string post(str.substr(i+1, str.length()-(i+1)));
                    str = prev + sub + post;
                    St.pop();
                }
                else {
                    return "Error: not paired!";
                }
            }
            else {}
        }
        return str;
    }

    string RollOut(const string& str) {
        const auto it = begin(str);
        const auto itLast = find_if(it, end(str), [](const char c){
            return isalpha(c);
        });
        const int dist = distance(it, itLast);
        const string strNum = str.substr(0, dist);
        const int num = stoi(strNum);
        const int trL = str.length() - dist;
        const string trStr = str.substr(dist, trL);
        string result("");
        FOR (i, num) {
            result += trStr;
        }

        return result;
    }

```

### GitHub

- [LGSW_Compile](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/LGSW_Compile>){:target="_blank"}
