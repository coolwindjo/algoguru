---
title: 206. Reverse Linked List
layout: post
tags:
- cpp
- linked-list

---

<https://leetcode.com/problems/reverse-linked-list/>{:target="_blank"}

### Source

```cpp

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

```

### GitHub

- [ReverseList](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/ReverseList>){:target="_blank"}
