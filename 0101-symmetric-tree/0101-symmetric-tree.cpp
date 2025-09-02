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
    bool helper(TreeNode* temp1 , TreeNode* temp2){
        if(!temp1 && !temp2){
            return true;
        }
        if(!temp1 || !temp2){
            return false;
        }
        return (temp1->val == temp2->val) &&
                helper(temp1->left , temp2->right) &&
                helper(temp1->right , temp2->left);

    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return helper(root->left , root->right);;
    }
};