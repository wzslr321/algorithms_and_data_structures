// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/

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
    int pairSum(ListNode* head) {
        queue<int> qq;
        stack<int> st;
        while(head) {
            qq.push(head->val);
            st.push(head->val);
            head = head->next;
        }
        int ans = 0;
        while(st.size()) {
            auto c1 = st.top();
            auto c2 = qq.front();
            st.pop(), qq.pop();
            ans = max(ans, c1 + c2);
        }
        
        return ans;
    }
};