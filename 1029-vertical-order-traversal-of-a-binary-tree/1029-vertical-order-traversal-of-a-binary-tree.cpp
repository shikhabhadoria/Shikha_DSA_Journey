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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode* , pair<int , int>>> Q;
        map<int , multiset<pair<int , int>>> mp;
        if(root) Q.push({root , pair{0 , 0}});
       
        while(!Q.empty()){
            int size = Q.size();
            for(int i = 0; i<size; i++){
                auto temp = Q.front().first;
                int x = Q.front().second.first;
                int y = Q.front().second.second;
                Q.pop();
                if(temp->left){
                    Q.push({temp->left , {x+1 , y-1}});
                }
                if(temp->right){
                    Q.push({temp->right , {x+1 , y+1}});
                }
                mp[y].insert({x , temp->val});
            }
        }
        for(auto &[y , vals] : mp) {
            vector<int> temp;
            for(auto &[x , val] : vals) {
                temp.push_back(val);  
            }
            ans.push_back(temp);
        }

        return ans; 

    }
};