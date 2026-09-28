class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto ast : asteroids){
            bool dis=false;
            if(ast>0){
                st.push(ast);
            }
            else{
                if(st.empty() || st.top()<0){
                    st.push(ast);
                }
                else{
                    while(!st.empty() && st.top()>0){
                        if(st.top()==abs(ast)){
                            dis=true;
                            st.pop();
                            break;
                        }
                        else if(st.top()<abs(ast)){
                            st.pop();
                        }
                        else{
                            dis=true;
                            break;
                        }
                    }
                    if(!dis){
                        st.push(ast);
                    }
                }
            }
        }
        int n=st.size();
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};