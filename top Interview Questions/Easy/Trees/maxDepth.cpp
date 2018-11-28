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
    
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        else{
            
            int lheight = height(root->left);
            int rheight = height(root->right);
            return 1 + max(lheight,rheight);
        }
    }
    
    int maxDepth(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        else{
            int ldepth = maxDepth(root ->left);
            int rdepth = maxDepth(root->right);
            if(ldepth > rdepth){
                return 1 + ldepth;
            }
            else{
                return 1 + rdepth; 
            }
        }
        
    }
};