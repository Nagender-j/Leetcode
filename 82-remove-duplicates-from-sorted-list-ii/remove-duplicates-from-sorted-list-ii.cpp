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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* node = head;
        int cnt = 0;
        while(node != NULL && node->val == head->val) {
            node = node->next;
            cnt++;
        }

        if(cnt == 1) {
            head->next = deleteDuplicates(node);
            return head;
        }
        
        return deleteDuplicates(node);
    }
};