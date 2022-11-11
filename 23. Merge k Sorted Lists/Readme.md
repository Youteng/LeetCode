<center><h1>Merge k Sorted Lists</h1></center>

[Leetcode Link](https://leetcode.com/problems/merge-k-sorted-lists/)

### Intorduce
k sorted in ASC lists will be provided as input, the only thing we need to do is to merge these lists with ordered into one list and return it.

Ofcourse we can using some methods like merge sort to solve this problem, but using min heap can achieve that easier.

### Min Heap
Heap is a common data structure used to store data that need to be sorted anytime, there are two types of heap, max heap and min heap.

A heap is looks like a tree, the only different between heap and BST is that the data stored in a heap is ordered.
![](https://i.imgur.com/Lv8LVU3.png)

In C#, a PriorityQueue is implemented with a min heap.

### Method
Three things we need to do when we get input lists:
1. Initialize a PriorityQueue res.
2. Enqueue all the heads of each list into res.
3. Initialize a ListNode result.
4. Chaining all the nodes stored in res as a list with Dequeue.
5. Return result.

### Code
```csharp
public class Solution {
    public ListNode MergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode, int> res = new();
        foreach(var i in lists)
        {
            if(i is not null)
            {
                res.Enqueue(i, i.val);
            } 
        }
        
        ListNode head = new();
        ListNode result = head;
        while(res.Count != 0)
        {
            head.next = res.Dequeue();
            head = head.next;
            if(head.next is not null) 
            {
                res.Enqueue(head.next, head.next.val);
            }
        }
        
        return result.next;
    }
}
```

### Refrences
https://javascript.plainenglish.io/real-world-uses-cases-for-heaps-e57edbeb7da3

###### tags: `Leetcode`