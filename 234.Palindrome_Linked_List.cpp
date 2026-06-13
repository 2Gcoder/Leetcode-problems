class Solution {
public:

    ListNode* reverseLL(ListNode* head) // function to reverse the secondhalf link of LL
    {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* newHead = reverseLL(head->next);

        head->next->next = head;
        head->next = NULL;

        return newHead;
    }

    bool isPalindrome(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* newhead = reverseLL(slow->next);

        ListNode* first = head;
        ListNode* second = newhead;

        bool ans = true;

        while(second != NULL)
        {
            if(first->val != second->val)
            {
                ans = false;
                break;
            }

            first = first->next;
            second = second->next;
        }

        
        slow->next = reverseLL(newhead);

        return ans;
    }
};