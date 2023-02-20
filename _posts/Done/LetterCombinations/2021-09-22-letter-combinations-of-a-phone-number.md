---
title: 
layout: post
tags:
- cpp
- dfs
- std-unordered-map
- std-unordered-set

---

<https://leetcode.com/problems/letter-combinations-of-a-phone-number/>{:target="_blank"}

### Source

```cpp

    unordered_map<int, string> lut {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };
    	
    vector<string> letterCombinations(string digits) {
        hashStr hash;
        DFS(digits, 0, "", hash);
        vstr vstrAns;
        for (auto it=begin(hash); it!=end(hash); ++it) {
            vstrAns.push_back(*it);
        }
        return vstrAns;
    }
    
    void DFS(const string& digits, const int idx, const string& letComb, hashStr& hash) {
        if (digits.length() == 0) {
            return;
        }
        if (idx == digits.length()) {
            hash.insert(letComb);
            return;
        }
        
        const int num = (digits[idx] - '0');
        const string letters = lut[num];
        FOR (i, letters.length()) {
            DFS(digits, idx+1, letComb + letters.substr(i, 1), hash);
        }
    }

```

### GitHub

- [LetterCombinations](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/LetterCombinations>){:target="_blank"}

![LetterCombinations]({{ "/assets/img/posting/letter_combinations.png" | relative_url }})
