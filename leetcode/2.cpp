/**
 * https://leetcode.com/problems/add-two-numbers/description/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int t = 0;
        ListNode* head = NULL;
        ListNode* cur = NULL;
        while (l1 != NULL || l2 != NULL) {
            int a1 = (l1 == NULL)?0:l1->val;
            int a2 = (l2 == NULL)?0:l2->val;
            int sum = a1 + a2 + t;
            
            t = sum/10;
            ListNode* node = new ListNode(sum%10);
            if (head == NULL) {
                head = node;
                cur = head;
            } else {
                cur->next = node;
                cur = cur->next;
            }
            
            l1 = (l1 != NULL)?l1->next:l1;
            l2 = (l2 != NULL)?l2->next:l2;
        }
        if (t != 0) {
            ListNode *node = new ListNode(t);
            cur->next = node;
        }
        return head;
    }
};
