// https://leetcode.com/problems/linked-list-random-node/description/

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
private:
    int N = 0;
    ListNode* h;
public:
    Solution(ListNode* head) {
        h = head;
        auto p = h;
        while(p) {
           ++N; 
           p = p->next;
        }
    }
    
    int getRandom() {
        auto p = h;
        auto r = rand() % N, i = 0;
        while(p) {
            if(i == r) return p->val;
            ++i, p = p->next;
        }
        return p->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */