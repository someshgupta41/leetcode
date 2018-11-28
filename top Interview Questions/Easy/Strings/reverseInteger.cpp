class Solution {
public:
    int reverse(int x) {
        
        long long n = x;
        long long sum = 0;
        bool found = false;
         if(x<0)
    {
        found = 1;
        n=-x;
    }
        while(n!=0){
             if(sum > (INT_MAX/10) || sum < (INT_MIN/10))
        return 0;
            int t = n % 10;
            sum = sum * 10 + t;
            n = n / 10;
            
        }
        if(found == 1)
    return (sum*(-1));
    else return sum;
        
    }
};