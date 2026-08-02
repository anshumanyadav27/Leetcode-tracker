class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0,pro=1;
        while(n>0){
            int a=n%10;
            sum+=a;
            pro*=a;
            n/=10;
        }
        return pro-sum;
    }
};