class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
                // optimize code

        string ans=strs[0];
        for(int i=1;i<strs.size();i++){
            int j=0;
            while(j<ans.size() && j<strs[i].size() && ans[j]==strs[i][j]){
                j++;
            }
            ans=ans.substr(0,j);
        }
        return ans;


                // brute force

        // string ans="";
        // string s=strs[0];
        // for(int i=1;i<=s.size();i++){
        //     string sub=s.substr(0,i);

        //     bool found =true;

        //     for(int j=1;j<strs.size();j++){
        //         if(strs[j].substr(0,i) != sub){
        //             found=false;
        //             break;
        //         }
        //     }
        //     if(found){
        //         ans=sub;
        //     }
        //     else{
        //         break;
        //     }
        // }
        // return ans;
    }
};