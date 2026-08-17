class Solution {
public:
    int repeatedStringMatch(string a, string b) {
            // optimize code
            string ans="";
            int count=0;
        while(ans.length()<b.length()){
            ans+=a;
            count++;
        }
        if(ans.find(b) !=string::npos){
            return count;
        }
        ans+=a;
        count++;

        if(ans.find(b) !=string::npos){
            return count;
        }
        return -1;
            // brute force.

        // int count=1;
        // string s=a;
        // while(s.find(b) ==string::npos){
        //     count++;
        //     s=s+a;
        //     if(s.find(b) !=string::npos){
        //         return count;
        //     }
        //     if(s.length()>b.length()+a.length()){
        //        return -1;
        //     }
        // }
        // return count;
    }
};