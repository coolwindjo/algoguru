---
title: 1315. Sum of Nodes with Even-Valued Grandparent
layout: post
tags:
- cpp
- simple-implementation
- medium
- dfs

---

<https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/>{:target="_blank"}

### Source

```cpp

    int sumEvenGrandparent(TreeNode* root) {
		if (nullptr == root) return 0;
		int sum = 0;
		if (root->val % 2 == 0) {
			sum += sumGrands(root);
		}
		sum += sumEvenGrandparent(root->left);
		sum += sumEvenGrandparent(root->right);
		return sum;
    }

	int sumGrands(TreeNode* root) {
		if (nullptr == root) return 0;
		int sum = 0;
		if (nullptr != root->left) {
			TreeNode* node = root->left->left;
			if (nullptr != node) {
				sum += node->val;
			}
			node = root->left->right;
			if (nullptr != node) {
				sum += node->val;
			}
		}
		if (nullptr != root->right) {
			TreeNode* node = root->right->left;
			if (nullptr != node) {
				sum += node->val;
			}
			node = root->right->right;
			if (nullptr != node) {
				sum += node->val;
			}
		}
		return sum;
	}

```

### GitHub

- [SumEvenGrandParent](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/SumEvenGrandParent>){:target="_blank"}
