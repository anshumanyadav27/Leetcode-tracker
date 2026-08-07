class Solution {
public:
    int addDigits(int n) {
        if(n==0){
            return 0;
        }
        while(n>9){
            int a=n%10;
            int b=n/10;
            n=a+b;
        }
        return n;
    }
};