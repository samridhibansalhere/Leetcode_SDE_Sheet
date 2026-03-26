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
ListNode* reverse(ListNode* head) {
    if(head==nullptr || head->next==nullptr) return head;
    ListNode* newhead=reverse(head->next);
    ListNode* front=head->next;
    front->next=head;
    head->next=nullptr;
    return newhead;
}
    ListNode* find(ListNode* temp,int k)
    {
        while(temp!=nullptr && k>0)
        {
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev=nullptr;
        ListNode* temp=head;
        while(temp!=nullptr){
            ListNode* kth=find(temp,k-1);
            if(kth==nullptr){
                if(prev)prev->next=temp;
                break;
            }
            ListNode* next=kth->next;
            kth->next=nullptr;
            ListNode* newhead=reverse(temp);
            if(prev==nullptr) head=newhead;
            else prev->next=newhead;
            prev=temp;
            temp=next;
        }
        return head;
    }
};