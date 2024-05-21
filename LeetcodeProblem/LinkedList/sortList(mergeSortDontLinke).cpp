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
    ListNode* sortList(ListNode* head) {
        if (head==nullptr||head->next==nullptr) return head;
        ListNode *prev=nullptr,*slow=head,*fast=head;
        while(fast!=nullptr&&fast->next!=nullptr) {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=nullptr;
        ListNode *l1=sortList(head);
        ListNode *l2=sortList(slow);
        return merge(l1,l2);
    }
    ListNode *merge(ListNode *l1,ListNode *l2) {
        ListNode *l=new ListNode(),*p=l;
        while(l1!=nullptr&&l2!=nullptr) {
            if (l1->val<l2->val) {
                p->next=l1;
                l1=l1->next;
            } else {
                p->next=l2;
                l2=l2->next;
            }
            p=p->next;
        }
        if (l1!=nullptr) p->next=l1;
        if (l2!=nullptr) p->next=l2;
        return l->next;
    }
};
