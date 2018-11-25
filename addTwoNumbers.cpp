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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
        ListNode* dummy = new ListNode(0);
        
        ListNode* t = dummy;
        
        int c = 0;
        
        while(c || l1 || l2){
            
            c += (l1 ? l1 -> val : 0) + (l2 ? l2 ->val : 0);
            
            t->next = new ListNode(c % 10);
            t = t->next;
            
            c = c / 10;
            
            if(l1) l1 = l1->next;
            
            if(l2) l2 = l2->next;
            
        }
        return dummy->next;
    }
};