/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        if(root) s1.push(root);
        int check = 1;
        
        while(!s1.empty() || !s2.empty()){
            if(check == 1){
                int size = s1.size();
                vector<int> temp;
                for(int i = 0; i<size; i++){
                    TreeNode* curr = s1.top();
                    s1.pop();
                    temp.push_back(curr->val);
                    if(curr->left) s2.push(curr->left);
                    if(curr->right) s2.push(curr->right);
                }
                ans.push_back(temp);
                check = 2;
            }
            
            else if(check == 2){
                int size = s2.size();
                vector<int> temp;
                for(int i = 0; i<size; i++){
                    TreeNode* curr = s2.top();
                    s2.pop();
                    temp.push_back(curr->val);
                    if(curr->right) s1.push(curr->right);
                    if(curr->left) s1.push(curr->left);
                }
                ans.push_back(temp);
                check = 1;
            }
            
        }
        return ans;
    }
};