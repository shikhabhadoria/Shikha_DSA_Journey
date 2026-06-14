class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        stack<int> st;
        int m = target.size();
        int index = 1;
        int j = 0;
        while(index <= n){
            if(j < m){
                if(index == target[j]){
                    st.push(index);
                    ans.push_back("Push");
                    j++;
                }else{
                    st.push(index);
                    ans.push_back("Push");
                    ans.push_back("Pop");
                    st.pop(); 
                }
                index++;
            }else{
                break;
            }
        }

        return ans;
    }
};