---
title: 1022. Sum of Root To Leaf Binary Numbers
layout: post
tags:
- cpp
- simple-implementation
- dfs
- binary-search-tree
- radix-conversion

---

<https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/>{:target="_blank"}

### Source

```cpp
    int sumRootToLeaf(TreeNode* root) {
        if (nullptr == root) return 0;

        // root node has a value 0 or 1.
        // root-to-leaf : binary number => DFS, bin2dec
        m_sum = 0;
        DFS(root, "");

        // Return the sum of these numbers
        return m_sum;
    }

    int bin2dec(const string strBin) {
        const int lenBin = strBin.length();
        int dec = 0;
        for (int i=0; i<lenBin; ++i){
            const int b = strBin[i]-'0';
            dec = (b + (dec <<= 1));
        }
        return dec;
    }

    void DFS(TreeNode* node, const string bin) {
        if (nullptr == node) return;

        const string strNum = to_string(node->val);
        const string newBin = bin + strNum;

        if (nullptr == node->left && nullptr == node->right) {
            m_sum += bin2dec(newBin);
            return;
        }

        DFS(node->left, newBin);
        DFS(node->right, newBin);
    }
```

### GitHub

- [SumRootToLeaf](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/SumRootToLeaf>){:target="_blank"}
