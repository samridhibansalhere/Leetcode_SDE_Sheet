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
    ListNode* reverseList(ListNode* head) {
        vector<int> a;
        ListNode* curr = head;
        while (head != nullptr) {
            a.push_back(head->val);
            head = head->next;
        }
        head = curr;
        int i = a.size() - 1; 
        while (curr != nullptr) {
            curr->val = a[i--];
            curr = curr->next;
        }

        return head;
    }
};
