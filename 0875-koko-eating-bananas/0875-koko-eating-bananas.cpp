class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;
        for(int i = 0; i<piles.size(); i++){
            maxi = max(piles[i] , maxi);
        }

        int low = 1;
        int high = maxi;
        while(low <= high){
            int k = low + (high - low)/2;
            long long timer = 0;
            int buffer = 0;
            for(int i = 0; i<piles.size(); i++){
                int element = piles[i];
                
                if(element >= k){
                    timer += element / k;
                }

                if(element % k != 0){
                    timer++;
                }
                
            }

            if(timer <= h){
                high = k - 1;
            }else{
                low = k + 1;
            }
        }
        return low;
    }
};