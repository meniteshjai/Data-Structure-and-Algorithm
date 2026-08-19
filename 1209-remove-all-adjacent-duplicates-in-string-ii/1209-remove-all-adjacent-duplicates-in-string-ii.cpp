class Solution {
public:
    string removeDuplicates(string s, int k) {
        int i=0;

        while(i+k<=s.size()){
            bool same=true;

            int j=i+1;

            while(j<i+k){
                if(s[j]!=s[i]){
                    same=false;
                    break;
                }
                j++;
            }
            if(same){
                s.erase(i,k);
                if(i>=k-1)
                    i=i-(k-1);
                else
                    i=0;
            }
            else{
                i++;
            }
        }
        return s;
    }
};