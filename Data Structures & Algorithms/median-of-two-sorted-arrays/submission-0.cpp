class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        int m=nums1.size();
        int n=nums2.size();
        int l=0; int h=m;
        while(l<=h){
            int partA=l+(h-l)/2;
            int partB=(m+n+1)/2-partA;
            int minA=(partA==0)?INT_MIN:nums1[partA-1];
            int maxA=(partA==m)?INT_MAX:nums1[partA];
            int minB=(partB==0)?INT_MIN:nums2[partB-1];
            int maxB=(partB==n)?INT_MAX:nums2[partB];
            if(minA<=maxB && minB<=maxA){
                if((m+n)%2!=0){
                    return max(minA, minB);
                }else{
                    return (max(minA, minB)+min(maxA, maxB))/2.0;
                }
            }else if(minA>maxB){
                h=partA-1;
            }else{
                l=partA+1;
            }
        }
        return 0.0;
    }
};
