---
title: LGSW Coupon
layout: post
tags:
- cpp
- simple-implementation
- sort

---

- N: number of {price : delivery cost}
- M: initial amount of money
- 1 Coupon: get half price for one of them

### Source

```cpp

    void _Solve(){

        vii viiP(m_N);
        FOR (i, m_N) {
            viiP[i] = ii(-1*m_viiPC[i].first, i);
        }
        sort(begin(viiP), end(viiP));

        int maxCnt = 0;
        int maxRem = 0;
        FOR(i, m_N)
        {
            vii viiPC(m_viiPC);
            const int idx = viiP[i].second;
            const int price = viiPC[idx].first;
            viiPC[idx].first = static_cast<int>(price*0.5);

            Sort(viiPC);

            int rem = m_M;
            const int cnt = CalCntRem(viiPC, rem);

            if (cnt > maxCnt) {
                maxCnt = cnt;
                maxRem = rem;
            }
            else if (cnt == maxCnt) {
                if (rem > maxRem) {
                    maxRem = rem;
                }
            }
            else {}
        }

        cout << maxCnt << " " << maxRem;
    } // _Solve()

```

### GitHub

- [LGSW_Coupon](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/LGSW_Coupon>){:target="_blank"}
