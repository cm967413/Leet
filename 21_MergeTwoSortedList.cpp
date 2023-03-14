#include<bits/stdc++.h>
using namespace std;
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head1 = list1;
        ListNode *head2 = list2;
        ListNode *ans = new ListNode();
        ListNode *ans_head = ans;
        while(head1 != NULL && head2 != NULL)
        {
            if(head1->val <= head2->val)
            {
                // ListNode *tmp = new ListNode(head1->val);
                // ans->next = tmp;
                ans->next = head1;
                head1 = head1 -> next;
                ans = ans -> next;
            }
            else
            {
                // ListNode *tmp = new ListNode(head2->val);
                // ans->next = tmp;
                ans->next = head2;
                head2 = head2 -> next;
                ans = ans -> next;
            }
        }
        if(head1 != NULL)
        {
            ans->next = head1;
        }
        if(head2 != NULL)
        {
            ans->next = head2;
        }
        return ans_head->next;

    }
};


class Solution2 {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
  {
		// if list1 happen to be NULL
		// we will simply return list2.
		if(l1 == NULL)
        {
			return l2;
		}
		
		// if list2 happen to be NULL
		// we will simply return list1.
		if(l2 == NULL)
        {
			return l1;
		} 
		
		// if value pointend by l1 pointer is less than equal to value pointed by l2 pointer
		// we wall call recursively l1 -> next and whole l2 list.
		if(l1 -> val <= l2 -> val)
        {
			l1 -> next = mergeTwoLists(l1 -> next, l2);
			return l1;
		}
		// we will call recursive l1 whole list and l2 -> next
		else
        {
			l2 -> next = mergeTwoLists(l1, l2 -> next);
			return l2;            
		}
	}
};	