class Solution {
public:
  void find(vector<int>& nums, int index, int n, int k, int& count){
        if(index==n){
            return;
        }
        int sum=0;
        for(int i=index; i<n; i++){
            sum+=nums[i];
            if(sum==k){
                count++;
            }
        }
        find(nums,index+1,n,k,count);
    }
    int subarraySum(vector<int>& nums, int k) {
        int index=0;
        int n=nums.size();
        int count=0;
        find(nums,index,n,k,count);
        return count;
    }
};