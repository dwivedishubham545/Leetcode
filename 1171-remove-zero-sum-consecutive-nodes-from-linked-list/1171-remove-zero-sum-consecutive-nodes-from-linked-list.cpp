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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> map;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int sum = 0;
        for(ListNode* node = dummy; node != nullptr; node = node->next) {
            sum += node->val;
            map[sum] = node;
        }
        sum = 0;
        for(ListNode* node = dummy; node != nullptr; node = node->next) {
            sum += node->val;
            node->next = map[sum]->next;  
        }
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};