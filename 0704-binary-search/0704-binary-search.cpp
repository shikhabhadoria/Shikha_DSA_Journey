class Solution {
public:

    int bs(vector<int>&nums, int low, int high, int target){
        
        while(low <= high){
            int mid = (low + high)/2;
            if(target < nums[mid]){
                return bs(nums, low, mid-1, target);
            }else if(target > nums[mid]){
                return bs(nums, mid+1, high, target);
            }else{
                return mid;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int result = bs(nums, low, high, target);
        return result;
    }
};