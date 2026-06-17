class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int a = 0, b = 0;

        // Count the lengths of both linked lists
        while(temp1 != NULL || temp2 != NULL)
        {
            if(temp1 != NULL){
                a++;
                temp1 = temp1->next;
            }

            if(temp2 != NULL){
                b++;
                temp2 = temp2->next;
            }
        }

        int n;

        if(a == b){

            // Traverse both lists together until intersection is found  if both have equal length
            while(headA != headB){
                headA = headA->next;
                headB = headB->next;
            }
            return headA;
        }

        if(a < b){

            n = b - a;

            // Move headB ahead by 'n' length difference . so, that both can start at same distance from intersection 
            while(n--)
                headB = headB->next;

            // Traverse both lists together to find intersection
            while(headA != headB)
            {
                headA = headA->next;
                headB = headB->next;
            }
            return headA;
        }

        else{
// Similar to above but a have extra nodes
            n = a - b;

            
            while(n--)
                headA = headA->next;

            
            while(headA != headB)
            {
                headA = headA->next;
                headB = headB->next;
            }
            return headB;
        }
    }
};