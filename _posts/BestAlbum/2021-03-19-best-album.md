---
title: Best Album
layout: post
tags:
- C++
- string manipulation
- unique and erase vector
- split string
- sort
- std::unordered_map

---

### Source

```cpp
  void _Solve(){
        typedef std::pair<int, vii> i_vii;
        typedef std::vector<i_vii> vivii;
        vivii viviiTotVecPlaysId;

        typedef std::unordered_map<string, int> hash_str_i;
        hash_str_i hash_striGenreIdx;

        int genreCnt = 0;
        FOR(i, vstrGenre.size()){
            string genre = vstrGenre[i];
            int plays = viPlays[i];
            hash_str_i::iterator it = hash_striGenreIdx.find(genre);
            if (it == hash_striGenreIdx.end()) {
                vii viiTotVecPlaysId;
                viiTotVecPlaysId.push_back(ii(plays, i));
                viviiTotVecPlaysId.push_back(i_vii(plays, viiTotVecPlaysId));
                hash_striGenreIdx.insert(str_i(genre, genreCnt++));
            }
            else {
                // vivii[hash->int].vii.push_back()
                viviiTotVecPlaysId[it->second].second.push_back(ii(plays, i));
                // vivii[hash->int].int+=plays
                viviiTotVecPlaysId[it->second].first+=plays;
            }
        }

        std::sort(viviiTotVecPlaysId.begin(), viviiTotVecPlaysId.end(),
        [](const i_vii &a, const i_vii &b){
            return a.first > b.first;
        });
        vi viPick;
        for (auto i_viiTotVecPlaysId : viviiTotVecPlaysId) {
            auto viiPlaysId = i_viiTotVecPlaysId.second;
            std::sort(viiPlaysId.begin(), viiPlaysId.end(),
            [](const ii &a, const ii &b){
                if (a.first == b.second) {
                    return a.second < b.second;
                }
                return a.first > b.first;
            });
            for (int j=0; (j<2) && (j<viiPlaysId.size()); ++j) {
                viPick.push_back(viiPlaysId[j].second);
            }
        }
        for (auto id : viPick) {
            cout << id << " ";
        }
    } // Solve
```

{% highlight cpp %}

  void _Solve_arch(){
        typedef std::pair<int, vii> i_vii;
        typedef std::vector<i_vii> vivii;
        vivii viviiTotVecPlaysId;

        typedef std::pair<string, i_vii> str_ivii;
#if 0   // only key can be compared... the code below is not possible
        struct cmp {
            bool operator()(const str_ivii &a, const str_ivii &b) const {
                return a.second.first > b.second.first;
            }
        };
        typedef std::map<string, i_vii, cmp> hash_str_ivii;
#else
        typedef std::unordered_map<string, i_vii> hash_str_ivii;
#endif
        hash_str_ivii hash_striviiGenre;

        int genreCnt = 0;
        FOR(i, vstrGenre.size()){
            string genre = vstrGenre[i];
            int plays = viPlays[i];
            hash_str_ivii::iterator it = hash_striviiGenre.find(genre);
            if (it == hash_striviiGenre.end()) {
                vii viiTotVecPlaysId;
                viiTotVecPlaysId.push_back(ii(plays, i));
                hash_striviiGenre.insert(str_ivii(genre, i_vii(plays, viiTotVecPlaysId)));
            }
            else {
                // hash->ivii.vii.push_back()
                it->second.second.push_back(ii(plays, i));
                // hash->ivii.int
                it->second.first+=plays;
            }
        }

        hash_str_ivii::iterator it = hash_striviiGenre.begin();
        for (; it!=hash_striviiGenre.end(); ++it) {
            viviiTotVecPlaysId.push_back(
                // hash->ivii.int, hash->ivii.vii
                i_vii(it->second.first, it->second.second));
        }

#if 0 // Impossible to sort a map
        std::sort(hash_striviiGenre.begin(), hash_striviiGenre.end(),
        [](const string &a, const string &b){
            return a.length() > b.length();
        });
#else
        std::sort(viviiTotVecPlaysId.begin(), viviiTotVecPlaysId.end(),
        [](const i_vii &a, const i_vii &b){
            return a.first > b.first;
        });
#endif
        vi viPick;
        for (auto i_viiTotVecPlaysId : viviiTotVecPlaysId) {
            auto viiPlaysId = i_viiTotVecPlaysId.second;
            std::sort(viiPlaysId.begin(), viiPlaysId.end(),
            [](const ii &a, const ii &b){
                if (a.first == b.second) {
                    return a.second < b.second;
                }
                return a.first > b.first;
            });
            for (int j=0; (j<2) && (j<viiPlaysId.size()); ++j) {
                viPick.push_back(viiPlaysId[j].second);
            }
        }
        for (auto id : viPick) {
            cout << id << " ";
        }
    } // Solve

{% endhighlight %}

### GitHub

[BestAlbum](https://github.com/coolwindjo/RefCodes/tree/master/AlgoGuruProject/Cpp/Done/BestAlbum "BestAlbum")

![BestAlbum]({{ "/assets/img/posting/best_album.png" | relative_url }})
