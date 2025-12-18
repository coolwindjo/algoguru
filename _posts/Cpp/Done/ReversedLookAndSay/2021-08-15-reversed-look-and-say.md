---
title: Reversed Look-And-Say
layout: post
tags:
- cpp
- simple-implementation
- string-manipulation
- std-cin-ignore

---

<https://www.codingame.com/ide/puzzle/reversed-look-and-say>{:target="_blank"}

### Source

```cpp

    void _Solve(){
        string s;
        getline(cin, s); cin.ignore();
        string strToCheck;
        while (s.length() > 0) {
            strToCheck = revLAS(s);
            if (s.compare(strToCheck) == 0) break;
            if (s.compare(convLAS(strToCheck)) != 0) break;
            s = strToCheck;
        }
        cout << s;
    } // _Solve()

    string revLAS(const string& strLAS) {
        string ret("");
        int numVals = 0;
        for (auto c : strLAS) {
            if (0 == numVals) {
                numVals = c - '0';
                continue;
            }
            string strVals(numVals, c);
            ret += strVals;
            numVals = 0;
        }
        return ret;
    }

    string convLAS(const string& str) {
        string ret("");
        for (auto it = begin(str); it != end(str);) {
            auto itLast = find_if_not(next(it), end(str), [it](auto& s){
                return (s == *it);
            });
            ret += to_string(distance(it, itLast));
            ret += *it;
            it = itLast;
        }
        return ret;
    }

```

### GitHub

- [ReversedLookAndSay](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/ReversedLookAndSay>){:target="_blank"}
