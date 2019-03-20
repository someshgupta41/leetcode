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
    
    void path1(TreeNode* root, int sum , vector<int>& path, vector<vector<int>>& paths){
        
        if(root == NULL){
            return ;
        }
        
        path.push_back(root->val);
        
        if(root->left  == NULL && root->right == NULL && root->val == sum){
            paths.push_back(path);
        }
        
        path1(root->left,sum - root->val, path,paths);
        path1(root->right, sum - root->val, path, paths);
        
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int>> paths;
        vector<int> path;
        
        path1(root, sum, path, paths);
        return paths;
    }
};