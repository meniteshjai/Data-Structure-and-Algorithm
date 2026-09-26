class Solution {
public:

    vector<int>nextSmaller(vector<int>&v){
        stack<int>st;
        st.push(-1);
        vector<int>ans(v.size(),-1);
        for(int i=v.size()-1;i>=0;i--){
            while(st.top()!=-1 && v[st.top()]>=v[i]){
                    st.pop();    
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>prevSmaller(vector<int>&v){
        stack<int>st;
        st.push(-1);
        vector<int>ans(v.size(),-1);
        for(int i=0;i<v.size();i++){
            while(st.top()!= -1 && v[st.top()]>v[i]){
                    st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }   
    int sumSubarrayMins(vector<int>& arr) {
        auto next=nextSmaller(arr);
        auto prev=prevSmaller(arr);
        long long sum=0;
        const int mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            int nexti=next[i]==-1 ? arr.size() : next[i];
            int previ=prev[i];
            long long left=i-previ;
            long long right=nexti-i;
            long long number=(left*right)%mod;
            long long total=(number * arr[i])%mod;
            sum=(sum + total)%mod;
        }
        return sum;
    }
};