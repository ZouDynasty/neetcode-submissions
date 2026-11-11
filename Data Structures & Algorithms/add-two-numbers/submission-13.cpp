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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;

        bool carry = false;

        while (l1 || l2)
        {
            int sum = 0;
            if (carry == true)
            {
                if (!l1)
                {
                    sum = l2->val + 1;
                }
                else if (!l2)
                {
                    sum = l1->val + 1;  
                }
                else
                {
                    sum = l1->val + l2->val + 1;
                }
            }
            else
            {
                if (!l1)
                {
                    sum = l2->val;
                }
                else if (!l2)
                {
                    sum = l1->val;  
                }
                else
                {
                    sum = l1->val + l2->val;
                }
            }
            carry = false;

            if (sum > 9)
            {
                carry = true;
            }
            
            dummy->val = sum % 10;

            if (l1)
            {
                l1 = l1->next;               
            }
            if (l2)
            {
                l2 = l2->next;               
            }
            if (!l1 && !l2)
            {
                if (carry == true)
                {
                    dummy->next = new ListNode(1);
                }
                break;
            }
            dummy->next = new ListNode(0);
            dummy = dummy->next;
        }

        return head;
    }
};
