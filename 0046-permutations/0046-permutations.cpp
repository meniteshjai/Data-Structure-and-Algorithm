class Solution {
public:
    void permutation(vector<vector<int>>&ans,vector<int>& nums,int i){
        if(i>=nums.size()){
            ans.push_back(nums);
            return ;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            permutation(ans,nums,i+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int i=0;
        permutation(ans,nums,i);
        return ans;
    }
};