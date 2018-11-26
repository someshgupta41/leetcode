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
    
    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
    ListNode* result;
        
        if(l1 == NULL){
            return l2;
        }
        else if(l2 == NULL){
            return l1;
        }
        
        if(l1->val <= l2->val){
            result = l1;
            result->next = mergeTwoLists(l1->next, l2);
        }
        else{
            result = l2;
            result->next = mergeTwoLists(l1, l2->next);
        }
        
        return result;
    }
   
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size() == 0){
            return NULL;
        }
        
        while(lists.size() > 1){
            lists.push_back(mergeTwoLists(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        
        return lists[0];
        
    }
};