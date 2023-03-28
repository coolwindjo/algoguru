---
title: 771. Jewels and Stones
layout: post
tags:
- cpp
- easy
- string-manipulation
- std-find_first_of

---

<https://leetcode.com/problems/jewels-and-stones/>{:target="_blank"}

### Source

```cpp

    int numJewelsInStones(string jewels, string stones) {
        int cnt = 0;
        int prev = 0, pos;
        while ((pos=stones.find_first_of(jewels, prev)) != string::npos) {
            cnt++;
            prev = pos + 1;
        }
        return cnt;
    }

```

### GitHub

- [JewelsStones](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/JewelsStones>){:target="_blank"}

![JewelsStones]({{ "/assets/img/posting/jewels_stones.png" | relative_url }})
