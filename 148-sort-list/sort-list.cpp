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
 ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* t=dummy;
        while(temp1 && temp2)
        {
            if(temp1->val<=temp2->val)
            {
                t->next=temp1;
                t=temp1;
                temp1=temp1->next;
            }
            else
            {
                t->next=temp2;
                t=temp2;
                temp2=temp2->next;
            }
        }
        while(temp1){
            t->next=temp1;
                t=temp1;
                temp1=temp1->next;
        }
         while(temp2){
            t->next=temp2;
                t=temp2;
                temp2=temp2->next;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next){slow=slow->next; fast=fast->next->next;}
        ListNode* righthead=slow->next;
        slow->next=nullptr;
        ListNode* left=sortList(head);
        ListNode* right=sortList(righthead);
        return merge(left,right);
    }
};