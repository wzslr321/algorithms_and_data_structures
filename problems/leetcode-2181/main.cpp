// https://leetcode.com/problems/merge-nodes-in-between-zeros/description/

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* h = nullptr;
        ListNode* ans = nullptr;
        auto sum = 0;
        head=head->next;
        while(head) {
            if(head->val == 0) {
                auto node = new ListNode(sum);
                if(!h) {
                    h = node;
                    ans = h;
                }
                else {
                    h->next = node;
                    h = h->next;
                }
                sum = 0;
            }
            sum += head->val;
            head = head->next;
        }
        return ans;
    }
};