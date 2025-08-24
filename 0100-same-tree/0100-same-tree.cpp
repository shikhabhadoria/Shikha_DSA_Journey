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
    void helper(TreeNode* p , TreeNode* q , bool &valid){
        if(!p && !q){
            return;
        }
        
        if(!p || !q){
            valid = false;
            return;
        }
        if(p->val != q->val){
            valid = false;
            return;
        }
        helper(p->left , q->left , valid);
        helper(p->right , q->right , valid);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool valid = true;
        helper(p , q , valid);
        return valid;
    }
};