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
    int findLengthOfLoop(ListNode *head) {
            if(head == nullptr || head->next == nullptr) return 0;
        ListNode* fast= head;
        ListNode* slow= head;
        int cnt=1;
        while(fast!= nullptr && fast->next != nullptr){
        slow= slow->next;
            fast = fast->next->next;
        if(slow == fast){
            fast=fast->next;
        while (slow != fast) {
            cnt++;
            fast = fast->next;
        }
        return cnt;
        }
        }
        return 0;
        
    }
};