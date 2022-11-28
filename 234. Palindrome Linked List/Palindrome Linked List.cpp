class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* cur = head;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        int mid;
        int size = 0;
        
        while(head){
            size++;
            head = head->next;
        }
        
        mid = size / 2;
        
        while(mid != 0){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            mid--;
        }
        
        cur = size % 2 == 0 ? cur : cur->next;
        
        while(cur){
            if(cur->val != prev->val) return false;
            cur = cur->next;
            prev = prev->next;
        }
        return true;
    }
};