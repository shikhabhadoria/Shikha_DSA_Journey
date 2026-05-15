class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int low = 0;
        int high = nums.size()-1;

        while(low <= high){
            int mid = high + (low - high)/2;

            if(nums[mid] == target){
              int s = mid;
              int e = mid;
              while(s >= low && nums[s] == target){
                s--;
              }
              while(e <= high && nums[e] == target){
                e++;
              }
              ans[0] = s+1;
              ans[1] = e-1;
              return ans;
            }else if(nums[mid] < target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};