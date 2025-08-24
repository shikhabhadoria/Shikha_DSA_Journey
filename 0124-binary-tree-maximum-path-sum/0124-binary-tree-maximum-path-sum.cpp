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
    int helper(TreeNode* root , int &maxi){
        if(!root){
            return 0;
        }
        int current = 0;
        int l = max(0 , helper(root->left , maxi));
        int r = max(0 , helper(root->right , maxi));
        current = l + r + root->val;
        maxi = max(maxi , current);
        return max(l , r) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(!root){
            return 0;
        }
        int maxi = INT_MIN;
        helper(root , maxi);
        return maxi;
    }
};