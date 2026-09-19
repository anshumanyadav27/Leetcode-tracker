class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> arr3;
        for(int i=0; i<nums1.size(); i++){
        arr3.push_back(nums1[i]);
        }
        for(int j=0; j<nums2.size(); j++){
        arr3.push_back(nums2[j]);
        }
        sort(arr3.begin(), arr3.end());
        double answer;
        int c=arr3.size()/2;
        if(arr3.size()%2==0){
            answer=(arr3[c]+arr3[c-1])/2;
        }
        else{
            answer=arr3[c];
        }
        return answer;
    }
};