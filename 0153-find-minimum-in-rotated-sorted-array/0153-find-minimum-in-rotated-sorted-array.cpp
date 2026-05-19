class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[low] < nums[mid] && nums[mid] < nums[high]){
                high = mid - 1;
            }else if(nums[low] > nums[mid] && nums[mid] > nums[high]){
                low = mid + 1;
            }else if(nums[low] < nums[mid] && nums[mid] > nums[high]){
                low = mid + 1;
            }else{
               if(nums[low] ==  nums[high]){
                    return nums[mid];
               }else if(nums[low] == nums[mid] || nums[mid] == nums[high]){
                    if(nums[low] > nums[high]){
                        return nums[high];
                    }else if(nums[low] < nums[high]){
                        return nums[low];
                    }
               }else if(mid - 1 >= low && nums[mid - 1] > nums[mid]){
                    return nums[mid];
               }else if(mid - 1 >= low && nums[mid - 1] < nums[mid]){
                    high = mid - 1;
               }
            }
        }
        return -1;
    }
};