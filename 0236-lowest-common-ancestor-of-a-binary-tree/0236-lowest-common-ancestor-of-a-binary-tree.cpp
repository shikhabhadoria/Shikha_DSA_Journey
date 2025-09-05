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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode* , TreeNode*> parent;
        parent[root] = nullptr;
        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()){
            TreeNode* node = s.top();
            s.pop();

            if(node->left){
                parent[node->left] = node;
                s.push(node->left);
            }

            if(node->right){
                parent[node->right] = node;
                s.push(node->right);
            }
        }

        unordered_set<TreeNode*> ancestor;

        while(p){
            ancestor.insert(p);
            p = parent[p];
        }

        while(ancestor.find(q) == ancestor.end()){
            q = parent[q];
        }

        return q;

    }
};