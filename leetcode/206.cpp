/**
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* pre = NULL;
        ListNode* node = head;
    
        while (node) {
            ListNode* tmp = node->next;
            node->next = pre;
            pre = node;
            node = tmp;
        }
        return pre;
    }
};
