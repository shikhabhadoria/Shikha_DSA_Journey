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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<pair<TreeNode* , pair<int , int>>> Q;
        Q.push({root , {0, 0}});
        map<int , int> m;

        while(!Q.empty()){
            int size = Q.size();

            for(int i = 0; i<size; i++){
                TreeNode* temp = Q.front().first;
                int x = Q.front().second.first;
                int y = Q.front().second.second;
                Q.pop();

                if(i == size-1){
                    m[x] = temp->val;
                }

                if(temp->left){
                    Q.push({temp->left , {x+1 , y-1}});
                }
                if(temp->right){
                    Q.push({temp->right , {x+1 , y+1}});
                }
            }
        }

        for(auto &p : m){
            ans.push_back(p.second);
        }
        return ans;
    }
    
};