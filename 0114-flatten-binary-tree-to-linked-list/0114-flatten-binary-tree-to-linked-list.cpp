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
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* node = root;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        if(root->left) s1.push(root->left);
        if(root->right) s2.push(root->right);
        node->left = nullptr;
        node->right = nullptr;

        while(!s1.empty()){
            int size = s1.size();
            for(int i = 0; i<size; i++){
                TreeNode* temp = s1.top();
                s1.pop();
                node->right = temp;
                node->left = nullptr;
                node = node->right;

                if(temp->left){
                    s1.push(temp->left);
                }
                if(temp->right){
                    s2.push(temp->right);
                }
            }
        }

        while(!s2.empty()){
            int size = s2.size();
            for(int i = 0; i<size; i++){
                TreeNode* temp = s2.top();
                s2.pop();
                node->right = temp;
                node->left = nullptr;
                node = node->right;

                if(temp->right){
                    s2.push(temp->right);
                }
                if(temp->left){
                    s2.push(temp->left);
                }
            }
        }

    }
};