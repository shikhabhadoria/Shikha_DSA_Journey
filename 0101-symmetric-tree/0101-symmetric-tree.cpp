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
    bool isSymmetric(TreeNode* root) {
        queue<pair<int , TreeNode*>> q1;
        queue<pair<int , TreeNode*>> q2;
        if(root->left) q1.push({0 , root->left});
        if(root->right) q2.push({0 , root->right});

        while(!q1.empty() || !q2.empty()){
            int size1 = q1.size();
            int size2 = q2.size();

            if(size1 != size2){
                return false;
            }
            
            for(int i = 0; i<size1; i++){
                TreeNode* temp1 = q1.front().second;
                int lx = q1.front().first;
                q1.pop();
                TreeNode* temp2 = q2.front().second;
                int ly = q2.front().first;
                q2.pop();

                if(temp1->val == temp2->val && lx == ly){
                    if(temp1->left) q1.push({lx-1 , temp1->left});
                    if(temp1->right) q1.push({lx+1 , temp1->right});
                    if(temp2->right) q2.push({ly-1 , temp2->right});
                    if(temp2->left) q2.push({ly+1 , temp2->left});
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};