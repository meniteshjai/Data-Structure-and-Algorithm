class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            int count=0;
            string s=bank[i];
            for(int j=0;j<s.size();j++){
                if(s[j]=='1'){
                    count++;
                }
            }
            ans.push_back(count);
        }
        
        int prev=0;
        int res=0;
        
        for(int i=0;i<ans.size();i++){
            if(ans[i] !=0){
                res=res+prev*ans[i];
                prev=ans[i];
            }
        }
    return res;
    }
};