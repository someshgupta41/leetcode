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
    
    bool isSameTree(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL){
            return true;
        }
        else if(root1 == NULL || root2 == NULL){
            return false;
        }
        else {
            return (root1->val == root2->val) && isSameTree(root1->left,root2->left) && isSameTree(root1->right, root2->right);
        }
    }
    
    TreeNode* mirrorTree(TreeNode* root){
        if(root == NULL){
            return NULL;
        }
        TreeNode* t = root->left;
        root->left = root->right;
        root->right = t;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
    
    bool isSymmetric(TreeNode* root) {
        
        if(root == NULL){
            return true;
        }
        
        TreeNode* left = root->left;
        TreeNode* mirrorLeft = mirrorTree(left);
        
        return isSameTree(root->right, mirrorLeft);
        
        
    }
};