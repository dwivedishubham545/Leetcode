class Solution {
public:
    bool hasCycle(ListNode *head) {
         if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode* tortoise = head;
        ListNode* hare = head->next;

        while (hare != nullptr && hare->next != nullptr) {
            if (tortoise == hare) {
                return true;
            }
            tortoise = tortoise->next;
            hare = hare->next->next; 
        }
        return false;
    }
};