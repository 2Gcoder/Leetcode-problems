class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == NULL)
            return NULL;

        Node* temp = head;

        // Insert copy nodes Between original nodes
        while(temp != NULL){
            Node* copynode = new Node(temp->val);
            copynode->next = temp->next;
            temp->next = copynode;

            temp = temp->next->next;
        }

        // Assign random pointers
        temp = head;

        while(temp != NULL){
            Node* copynode = temp->next;

            if(temp->random != NULL)
                copynode->random = temp->random->next;
            else
                copynode->random = NULL;

            temp = temp->next->next;
        }

        // Separate original and copied list
        Node* dummy = new Node(-1);
        Node* res = dummy;
        temp = head;

        while(temp != NULL){
            res->next = temp->next;

            temp->next = temp->next->next;

            res = res->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};