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