/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        
        unordered_set<int> s;
        
        return dfs(root, s, k);
        
    }
    
    bool dfs(TreeNode* root, unordered_set<int>& s ,int k){
        
        if(root == NULL){
            return false;
        }
        
        if(s.count(k - root->val)){
            return true;
        }
        s.insert(root->val);
        
            return dfs(root->left, s, k) || dfs(root->right, s , k);
        
    }
    
};