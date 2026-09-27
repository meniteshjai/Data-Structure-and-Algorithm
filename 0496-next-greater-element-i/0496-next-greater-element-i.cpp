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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>ans;
        auto req=nextGreater(nums2);
        for(int i=0;i<n;i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(req[j]);
                    break;
                }
            }
        }
        return ans;
    }
};