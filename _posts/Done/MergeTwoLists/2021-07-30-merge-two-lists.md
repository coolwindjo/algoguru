---
title: Merge Two Sorted Lists
layout: post
tags:
- cpp
- implementation

---

<https://leetcode.com/problems/merge-two-sorted-lists/>{:target="_blank"}

### Source

```cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode stHead;
        ListNode* pstCur = &stHead;
        while ((l1!=nullptr) && (l2!=nullptr)) {
            if (l1->val < l2->val) {
                pstCur->next = l1;
                l1=l1->next;
            }
            else {
                pstCur->next = l2;
                l2=l2->next;
            }
            pstCur = pstCur->next;
        }
        while (l1!=nullptr) {
            pstCur->next = l1;
            l1=l1->next;
            pstCur = pstCur->next;
        }
        while (l2!=nullptr) {
            pstCur->next = l2;
            l2=l2->next;
            pstCur = pstCur->next;
        }
        return stHead.next;
    }

```

### GitHub

- [MergeTwoLists](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/MergeTwoLists>){:target="_blank"}
