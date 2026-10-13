class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
        int j=heights.size()-1;
        int maximum=0;
        while(i<j){
            int l=min(heights[i], heights[j]);
            int curr=(l*(j-i));
            maximum=max(curr, maximum);
            if(heights[i]<heights[j]){
                i++;
            }else{
                j--;
            }
        }
        return maximum;
    }
};
