class Solution {
public:
    int heightChecker(vector<int>& a) {
    int n=a.size();
    vector<int> c(n);
    for(int i=0; i<n; i++){
        c[i]=a[i];
    }
    sort(c.begin(), c.end());
    int count=0;
    for(int i=0; i<n; i++){
        if(a[i]!=c[i]){
            count++;
        }
    }
    return count;
    }
};