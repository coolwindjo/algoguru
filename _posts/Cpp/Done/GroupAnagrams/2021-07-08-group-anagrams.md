---
title: 49. Group Anagrams
layout: post
tags:
- cpp
- sort
- std-unordered-map

---

<https://leetcode.com/problems/group-anagrams/>{:target="_blank"}

### Source

```cpp

    vector<vector<string>> groupAnagrams(vector<string>& strs)
        unordered_map<string, vstr> umapKeyAnas;

        for (int i=0; i<strs.size(); ++i) {
            /*/
            string strKey = strs[i];
            sort(begin(strKey), end(strKey));
            /*/
            map<char, int> code;
            for (auto c : strs[i]) {
                code[c]++;
            }
            string strKey;
            for (auto it=begin(code); it!=end(code); ++it) {
                strKey.push_back(it->first);
                strKey.push_back(('0'+it->second));
            }
            //*/

            if (umapKeyAnas.find(strKey) == end(umapKeyAnas)) {
                vstr vstrAnas;
                vstrAnas.push_back(strs[i]);
                umapKeyAnas.emplace(strKey, vstrAnas);
            }
            else {
                umapKeyAnas[strKey].push_back(strs[i]);
            }
        }

        vvstr vvstrAns(umapKeyAnas.size());
        int cnt = 0;
        for (auto it = begin(umapKeyAnas); it!=end(umapKeyAnas); ++it) {
            for (string strVal : it->second) {
                vvstrAns[cnt].push_back(strVal);
            }
            cnt++;
        }
        return vvstrAns;
    }

```

### GitHub

- [GroupAnagrams](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/GroupAnagrams>){:target="_blank"}

![GroupAnagrams]({{ "/assets/img/posting/group_anagrams.png" | relative_url }})
![GroupAnagramsMemo]({{ "/assets/img/posting/group_anagrams_memo.png" | relative_url }})
