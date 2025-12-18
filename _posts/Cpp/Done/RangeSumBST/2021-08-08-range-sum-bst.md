---
title: 938. Range Sum of BST
layout: post
tags:
- cpp
- easy
- binary-search-tree

---

<https://leetcode.com/problems/range-sum-of-bst/>{:target="_blank"}

### Source

```cpp

    int rangeSumBST(TreeNode* root, int low, int high) {
        if (nullptr == root) return 0;

        int sum = 0;
        const int val = root->val;
        if ((val >= low) && (val <=high)) {
            sum += val;
        }

        // if (nullptr != root->left) {
        if (val > low) {
            sum += rangeSumBST(root->left, low, high);
        }

        // if (nullptr != root->right) {
        if (val < high) {
            sum += rangeSumBST(root->right, low, high);
        }

        return sum;
    }

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* BFSBuildBST(const vector<string> vstrVal) {
    const int n = vstrVal.size();
    if (n == 0) return nullptr;
    int cnt = 0;
    if ("null" == vstrVal[cnt]) {
        return nullptr;
    }
    queue<TreeNode*> qTN;
    TreeNode* root = new TreeNode(stoi(vstrVal[cnt++]));
    qTN.emplace(root);
    while ((!qTN.empty() && (cnt < n))) {
        TreeNode* tn = qTN.front(); qTN.pop();
        string strVal = vstrVal[cnt++];
        if ("null" != strVal) {
            tn->left = new TreeNode(stoi(strVal));
        }
        qTN.emplace(tn->left);
        if (cnt == n) break;

        strVal = vstrVal[cnt++];
        if ("null" != strVal) {
            tn->right = new TreeNode(stoi(strVal));
        }
        qTN.emplace(tn->right);
        if (cnt == n) break;
    }

    return root;
}

```

### GitHub

- [RangeSumBST](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/RangeSumBST>){:target="_blank"}
