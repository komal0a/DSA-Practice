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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         ListNode* dummy = new ListNode(0, head);
        ListNode* temp=dummy;
        while(n){
            temp=temp->next;
            n--;
        }

        ListNode* sec=dummy;
        while(temp->next !=nullptr){
            sec=sec->next;
            temp=temp->next;
        }

        sec->next=sec->next->next;
        return dummy->next;
    }
};