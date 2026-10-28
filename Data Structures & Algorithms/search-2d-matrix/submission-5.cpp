class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int selected_row=-1;
        if (matrix.empty() || matrix[0].empty()) return false;
        int i=0; int j=matrix.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(matrix[mid][0]<=target && target<=matrix[mid][matrix[mid].size()-1]){
                selected_row=mid;;
                break;
            }else if(matrix[mid][0]>target){
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        if(selected_row==-1){
            return false;
        }
        bool ans=false;
        int l=0; int h=matrix[0].size()-1;
        while(l<=h){
            int middle=l+(h-l)/2;
            if(matrix[selected_row][middle]==target){
                ans=true;
                break;
            }else if(matrix[selected_row][middle]<target){
                l=middle+1;
            }else{
                h=middle-1;
            }
        }
        return ans;
    }
};
