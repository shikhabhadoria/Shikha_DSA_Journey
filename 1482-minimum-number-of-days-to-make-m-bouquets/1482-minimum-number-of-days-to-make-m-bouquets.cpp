class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int size = bloomDay.size();
        
        long long t = 1LL * m * k;
        if(t > size) return -1;
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low)/2;
            int count = 0;
            int ans = 0;
            for(int i = 0; i<size; i++){
                if(bloomDay[i] <= mid){
                    count++;
                }else{
                    count = 0;
                }

                if(count == k){
                    ans++;
                    count = 0;
                }
            }
        
            if(ans >= m){
                high = mid - 1;
            }else if(ans < m){
                low = mid + 1;
            }

        }
        return low;
    }
};