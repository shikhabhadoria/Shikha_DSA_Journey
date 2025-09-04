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


//traversal approach
class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        if(!root) return ans;
        
        stack<pair<Node* , vector<int>>> s;
        s.push({root , {root->data}});
        
        while(!s.empty()){
            int size = s.size();
            for(int i = 0; i<size; i++){
                Node* temp = s.top().first;
                vector<int> curr = s.top().second;
                s.pop();
                
                if(!temp->left && !temp->right){
                    ans.push_back(curr);
                }
                
                
                if(temp->right){
                    vector<int> rv = curr;
                    rv.push_back(temp->right->data);
                    s.push({temp->right , {rv}});
                }
                
                
                if(temp->left){
                    vector<int> lv = curr;
                    lv.push_back(temp->left->data);
                    s.push({temp->left , {lv}});
                }
                
                
            }
        }
        return ans;
        
    }
};
