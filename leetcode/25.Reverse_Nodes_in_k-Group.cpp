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
    ListNode* reverseKGroup(ListNode* startNode, int k) {
        ListNode* cur = startNode;
        int cnt = 0;

        while(cur != NULL && cnt < k){
            cur = cur->next;
            ++cnt;
        }

        if(cnt == k){
            cur = reverseKGroup(cur, k);

            while(cnt--){
                ListNode* tmp = startNode->next;
                startNode->next = cur;
                cur = startNode;
                startNode = tmp;

            }

            startNode = cur;
        }

        return startNode;
    }
};