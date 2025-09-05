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
    bool helper(TreeNode* root , TreeNode* n , vector<TreeNode*> &path){
        if(!root){
            return false;
        }
        path.push_back(root);
        if(root == n){
            return true;
        }
        if(helper(root->left , n , path) || helper(root->right , n , path)){
            return true;
        }
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pans;
        vector<TreeNode*> qans;

        helper(root , p , pans);
        helper(root , q , qans);

        int i = 0;
        TreeNode* ans = nullptr;
        while(i < pans.size() && i < qans.size() && pans[i] == qans[i]){
            ans = pans[i];
            i++;
        }
        return ans;
    }
};