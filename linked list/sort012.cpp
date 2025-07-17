/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode *sortList(ListNode *head) {
          ListNode* zerohead=new ListNode(0);
        ListNode* onehead=new ListNode(0);
         ListNode* twohead=new ListNode(0);
             ListNode* a=zerohead;
           ListNode* b=onehead;
            ListNode* c=twohead;
            ListNode* temp=head;

             while(temp){
                if(temp->val==0){
                    a->next=temp;
                    a=a->next;
                }else  if(temp->val==1){
                    b->next=temp;
                    b=b->next;
                }else {
                    c->next=temp;
                    c=c->next;
                }
                temp=temp->next;
             }
             a->next=onehead->next;
             b->next=twohead->next;
             c->next=nullptr;
             return zerohead->next;
    }
};