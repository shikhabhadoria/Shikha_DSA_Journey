class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = high + (low - high)/2;
            if(nums[mid] == target){
                return true;
            }else if(nums[low] == nums[mid] || nums[mid] == nums[high]){
                if(nums[low] == nums[mid]){
                    int s = low;
                    while(s <= mid){
                        if(nums[s] == target){
                            return true;
                        }
                        s++;
                    }
                    low = mid + 1;
                }
                if(nums[mid] == nums[high]){
                    int e = mid;
                    while(e <= high){
                        if(nums[e] == target){
                            return true;
                        }
                        e++;
                    }
                    high = mid - 1;
                }
                
            }
            else{
                if(nums[low] < nums[mid]){
                    if(nums[low] <= target && nums[mid] >= target){
                        high = mid - 1;
                    }else{
                        low = mid + 1;
                    }
                }else{
                    if(nums[mid] <= target && nums[high] >= target){
                        low = mid + 1;
                    }else{
                        high = mid - 1;
                    }
                }
            }
            
        }
        return false;
    }
};