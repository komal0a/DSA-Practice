class Solution {
public:
    bool searchKey(ListNode* head, int key) {
        // Your code goes here
        if(head==nullptr)return false;
        while(head->next!=nullptr){
            if(head->val==key)return true;
            head=head->next;
        }
        return false;
    }
};