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
    int helper(ListNode* temp){
        if(temp==nullptr)return 1;

        int carry=helper(temp->next);

        int sum = temp->val + carry;
        temp->val = sum % 10;
        return sum / 10;
        
    }
    ListNode *addOne(ListNode *head) {
       int carry=helper(head);

        if(carry==1){
            ListNode* newnode= new ListNode(1);
            newnode->next=head;
            return newnode;
        }
        return head;
    }
};