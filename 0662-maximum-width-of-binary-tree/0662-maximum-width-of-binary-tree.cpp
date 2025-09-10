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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* , long long>> q;
        q.push({root , 0});
        long long maxi = 0;
        while(!q.empty()){
            int size = q.size();
            long long left = q.front().second;
            long long right = left;
            for(int i = 0; i<size; i++){
                TreeNode* temp = q.front().first;
                long long n = q.front().second;
                q.pop();
                right = n;
                if(temp->left){
                    q.push({temp->left , 2*(n-left)+1});
                }
                if(temp->right){
                    q.push({temp->right , 2*(n-left)+2});
                }
              
            }
            maxi = max(maxi , (right-left)+1);
        }
        return (int)maxi;
    }
};