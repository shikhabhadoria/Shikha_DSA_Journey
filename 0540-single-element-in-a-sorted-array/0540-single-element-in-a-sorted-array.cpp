class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while(low < high){
            int mid = low + (high - low)/2;

            if(mid > 0 && mid < nums.size()-1 && nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]){
                return nums[mid];
            }else if(low < mid-1 && nums[mid - 1] == nums[mid]){
                int i = mid;
                if(((i-low)+1)%2 != 0){
                    high = i;
                }else if(((high - (i+1))+1)%2 != 0){
                    low = i+1;
                }
            }else if(mid+1 < high && nums[mid] == nums[mid + 1]){
                int i = mid + 1;
                if(((i-low)+1)%2 != 0){
                    high = i;
                }else if(((high - (i+1))+1)%2 != 0){
                    low = i+1;
                }
            }else if(mid-1 == low && mid+1 == high){
                if(nums[mid] == nums[low]){
                    return nums[high];
                }else{
                    return nums[low];
                }
            }
        }
        return nums[low];
    }
};