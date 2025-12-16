---
title: 623. Add One Row to Tree
layout: post
tags:
- cpp
- dfs

---

<https://leetcode.com/problems/add-one-row-to-tree/>{:target="_blank"}

### Source

```cpp

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (1 == depth) {
            TreeNode* node = new TreeNode(val, root, nullptr);
            root = node;
        }
        else {
            DFS(root, val, depth-1);
        }
        return root;
    }

    void DFS(TreeNode* cur, const int val, const int depth) {
        if (nullptr == cur) return;
        if (1 == depth) {
            TreeNode* node = new TreeNode(val, cur->left, nullptr);
            cur->left = node;
            node = new TreeNode(val, nullptr, cur->right);
            cur->right= node;
        }

        if (nullptr != cur->left) DFS(cur->left, val, depth-1);
        if (nullptr != cur->right) DFS(cur->right, val, depth-1);
    }

```

### GitHub

- [AddOneRow](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/AddOneRow>){:target="_blank"}

![AddOneRow]({{ "/assets/img/posting/add_one_row.png" | relative_url }})
