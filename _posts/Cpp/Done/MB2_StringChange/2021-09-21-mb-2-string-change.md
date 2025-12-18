---
title: MB2 String Change
layout: post
tags:
- cpp
- string-manipulation
- string-substr
- string-find
- string-replace

---

### Source

```cpp

    bool isValid(const string& a) {
        string subA = a;
        while (subA.length() > 0) {
            if (subA[0] == 'a') {
                subA = subA.substr(1, subA.length()-1);
            }
            else if (subA[(subA.length()-1)] == 'a') {
                subA = subA.substr(0, subA.length()-1);
            }
            else if ((subA[0] == 'b') && (subA[(subA.length()-1)] == 'b')) {
                int cnt = 0;
                while (subA.length() > 0) {
                    if ((subA[0] != 'b') || (subA[(subA.length()-1)] != 'b')) {
                        break;
                    }
                    subA = subA.substr(1, subA.length()-2);
                    cnt++;
                }
                FOR (i, cnt) {
                    string tmp = subA;
                    auto it = tmp.find("a");
                    if (it != string::npos) {
                        tmp.replace(it, 1, "");
                    }
                    else {
                        return false;
                    }
                }
            }
            else {
                return false;
            }
        }
        return true;
    }

```

### GitHub

- [MB2_StringChange](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/MB2_StringChange>){:target="_blank"}

![MB2_StringChange]({{ "/assets/img/posting/mb2_string_change.png" | relative_url }})
