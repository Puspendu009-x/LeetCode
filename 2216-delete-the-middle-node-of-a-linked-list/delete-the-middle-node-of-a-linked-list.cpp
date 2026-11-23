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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;

        ListNode* temp=head;
        ListNode* slow=head;
        ListNode* prev=NULL;

        while(temp!=NULL && temp->next!=NULL){
            temp=temp->next->next;
            prev=slow;
            slow=slow->next;
        }

        prev->next=slow->next;
        delete(slow);
        return head;
    }
};