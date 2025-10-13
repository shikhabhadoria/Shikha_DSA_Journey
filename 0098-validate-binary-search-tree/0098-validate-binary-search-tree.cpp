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
    bool isValidBST(TreeNode* root) {
        return validate(root , LLONG_MIN , LLONG_MAX);
    }

    bool validate(TreeNode* root , long long minvalue , long long maxvalue){
        if(root == nullptr) return true;
        if(root->val >= maxvalue || root->val <= minvalue){
            return false;
        }

        return validate(root->left , minvalue , root->val) &&
            validate(root->right , root->val , maxvalue);
    }
};