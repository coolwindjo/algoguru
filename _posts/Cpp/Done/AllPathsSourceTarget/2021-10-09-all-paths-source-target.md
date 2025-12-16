---
title: 797. All Paths From Source to Target
layout: post
tags:
- cpp
- dfs

---

<https://leetcode.com/problems/all-paths-from-source-to-target/>{:target="_blank"}

### Source

```cpp

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vvi vviAns;
        DFS(vviAns, vi(), 0, graph);
        return vviAns;
    }

    void DFS(vvi& vviResult, vi viPath, const int cur, vvi& vviGraph) {
        if (vviGraph.size() == 0) return;
        if ((cur < 0) || (cur >= vviGraph.size())) return;

        viPath.push_back(cur);
        if (cur == vviGraph.size()-1) {
            vviResult.push_back(viPath);
        }

        for (int next : vviGraph[cur]) {
            DFS(vviResult, viPath, next, vviGraph);
        }
    }

```

### GitHub

- [AllPathsSourceTarget](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/AllPathsSourceTarget>){:target="_blank"}
