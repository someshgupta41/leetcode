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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> result;
        
        if(root == NULL){
            return result;
        }
        
        stack<TreeNode*> st;
        
        while(true){
            if(root != NULL){
                st.push(root);
                root = root->left;
            }
            else{
                if(st.empty()){
                    break;
                }
                root = st.top();
                result.push_back(root->val);
                st.pop();
                root = root->right;
            }
        }
        
        return result;
        
    }
};