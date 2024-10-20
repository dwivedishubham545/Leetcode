class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head==NULL) return NULL;
        ListNode* cur=head, *Next, *prev=NULL;
        while(cur!=NULL){
            Next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=Next;
        }
        return prev;
    }
};