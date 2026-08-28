class Solution {
public:

     void solve(vector<int>& nums,int index,vector<int>output,vector<vector<int>>&ans){
        if(index>=nums.size()){
            ans.push_back(output);
            return ;
        }
        int n=nums[index];
        // include
        output.push_back(n);
        solve(nums,index+1,output,ans);
        //exclude
        output.pop_back();
        solve(nums,index+1,output,ans);

    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>output;
        vector<vector<int>>ans;
        vector<vector<int>>ans1;
        int index=0;

        sort(nums.begin(), nums.end());
        
        solve(nums,index,output,ans);
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