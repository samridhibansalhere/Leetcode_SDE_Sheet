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
    ListNode* find(ListNode* temp,int k)
    {
        while(temp!=nullptr && k>0)
        {
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        int l=1;
        ListNode* tail=head;
        while(tail->next)
        {
            l++;
            tail=tail->next;
        }
        k=k%l;
        if(k==0) return head;
        tail->next=head;
        ListNode* last=find(head,l-k-1);
        head=last->next;
        last->next=nullptr;
        return head;
    }
};