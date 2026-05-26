class Solution {
public:

    bool helper(vector<int>&nums, int k , int sum){
        int falsesum = 0;
        int count = 1;
        for(int i = 0; i<nums.size(); i++){
            
            if(falsesum + nums[i] <= sum){
                falsesum += nums[i];
            }else{
                count++;
                falsesum = nums[i];
            }

            if(count > k) return false;
        }

        return true;

    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        int size = nums.size();
        for(int i = 0; i<size; i++){
            high += nums[i];
        }
        int ans = high;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(helper(nums , k , mid)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;

    }
};