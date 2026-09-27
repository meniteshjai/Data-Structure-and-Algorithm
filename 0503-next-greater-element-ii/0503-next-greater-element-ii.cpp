class Solution {
public:
        vector<int>nextGreater(vector<int>& nums2){
        stack<int>st;
        st.push(-1);
        int n=nums2.size();
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            int element=nums2[i];
            while(!st.empty() && st.top()<=element){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
            st.push(element);
        }
        return ans;
    }
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>nums1=nums;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            nums1.push_back(nums[i]);
        }
        auto arr=nextGreater(nums1);
        for(int i=0;i<nums.size();i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};