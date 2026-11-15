class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> s;
        int max_area=INT_MIN;
        int curr_area=0;
        int index=0;
        for(int i=0; i<heights.size(); i++){
            index=i;
            while(!s.empty() && heights[i]<=s.top().second){
                index=s.top().first;
                curr_area=s.top().second*(i-s.top().first);
                s.pop();
                max_area=max(max_area, curr_area);
            }
            if(s.empty() || s.top().second<heights[i]){
                s.push({index, heights[i]});
                curr_area=heights[i];
            }
        }
        int n=heights.size()-1;
        while(!s.empty()){
            int curr_area=s.top().second*(n-s.top().first+1);
            max_area=max(max_area, curr_area);
            s.pop();
        }
        return max_area;
    }
};
