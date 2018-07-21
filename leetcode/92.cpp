/**
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/ 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n || !head || !head->next) {
            return head;
        }

        ListNode* pre = NULL;
        ListNode* post = NULL;
        ListNode* node = head;
        int i = 0;
        while (node) {
            ++i;
            if (i == n+1) {
                post = node;
            }
            if (i == m-1) {
                pre = node;
            }
            node = node->next;
        }
        

        ListNode* pre0 = post;
        node = (!pre)?head:pre->next;

        while (node != post) {
            ListNode* tmp = node->next;
            node->next = pre0;
            pre0 = node;
            node = tmp;
        }
        if (pre) {
            pre->next = pre0;
            return head;
        }
        
        return pre0;
        
    }


};
