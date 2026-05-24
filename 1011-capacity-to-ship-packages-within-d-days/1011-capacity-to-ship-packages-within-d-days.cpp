class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        long long high = 0;
        for(int i = 0; i<weights.size(); i++){
            high += weights[i];
        }

        while(low <= high){
            int mid = low + (high - low)/2;
            int ans = 0;
            int D = 1;
            for(int i = 0; i<weights.size(); i++){
                ans += weights[i];
                if(ans > mid){
                    D++;
                    ans = weights[i];
                }
            }
            if(D <= days){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};