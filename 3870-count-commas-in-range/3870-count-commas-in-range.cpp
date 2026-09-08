class Solution {
public:
    int countCommas(int n) {
        long long commas = 0;
        long long start = 1000;
        
        while (n >= start) {
            commas += (n - start + 1);
            start *= 1000;
        }
        
        return commas;
    }
};