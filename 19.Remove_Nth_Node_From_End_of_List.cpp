class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) { 
        if(head == NULL) return NULL;

        ListNode* curr = head;
        ListNode* prev = head;

        int cnt = 0;
        while(cnt < n)
        {
            curr = curr->next;
            cnt++;
        }

        // Remove first node
        if(curr == NULL) return head->next;

        while(curr->next != NULL)
        {
            curr = curr->next;
            prev = prev->next;
        }
        prev->next = prev->next->next;
       

        return head;
    }
};