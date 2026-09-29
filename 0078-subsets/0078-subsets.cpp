class Solution {
public:
void subsequence(vector<int>& arr,int index,int n, vector<vector<int>>& ans, vector<int>& temp){
    if(index==n){
        ans.push_back(temp);
        return;
    }
    else{
        subsequence(arr,index+1,n,ans,temp);
        temp.push_back(arr[index]);
        subsequence(arr,index+1,n,ans,temp);
        temp.pop_back(); 
    }
}
    vector<vector<int>> subsets(vector<int>& arr) {
    int n=arr.size();
    int index=0;
    vector<vector<int>> ans;
    vector<int> temp;
    subsequence(arr,0,n,ans,temp);
    return ans;
    }
};