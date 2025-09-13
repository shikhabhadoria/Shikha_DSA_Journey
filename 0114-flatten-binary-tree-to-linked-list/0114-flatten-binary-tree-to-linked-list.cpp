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
    void flattenhelper(TreeNode* root , vector<TreeNode*> &preOrder){
        if(!root) return;
        preOrder.push_back(root);
        flattenhelper(root->left , preOrder);
        flattenhelper(root->right , preOrder);
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        vector<TreeNode*> preOrder;
        flattenhelper(root , preOrder);
        int len = preOrder.size()-1;
        for(int i = 0; i<len; i++){
            preOrder[i]->right = preOrder[i+1];
            preOrder[i]->left = nullptr;
        }

    }
};