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
    
    int numberOfNodes(ListNode* head){
        
        ListNode* current = head;
        int count = 0;
        while(current != NULL){
            count++;
            current = current->next;
        }
        return count;
        
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        
        int nA = numberOfNodes(headA);
        int nB = numberOfNodes(headB);
        
        //cout << nA <<" " << nB<<endl; 
        
        int m = 0;
        
        ListNode* currB = headB;
        ListNode* currA = headA;
        
        cout << currA->val <<" " << currB->val <<endl; 
        
        if(nA >= nB){
            m = nA - nB;
            while(m--){
                currA = currA->next;
            }
        }
        else{
            m = nB - nA;
            while(m--){
                currB = currB->next;
            }
        }
        
        //cout << currA->val <<" " << currB->val <<endl; 
        
        while(currA != NULL && currB != NULL){
            if(currA == currB){
                return currA;
            }
            currA = currA->next;
            currB = currB->next;
            
        }
        return currA;
        
    }
};