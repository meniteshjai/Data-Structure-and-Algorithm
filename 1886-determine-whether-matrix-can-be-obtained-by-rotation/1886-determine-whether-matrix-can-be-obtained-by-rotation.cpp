class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int left=0;
        int right=row-1;
        for(int i=0;i<row;i++){
            for(int j=i+1;j<col;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        while(left<=right){
            for(int i=0;i<col;i++){
                swap(matrix[i][left],matrix[i][right]);
            }
            left++;
            right--;
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        bool ans=false;
        for(int i=0;i<4;i++){
            rotate(mat);
            if(mat==target){
                ans=true;
            }
        }
        return ans;
    }
};