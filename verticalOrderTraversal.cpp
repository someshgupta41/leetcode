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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        
        if(root == NULL){
            return result;
        }
        
        map<int,vector<int>> m;
        queue<pair<int,TreeNode*>> q;
        
        q.push(make_pair(0,root));
        
        while(!q.empty()){
            
            int size = q.size();
            
            for(int i = 0 ; i < size;i++){
                TreeNode* tmp = q.front().second;
                int t = q.front().first;
                q.pop();
                m[t].push_back(tmp->val);
                if(tmp->left){
                    q.push(make_pair(t-1,tmp-> left));
                }
                if(tmp->right){
                    q.push(make_pair(t+1,tmp->right));
                }
            }
            
            
        }
        
        for(auto &item : m){
            result.push_back(item.second);
        }
        return result;
        
    }
};