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
    void inorder(TreeNode* root , vector<int> &vec){
        if(!root){
            return;
        }
        inorder(root->left , vec);
        vec.push_back(root->val);
        inorder(root->right , vec);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root){
            return 0;
        }
        vector<int> vec;
        inorder(root , vec);
        int ans = vec[k-1];
        return ans;
    }
};