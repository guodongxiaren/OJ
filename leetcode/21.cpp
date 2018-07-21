/**
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        ListNode* base = (l1->val < l2->val)?l1:l2;
        ListNode* other = (base == l1)?l2:l1;
        
        ListNode* n1 = base;
        ListNode* n2 = other;
        ListNode* pre = NULL;

        while (n1 && n2) {
            
            if (n1->val <= n2->val) {
                pre = n1;
                n1 = n1->next;
            } else {
                ListNode* tmp = n2->next;
                pre->next = n2;
                n2->next = n1;
                pre = n2;
                n2 = tmp;
            }
        }
      
        if (n2) {
            pre->next = n2;
        }
        return base;
    }
};
