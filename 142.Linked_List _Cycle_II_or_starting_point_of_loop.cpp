class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
// method 1 : using hash mapping
        // map<ListNode*, int> mpp;

        // ListNode *temp = head;

        // while(temp != NULL)
        // {
        //     if(mpp.find(temp) != mpp.end())
        //         return temp;

        //     mpp[temp] = 1;
        //     temp = temp->next;
        // }

        // return NULL;


 //method2 :
 // 1) use slow and fast move them 1 and 2 step respectively and get the collision point  .
// 2) again point slow to head and fast at collision point , move them 1-1 step simultaneously
//and point of collision is starting point of loop
 if( head == NULL || head->next == NULL ) return NULL;
      struct  ListNode *slow =   head;
       struct ListNode *fast = head;

     while(fast != NULL && fast->next != NULL)
        {
                slow = slow->next;
                fast= fast->next->next;
            
                      if(slow == fast) 
            {
                slow = head;
                while(slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow ;
            
            }
        }

        return NULL;

    }
};