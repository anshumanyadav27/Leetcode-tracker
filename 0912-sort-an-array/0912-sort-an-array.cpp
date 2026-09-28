class Solution {
public:
    void mergesort(vector<int>& arr, int st, int end){
        if(st==end){
        return;
        }
        else{
        int mid=st+(end-st)/2;
        mergesort(arr, st, mid);
        mergesort(arr, mid+1, end);
        merge(arr,st,mid,end);
        }
    }
    void merge(vector<int>& arr, int st, int mid, int end){
    vector<int> temp(end-st+1);
    int left=st, right=mid+1, index=0;
    while(left<=mid && right<=end){
        if(arr[left]<=arr[right]){
            temp[index]=arr[left];
            index++, left++;
        }
        else{
            temp[index]=arr[right];
            index++, right++;
        }
    }
    while(left<=mid){
        temp[index]=arr[left];
        index++, left++;
    }
    while(right<=end){
        temp[index]=arr[right];
        index++, right++;
    }
    index=0;
    while(st<=end){
        arr[st]=temp[index];
        st++;
        index++;
    }
}
    vector<int> sortArray(vector<int>& arr) {
        mergesort(arr,0,arr.size()-1);
        return arr;
    }
};