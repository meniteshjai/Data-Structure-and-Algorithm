class Solution {
public:
    void solve(vector<int>& nums,int index,vector<int>output,vector<vector<int>>&ans){
        if(index>=nums.size()){
            ans.push_back(output);
            return ;
        }
        int n=nums[index];
        output.push_back(n);
        solve(nums,index+1,output,ans);
        output.pop_back();
        solve(nums,index+1,output,ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>output;
        vector<vector<int>>ans;
        int index=0;
        solve(nums,index,output,ans);
        return ans;
    }
};
