---
title: Valid Square
layout: post
tags:
- cpp
- implementation
- medium
- mathematics

---

<https://leetcode.com/problems/valid-square/>{:target="_blank"}

### Source

```cpp

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vvi vviPts;
        vviPts.push_back(p1);
        vviPts.push_back(p2);
        vviPts.push_back(p3);
        vviPts.push_back(p4);
        int maxLen = 1;
        maxLen = calMaxDistSq(vviPts, maxLen);

        vvi vviEndPts = getEndPts(vviPts, maxLen);

        if (vviEndPts.size() < 4) {
            return false;
        }

        const int prod = product(vviEndPts);
        if (prod == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    int product(const vvi& vviEndPts) {
        vi viPtA, viPtB;

        viPtA.push_back(vviEndPts[0][0] - vviEndPts[1][0]);
        viPtA.push_back(vviEndPts[0][1] - vviEndPts[1][1]);

        viPtB.push_back(vviEndPts[2][0] - vviEndPts[3][0]);
        viPtB.push_back(vviEndPts[2][1] - vviEndPts[3][1]);

        return viPtA[0]*viPtB[0] + viPtA[1]*viPtB[1];
    }

    int calMaxDistSq(const vvi& vviPts, const int initMaxLen) {
        int maxLen = initMaxLen;
        for (int i=0; i<3; ++i) {
            const vi pt1 = vviPts[i];
            for (int j=i; j<4; ++j) {
                const vi pt2 = vviPts[j];
                const int len = distSq(pt1, pt2);
                if (len > maxLen) {
                    maxLen = len;
                }
            }
        }
        return maxLen;
    }

    int distSq(vi pt1, vi pt2) {
        const int deltaX = (pt1[0]-pt2[0]);
        const int deltaY = (pt1[1]-pt2[1]);
        const int len = deltaX*deltaX + deltaY*deltaY;
        return len;
    }

    vvi getEndPts(const vvi& vviPts, const int maxDistSq) {
        vvi vviEndPts;
        for (int i=0; i<3; ++i) {
            const vi pt1 = vviPts[i];
            for (int j=i; j<4; ++j) {
                const vi pt2 = vviPts[j];
                const int len = distSq(pt1, pt2);
                if (len >= maxDistSq) {
                    vviEndPts.push_back(pt1);
                    vviEndPts.push_back(pt2);
                }
            }
        }
        return vviEndPts;
    }

```

### GitHub

- [ValidSquare](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/ValidSquare>){:target="_blank"}

![ValidSquare]({{ "/assets/img/posting/valid_square.png" | relative_url }})