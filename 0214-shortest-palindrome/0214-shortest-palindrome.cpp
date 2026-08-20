class Solution {
public:
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        int size=s.size();
        s+='$';
        s+=rev;
        int n=s.size();
        vector<int>lps(n,0);
        int pre=0;
        int suff=1;
        while(suff<s.size()){
            if(s[pre]==s[suff]){
                lps[suff]=pre+1;
                pre++;
                suff++;
            }
            else{
                if(pre==0)
                    suff++;
                else
                    pre=lps[pre-1];
            }
        }
        string ans="";
        for(int i=size-1;i>=lps[n-1];i--){
            ans+=s[i];
        }
        return ans+s.substr(0,size);
    }
};
