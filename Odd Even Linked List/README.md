<center><h1>Odd Even Linked List</h1></center>

### Introduction
A linked list is given as input, returning a reordered list that groups all the odd and even nodes in the original list.

Example:
![](https://hackmd.io/_uploads/S1iZwz2x3.png)
```
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
```

![](https://hackmd.io/_uploads/ByXXDz2e3.png)
```
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
```

### Method

First, three pointers should be defined, `odd`, `even` and `even_start`, which indicate the start node of the odd list, the start of the even list, and the anchor for the even list.

And that is easy to know, the `odd` should set to `head`, and both `even` and `even_start` should be set to `head->next`.

Then we just need to traverse the whole list and link all the odd and even nodes which are `odd->next->next` and `even->next->next` when the condition `odd->next && even->next` is true.

Then we just need to link `odd` to the anchor `even_start`, the answer is the `head`.

### Code
```cpp
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next)return head;

        ListNode* odd = head;
        ListNode* even_start = head->next;
        ListNode* even = head->next;

        while(odd->next && even->next)
        {
            odd->next = odd->next->next; // link all odd nodes
            even->next = even->next->next; // link all even nodes
            odd = odd->next;
            even = even->next;
        }

        odd->next = even_start; // link the odd-even nodes together
        return head;
    }
};
```

###### tags: `Leetcode`