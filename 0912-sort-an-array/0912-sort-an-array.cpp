class Solution {
public:

    void merge(vector<int>&nums, int start, int mid, int end){
        vector<int> temp(end-start+1);
        int left = start;
        int right = mid+1;
        int index = 0;
        while(left <= mid && right <= end){
            if(nums[left] <= nums[right]){
                temp[index] = nums[left];
                left++;
            }else{
                temp[index] = nums[right];
                right++;
            }
            index++;
        }

        while(left <= mid){
            temp[index] = nums[left];
            left++;
            index++;
        }

        while(right <= end){
            temp[index] = nums[right];
            right++;
            index++;
        }

        for(int i = 0; i<temp.size(); i++){
            nums[start + i] = temp[i];
        }
    }

    void mergesort(vector<int>&nums, int start, int end){
        if(start == end){
            return;
        }
        int mid = start + (end-start)/2;

        mergesort(nums, start, mid);
        mergesort(nums, mid+1, end);
        merge(nums, start, mid, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size()-1;
        mergesort(nums, 0, n);
        return nums;
    }
};