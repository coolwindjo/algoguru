---
title: Merge Two Binary Trees
layout: post
tags:
- cpp
- implementation
- binary-search-tree

---

<https://leetcode.com/problems/merge-two-binary-trees/>{:target="_blank"}

### Source

```cpp

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if ((nullptr == root1) && (nullptr == root2)) return nullptr;
        
        if (nullptr == root1) {
            return root2;
        }
        if (nullptr == root2) {
            return root1;
        }
        
        TreeNode* newRoot = new TreeNode(root1->val + root2->val,
                                         mergeTrees(root1->left, root2->left),
                                         mergeTrees(root1->right, root2->right));
        return newRoot;
    }

```

- No more new (dynamic allocations)!

```cpp

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* ans = PickNoneNull(root1, root2);
        if (nullptr == ans) return nullptr;
        
        PreorderMerge(ans, root1, root2);
        
        return ans;
    }
    
    
    TreeNode* PickNoneNull(TreeNode* root1, TreeNode* root2) {
        if ((nullptr == root1) && (nullptr == root2)) return nullptr;
        
        if (nullptr == root1) {
            return root2;
        }
        else if (nullptr == root2) {
            return root1;
        }
        else {
            return root1;
        }
    }
    
    void PreorderMerge(TreeNode* ans, TreeNode* root1, TreeNode* root2) {
        if (nullptr == ans) return;
        if ((nullptr == root1) || (nullptr == root2)) return;
        
        // Visit Root
        ans->val = root1->val + root2->val; 

        // Visit left 
        if (nullptr != ans->left) {
            PreorderMerge(ans->left, root1->left, root2->left);
        }
        else {
            // if null, check the other tree!
            ans->left = PickNoneNull(root1->left, root2->left);
        }

        // Visit right 
        if (nullptr != ans->right) {
            PreorderMerge(ans->right, root1->right, root2->right);
        }
        else {
            // if null, check the other tree!
            ans->right = PickNoneNull(root1->right, root2->right);
        }
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

- [MergeTrees](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/MergeTrees>){:target="_blank"}

