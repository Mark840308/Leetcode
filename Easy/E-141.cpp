/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        auto r1 = head, r2 = head;
        while(true){
            if(r2->next == NULL)
                return false;
            else if(r2->next->next == NULL)
                return false;
            r2 = r2->next->next;
            r1 = r1->next;
            if(r2 == r1)
                return true;
        }
    }
};