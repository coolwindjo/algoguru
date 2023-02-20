---
title: All Possible Full Binary Trees
layout: post
tags:
- cpp
- dynamic-programming
- bfs
- std-unordered-map
- std-queue
- binary-search-tree

---

<https://leetcode.com/problems/all-possible-full-binary-trees/>{:target="_blank"}

### Source

```cpp

typedef vector<TreeNode*> vTN;
    vTN m_vTN;
    vector<TreeNode*> allPossibleFBT(int n) {
        m_vTN = BST(n);
        return m_vTN;
    }
    
    vector<TreeNode*> BST(int n) {
        if (n <= 0) return {};
        if (n == 1) return {new TreeNode(0)};
        
        const auto it = hashN.find(n);
        if (it != end(hashN)) {
            return it->second;
        }
        
        // n >= 3
        vTN vTNs;
        for (int i=1; i<(n-1); i+=2) {          // 3    5   5   7   7   7
            vTN vTN_left = BST(i);              // 1    1   3   1   3   5
            vTN vTN_right = BST((n-1)-i);       // 1    3   1   5   3   1
            for (auto l : vTN_left) {
                for (auto r : vTN_right) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    vTNs.push_back(root);
                }
            }
        }
        hashN.insert(make_pair(n, vTNs));
        return vTNs;
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

void BFSPrint(TreeNode* root, int& cnt) {
    if (cnt == 0) return;

    queue<TreeNode*> qTN;
    qTN.emplace(root);
    while ((!qTN.empty()) && (cnt)) {
        TreeNode* tn = qTN.front(); qTN.pop();
        if (nullptr == tn) {
            cout << "null, ";
        }
        else {
            cout << tn->val << ", ";
            cnt--;
            qTN.emplace(tn->left);
            qTN.emplace(tn->right);
        }
    }
}

void PrintBST(TreeNode* root, int cnt) {
    cout << "[";
    BFSPrint(root, cnt);
    cout << "], ";
}

```

### GitHub

- [AllPossibleFBT](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/AllPossibleFBT>){:target="_blank"}

![AllPossibleFBT]({{ "/assets/img/posting/all_possible_fbt.png" | relative_url }})
