class Solution {
public:
    string Decimal2Binary(int n){
        string s = "";
        while(n > 0){
            s += n % 2;
            n = n/2;
        }
        return s;
    }
    int minBitFlips(int start, int goal) {
        string a = Decimal2Binary(start);
        string b = Decimal2Binary(goal);
        int size = min(a.size(), b.size());

        int count = 0;
        for(int i = 0; i<size; i++){
            if(a[i] != b[i]){
                count++;
            }
        }

        

        if(a.size() > b.size()){
            for(int i = size; i<a.size(); i++){
                if(a[i] == 1){
                    count++;
                }
            }
        }else if(b.size() > a.size()){
            for(int i = size; i<b.size(); i++){
                if(b[i] == 1){
                    count++;
                }
            }
        }

        return count;
    }
};