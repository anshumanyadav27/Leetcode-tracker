class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int pro=1;
        int c=n;
        while(n>0){
            int a=n%10;
            n/=10;
            sum+=a;
            pro*=a;
        }
        int b=sum+pro;
        if(c%b==0){
            return true;
        }
        else{
            return false;
        }
    }
};