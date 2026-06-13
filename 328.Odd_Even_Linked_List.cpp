/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if((head == NULL || head->next == NULL) || head->next->next== NULL) return head;

        ListNode* even = head->next;
        ListNode* odd = head;
        ListNode* evenstart = head->next;
        ListNode* oddstart = head;

        while(odd != NULL && odd->next !=NULL)
        { 
            odd->next= odd->next->next;
            even->next=even->next->next;
            odd= odd->next;
            even = even -> next;

            if(odd->next == NULL || odd->next->next == NULL)
            { 
                odd ->next=evenstart;
                return oddstart;
            }
        }


        return oddstart;
    }
};