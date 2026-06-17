ListNode* collisionpoint(ListNode* large,ListNode* small,int diff)
{
    while(diff--) // removing extra node of large LL, so, that both of them come at same distance from intersection
    large = large->next;

    while(large != small)
    {
        large = large->next;
        small = small->next;
    }

    return large;
}

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

        if(a>b)
        return collisionpoint(headA,headB,a-b);

        return collisionpoint(headB,headA,b-a);

        
    }
};