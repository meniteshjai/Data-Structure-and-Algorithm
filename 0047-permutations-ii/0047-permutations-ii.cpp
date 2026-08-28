class Solution {
public:
    void permutation(set<vector<int>>&ans,vector<int>& nums,int i){
        if(i>=nums.size()){
            ans.insert(nums);
            return ;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            permutation(ans,nums,i+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>ans;
        permutation(ans,nums,0);
        vector<vector<int>>ans1(ans.begin(),ans.end());
        return ans1;
    }
};