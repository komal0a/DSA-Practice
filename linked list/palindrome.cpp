/**linked
 * Definition for singly- list.
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
    ListNode* reverse(ListNode* head){
           ListNode* prev=nullptr;
        ListNode* cur=head;

        while(cur!=nullptr){
        ListNode* next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head== nullptr || head->next== nullptr)return true;
        ListNode* fast=head;
        ListNode* slow=head;

        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }

        //now slow is at middle, we have to reverse the next half

        ListNode* temp1= reverse(slow);
        ListNode* temp=head;
        while(temp1!=nullptr){
            if(temp1->val!=temp->val){
                return false;
            }
            temp=temp->next;
            temp1=temp1->next;
        }
        return true;
    }
};