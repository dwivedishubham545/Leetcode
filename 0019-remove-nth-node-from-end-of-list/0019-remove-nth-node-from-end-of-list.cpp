class Solution {
public:
    int lengthOfLinkedList(ListNode* head) {
        int length = 0;
        ListNode* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        return length;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = head;
        int length = lengthOfLinkedList(head);
        if (length == n) {
            ListNode* temp = head->next;
            delete head;
            return temp;
        }

        current = head; 
        ListNode* dummy = new ListNode(0); 
        ListNode* temp = dummy;

        int steps = length - n;
        for (int i = 0; i < steps; i++) {
            temp->next = current;
            temp = temp->next;
            current = current->next;
        }

        ListNode* nextNode = current->next; 
        delete current;  
        temp->next = nextNode;
        return dummy->next;
    }
};