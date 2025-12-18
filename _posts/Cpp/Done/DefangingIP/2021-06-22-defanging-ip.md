---
title: 1108. Defanging an IP Address
layout: post
tags:
- cpp
- easy
- string-manipulation
- split-string
- string-find_first_of
- string-substr

---

<https://leetcode.com/problems/defanging-an-ip-address>{:target="_blank"}

### Source

```cpp

    string defangIPaddr(string address) {
        vstr vstrNums;
        size_t prev = 0;
        size_t pos = 0;
        while((pos=address.find_first_of("\".", prev))!=std::string::npos){
            int wlen = pos - prev;
            if (wlen > 0) {
                vstrNums.push_back(address.substr(prev, wlen));
            }
            prev = pos + 1;
        }
        int trail = address.length() - prev;
        if (trail > 0) {
            vstrNums.push_back(address.substr(prev, trail+1));
        }

        string strAns;
        for(string num : vstrNums){
            strAns += num;
            strAns += "[.]";
        }
        strAns = strAns.substr(0, (strAns.length()-3));
        return strAns;
    }

```

### GitHub

- [DefangingIP](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/DefangingIP>){:target="_blank"}
