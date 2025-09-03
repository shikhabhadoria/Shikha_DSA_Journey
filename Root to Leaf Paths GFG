/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
    void helper(vector<vector<int>> &ans , vector<int> &temp , Node* root){
        temp.push_back(root->data);
        
        if(!root->left && !root->right){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        
        if(root->left) helper(ans , temp , root->left);
        if(root->right) helper(ans , temp , root->right);
        temp.pop_back();
        return;
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> temp;
        helper(ans , temp , root);
        return ans;
    }
};
