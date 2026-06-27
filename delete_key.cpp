#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

// Insert at end
void insertAtEnd(Node* &head, int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Delete all occurrences of key
Node* deleteKey(Node* &head, int key) {
    Node* temp = head;

    while (temp != nullptr)
    {
        Node* nextNode = temp->next;

        if (temp->data == key)
        {
            if (temp->prev != NULL && temp->next != NULL)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            else
            {
                
                if (temp->prev == nullptr)
                {
                    head = temp->next;

                    if (temp->next != nullptr)
                        temp->next->prev = nullptr;
                }
              
                else if (temp->next == nullptr)
                {
                    temp->prev->next = nullptr; 
                }
            }

            delete temp;
        }

        temp = nextNode;
    }

    return head;
}

// Display DLL
void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL)
            cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    int arr[] = {4, 5, 5, 6, 5, 5, 1, 5, 30, 14, 5, 5};

    for (int x : arr) {
        insertAtEnd(head, x);
    }

    cout << "Original List:\n";
    display(head);

    cout<<"Enter key vlue\n";
    int key;
    cin>>key;
    deleteKey(head, key);

    cout << "\nAfter deleting 10:\n";
    display(head);

    return 0;
}