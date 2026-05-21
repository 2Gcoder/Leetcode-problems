 ListNode* recursive(ListNode* head)
 {
     if(head == NULL || head->next == NULL)
            return head;

    ListNode* newhead = recursive(head->next);
    ListNode* front= head->next;
    front->next= head;
    head->next=NULL;
    return newhead;
 }
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) // common  in both
            return head;

// method 1 recursion
    //    return recursive(head);
 
 // method 2 swapping link 
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode;

        while(curr != NULL) {
            nextNode = curr->next; // store next
            curr->next = prev;     // reverse link
            prev = curr;           // move prev
            curr = nextNode;       // move curr
        }

        return prev;

    }
};