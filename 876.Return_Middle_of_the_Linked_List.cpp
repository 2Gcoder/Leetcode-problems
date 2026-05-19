class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        // 1st Approach
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* temp = head;
        int count = 0;
        while (temp != nullptr) { 
            temp = temp->next;
            count++;
        }

        count /= 2;
        temp = head;
        int n = 0;
        while (temp != nullptr) {       
            if (n == count) {
                return temp;             
            }
            n++;
            temp = temp->next;
        }
        return head;

        // 2nd approach
       
        // ListNode* slow = head;
        // ListNode* fast = head;

        // while (fast != nullptr && fast->next != nullptr) {
        //     slow = slow->next;
        //     fast = fast->next->next;
        // }
        // return slow;
        // fast move 2 step and slow move 1 step at a time . so, when fast is at end , slow is at middle 
    }
};