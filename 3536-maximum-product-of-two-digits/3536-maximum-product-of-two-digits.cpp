class Solution {
public:
    int maxProduct(int n) {
        int a1=0, a2=0;
        while(n>0){
            int digit=n%10;
            if(digit>=a1){
                a2=a1;
                a1=digit;
            }
            else if(digit>a2){
                a2=digit;
            }
            n/=10;
        }
        return a1*a2;
    }
};