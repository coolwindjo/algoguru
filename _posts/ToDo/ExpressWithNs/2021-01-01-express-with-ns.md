---
title: 
layout: post
tags:
- cpp
- dynamic-programming
- combination
- permutation
- dfs
- std-unordered-set

---

<https://programmers.co.kr/learn/courses/30/lessons/42895>{:target="_blank"}

### Source

```cpp

    void DFS(const int numNs, const int result){
        if (numNs > MAX_NUM) return;
        if (numNs >= minNumNs) return;

        if (result == number) {
            minNumNs = numNs;
        }

        hashM[numNs].insert(result);

        int NN = 0;
        FOR(i, MAX_NUM){
            int nextNumNs = numNs + i + 1;
            if (nextNumNs > MAX_NUM) break;

            NN = NN*10 + N;
            int plus = NN + result;
            int minus = NN - result;
            int mult = NN * result;

            if (hashM[nextNumNs].find(plus)==hashM[nextNumNs].end()){
                DFS((nextNumNs), (plus));
            }
            if (hashM[nextNumNs].find(minus)==hashM[nextNumNs].end()){
                DFS((nextNumNs), (minus));
            }
            if (hashM[nextNumNs].find(-1*minus)==hashM[nextNumNs].end()){
                DFS((nextNumNs), (-1*minus));
            }
            if (hashM[nextNumNs].find(mult)==hashM[nextNumNs].end()){
                DFS((nextNumNs), (mult));
            }
            if (result != 0) {
                int divid = NN / result;
                if (hashM[nextNumNs].find(divid)==hashM[nextNumNs].end()){
                    DFS((nextNumNs), (divid));
                }
            }
            if (NN != 0) {
                int r_divid = result / NN;
                if (hashM[nextNumNs].find(r_divid)==hashM[nextNumNs].end()){
                    DFS((nextNumNs), (r_divid));
                }
            }
        }
    }

    int DP(){
        int minNumNs = MAX_NUM + 1;
        int NN = 0;
        FOR(i, MAX_NUM){
            int I = i+1;
            NN = NN*10 + N; // 5, 55, 555, ... , 55555555
            hashM[I].insert(NN);
            hashM[I].insert(-1*NN);
            FOR(j, i){
                int J = j+1;
                int K = (i-j);    // I:J:K = i+1:j+1:i-j, 2:1:1
                                  //                    , 3:1:2, 3:2:1
                for(auto itJ = hashM[J].begin(); itJ!=hashM[J].end(); ++itJ){
                    for(auto itK = hashM[K].begin(); itK!=hashM[K].end(); ++itK){
                        int plus = *itJ + *itK;
                        int minus = *itJ - *itK;
                        int mult = *itJ * *itK;
                        if (hashM[I].find(plus)==hashM[I].end()){
                            hashM[I].insert(plus);
                        }
                        if (hashM[I].find(minus)==hashM[I].end()){
                            hashM[I].insert(minus);
                        }
                        if (hashM[I].find(mult)==hashM[I].end()){
                            hashM[I].insert(mult);
                        }
                        if (*itK != 0) {
                            int div = *itJ / *itK;
                            if (hashM[I].find(div)==hashM[I].end()){
                                hashM[I].insert(div);
                            }
                        }
                    }
                }
            }
            if (hashM[I].find(number) != hashM[I].end()) {
                minNumNs = I;
                break;
            }
        }
        return  minNumNs;
    }


```

### GitHub

- [ExpressWithNs](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/ExpressWithNs>){:target="_blank"}

![ExpressWithNs]({{ "/assets/img/posting/title_name.png" | relative_url }})
