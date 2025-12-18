---
title: Chuck Norris
layout: post
tags:
- cpp
- dfs
- string-manipulation
- std-unordered-map
- back_inserter
- radix-conversion

---

<https://www.codingame.com/ide/puzzle/chuck-norris>{:target="_blank"}

### Source

```cpp

    void _Solve(){
        string msg;
        getline(cin, msg);

        vector<bool> bits;
        for (auto c : msg) {
            auto binary = toBinStr(c, 7);
            copy(begin(binary), end(binary), back_inserter(bits));
        }

        unordered_map <bool, string> toZeros {
            {false, "00 "},
            {true, "0 "}
        };

        for (auto it = begin(bits); it != end(bits);) {
            const bool curr = *it;
            auto itLast = find(next(it), end(bits), !curr);
            if (it != begin(bits)) cout << " ";
            cout << toZeros[*it] << string (distance(it, itLast), '0');
            it = itLast;
        }
    } // _Solve()

    vector<bool> DFS(const int n, const int r) {
        if (n <= 0) { return {}; }
        vector<bool> ret = DFS(n/r, r);
        ret.push_back(n%r);
        return ret;
    }

    vector<bool> toBinStr(const int n, const int disp) {
        vector<bool> bits = DFS(n, 2);
        int numSp = disp - bits.size();
        vector<bool> ret(numSp, false);
        copy(begin(bits), end(bits), back_inserter(ret));
        return ret;
    }

```

### GitHub

- [ChuckNorris](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/ChuckNorris>){:target="_blank"}

![ChuckNorris]({{ "/assets/img/posting/chuck_norris.png" | relative_url }})
