---
title: Reverse Linked List II
layout: post
tags:
- cpp
- simple-implementation
- medium
- linked-list

---

<https://leetcode.com/problems/reverse-linked-list-ii/>{:target="_blank"}

### Source

```cpp

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (nullptr == head) return nullptr;
        if (nullptr == head->next) return head;

        ListNode* itLeftPrev = nullptr;
        ListNode* itLeft = findNode(head, left, &itLeftPrev);
        if (nullptr == itLeft) return nullptr;

        ListNode* itRight = findNode(head, right, nullptr);
        if (nullptr == itRight) return nullptr;

        ListNode* itNewLeft = reverse(itLeft, itRight);
        W_IFNOT(itRight->val == itNewLeft->val);
        if (nullptr != itLeftPrev) {
            itLeftPrev->next = itNewLeft;
        }
        else {
            head = itNewLeft;
        }
        return head;
    }

    ListNode* findNode(ListNode* begin, int pos, ListNode** ppPrev) {
        if (nullptr == begin) return nullptr;
        ListNode* curr = begin;
        ListNode* prev = nullptr;
        while(curr) {
            if (--pos == 0) {
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        if (nullptr != ppPrev) {
            *ppPrev = prev;
        }
        return curr;
    }

    ListNode* reverse(ListNode* head, ListNode* tail) {
        if (head == tail) return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr != tail) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if (nullptr != curr) {
            head->next = curr->next;
            curr->next = prev;
            return curr;
        }
        return prev;
    }

```

### GitHub

- [ReverseBetween](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/ReverseBetween>){:target="_blank"}
