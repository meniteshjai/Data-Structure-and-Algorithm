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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<vector<int>>ans1;
        permutation(ans,nums,0);
        sort(ans.begin(),ans.end());
        
        ans1.push_back(ans[0]);
        int i=1;
        while(i<ans.size()){
           if(ans1.back()!=ans[i]){
            ans1.push_back(ans[i]);
           }
           i++;
        }
        return ans1;
    }
};