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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ans = head;
        if(head == NULL)
            return head;
        while(head != NULL && head -> next != NULL)
        {
            if(head -> next -> val == val)
            {
                head -> next = head->next->next;
            }
            else
            {
                head = head->next;
            }
        }
        // while(ans!=NULL)
        // {
        //     cout <<  ans->val<<endl;
        //     ans = ans->next;
        // }
        if(ans->val == val)
        {
            ans = ans->next;
        }
        return ans;
    }
};