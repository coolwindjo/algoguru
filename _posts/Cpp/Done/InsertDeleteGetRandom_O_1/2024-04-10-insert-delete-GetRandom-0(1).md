---
title: Insert Delete GetRandom in 0(1)
layout: post
tags:
- cpp
- std-unordered-map
- std-unordered-set

---

<https://leetcode.com/problems/insert-delete-getrandom-o1/>{:target="_blank"}

### Source

```cpp

    bool insert_dicvec(int val) {
        auto itD = pDic->find(val);
        if (itD != end(*pDic)) return false;
        pV->push_back(val);
        (*pDic)[val] = pV->size() - 1;
        return true;
    }

    bool insert_hash(int val) {
        auto it = pHash->find(val);
        if (it != end(*pHash)) return false;
        pHash->emplace(val);
        return true;
    }

    bool remove_dicvec(int val) {
        auto itD = pDic->find(val);
        if (itD == end(*pDic)) return false;
        (*pV)[itD->second] = pV->back();
        (*pDic)[pV->back()] = itD->second;
        pV->pop_back();
        pDic->erase(val);
        return true;
    }

    bool remove_hash(int val) {
        auto it = pHash->find(val);
        if (it == end(*pHash)) return false;
        pHash->erase(val);
        return true;
    }

    int getRandom_dicvec() {
        if (pV->size() == 0) return -1;
        return (*pV)[rand() % pV->size()];
    }

    int getRandom_hash() {
        if (pHash->size() == 0) return -1;
        int r = std::rand() / ((RAND_MAX + 1u) / pHash->size());
        auto it = begin(*pHash);
        for (; it != end(*pHash); ++it) {
            if (r-- == 0) break;
        }
        return *it;
    }

```

### GitHub

- [InsertDeleteGetRandomO1](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/InsertDeleteGetRandomO1>){:target="_blank"}

![InsertDeleteGetRandomO1]({{ "/assets/img/posting/InsertDeleteGetRandomO1.png" | relative_url }})
