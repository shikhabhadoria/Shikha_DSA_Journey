class Solution {
public:
    int divide(int dividend, int divisor) {

        if(dividend == divisor) return 1;
        
        bool sign = true;

        if(dividend < 0 && divisor > 0){
            sign = false;
        }
        if(dividend > 0 && divisor < 0){
            sign = false;
        }

        int ct = 0;
        
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long ans = 0;
        
        while(d <= n){
            ct = 0;
            while((d << ct) <= n){
                ct++;
            }
            n -= (d << (ct-1));
            ans += (1L << (ct-1));
        }

        if(sign==true && ans > INT_MAX){
            return INT_MAX;
        }
        if(sign==false && ans > INT_MAX){
            return INT_MIN;
        }

        return sign ? (int)ans : (int)(-1*ans);
    }
};