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
    ListNode* mergeList(ListNode* left, ListNode* right){
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;

        while(left && right){
            if(left->val<=right->val){
                temp->next=left;
                left=left->next;
            }else{
                temp->next=right;
                right=right->next;
            }
            temp=temp->next;
        }

        if(left){
              temp->next=left;
        }else{
            temp->next=right;
        }

    return dummy->next;
    }
    ListNode* middleOfList(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast && fast->next){
          fast = fast->next->next;

            slow=slow->next;

        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)return head;

        ListNode* middle=middleOfList(head);
        ListNode* right=middle->next;
        middle->next=nullptr;
        ListNode* left= head;

        left=sortList(left);
        right=sortList(right);

        return mergeList(left,right);
    }
};