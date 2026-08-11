class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>ans(26,0);
        for(int i=0;i<sentence.size();i++){
            ans[sentence[i]-'a']++;
        }
        bool sol=true;
        for(int i=0;i<26;i++){
            if(ans[i]==0){
                sol=false;
            }
        }
    return sol;
    }
};