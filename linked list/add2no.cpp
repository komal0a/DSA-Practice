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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1=l1;
        ListNode* t2=l2;

        ListNode *dummy = new ListNode(); 
        ListNode *temp = dummy; 
        int carry=0;
        while(t1 || t2 ||carry){
           int sum=0;
           if (t1) {
                sum += t1->val;
                t1 = t1->next;  // ✅ Advance the pointer
            }
            if (t2) {
                sum += t2->val;
                t2 = t2->next;  // ✅ Advance the pointer
            }
            sum+=carry;
             carry = sum / 10; 
            ListNode *node = new ListNode(sum % 10); 
            temp->next=node;
            temp=temp->next;
            
        }
        return dummy->next;
    }   
};