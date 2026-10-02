class Solution {
public: 
    void paranthesis(int open,int close, vector<string>&ans,string &str){
        if(open<0 || close<0){
            return;
        }
        if(open==0 && close==0){
            ans.push_back(str);
            return;
        }
        if(open>close){
            return ;
        }
        str.push_back('(');
        paranthesis(open-1,close,ans,str);
        str.pop_back();

        str.push_back(')');
        paranthesis(open,close-1,ans,str);
        str.pop_back();

    }
    vector<string> generateParenthesis(int n) {
       vector<string>ans;
       string str="";
       paranthesis(n,n,ans,str);
       return ans;
    }
};