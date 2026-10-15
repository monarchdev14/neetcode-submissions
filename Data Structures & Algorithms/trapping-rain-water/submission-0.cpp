class Solution {
public:
    int trap(vector<int>& height) {
        int ref=INT_MIN;
        vector<int> left_max;
        vector<int> right_max;
        for(int i=0; i<height.size(); i++){
            left_max.push_back(max(ref, height[i]));
            ref=left_max.back();
        }
        ref=INT_MIN;
        for(int i=height.size()-1; i>=0; i--){
            right_max.push_back(max(ref, height[i]));
            ref=right_max.back();
        }
        reverse(right_max.begin(), right_max.end());
        int ans=0;
        for(int i=0; i<height.size(); i++){
            ans+=((min(left_max[i], right_max[i]))-height[i]);
        }
        return ans;
    }
};
