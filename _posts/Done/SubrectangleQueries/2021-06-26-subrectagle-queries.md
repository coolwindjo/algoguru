---
title: 1476. Subrectangle Queries
layout: post
tags:
- cpp
- simple-implementation
- medium

---

<https://leetcode.com/problems/subrectangle-queries/>{:target="_blank"}

### Source

```cpp

    class SubrectangleQueries {
        vvi m_rect;
    public:
        SubrectangleQueries(vector<vector<int>>& rectangle) {
            m_rect = rectangle;
        }

        void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
            FOR_INC (row, row1, row2+1) {
                FOR_INC (col, col1, col2+1) {
                    m_rect[row][col] = newValue;
                }
            }
        }

        int getValue(int row, int col) {
            return m_rect[row][col];
        }
    };

```

### GitHub

- [SubrectangleQueries](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/SubrectangleQueries>){:target="_blank"}
