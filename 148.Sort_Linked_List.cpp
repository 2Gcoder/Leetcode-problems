class Solution {
public:
// METHOD 1 
    ListNode* Finding_middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;//initialize fast with next because we want slow at 1st middle , so that second middle will become right

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }








    ListNode* merge_LL(ListNode* left, ListNode* right) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (left != NULL && right != NULL) {
            if (left->val < right->val) {
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        if (left)
            temp->next = left;
        else
            temp->next = right;

        return dummyNode->next;
    }







    ListNode* sortList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode* middle = Finding_middle(head);

        ListNode* right = middle->next;
        ListNode* left = head;

        middle->next = NULL;

        left = sortList(left);
        right = sortList(right);

        return merge_LL(left, right);


      //  METHOD 2
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> v;

        // Store values in vector
        ListNode* temp = head;
        while (temp != nullptr) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        // Sort vector
        sort(v.begin(), v.end());

        // Put sorted values back into linked list
        temp = head;
        int i = 0;
        while (temp != nullptr) {
            temp->val = v[i++];
            temp = temp->next;
        }

        return head;
    }
};
    }
};