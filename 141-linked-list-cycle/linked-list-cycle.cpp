class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast) return true;
        }
        return false;      
    }
};