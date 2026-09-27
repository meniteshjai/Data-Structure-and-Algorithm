class Solution {
public:
    void nextSmaller(vector<int>&arr,vector<int>&next){
        stack<int>st;
        st.push(-1);
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            int element=arr[i];
            while(st.top() != -1 && arr[st.top()]>=element){
                st.pop();
            }
            next.push_back(st.top());
            st.push(i);
        }
    }
    void prevSmaller(vector<int>&arr,vector<int>&prev){
        stack<int>st;
        st.push(-1);
        int n=arr.size();
        for(int i=0;i<n;i++){
            int element=arr[i];
            while(st.top() != -1 && arr[st.top()]>=element){
                st.pop();
            }
            prev.push_back(st.top());
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>next;
        vector<int>prev;
        nextSmaller(heights,next);
        reverse(next.begin(),next.end());
        for(int i=0;i<next.size();i++){
            if(next[i]==-1){
                next[i]=next.size();
            }
        }
        prevSmaller(heights,prev);
        vector<int>area;
        for(int i=0;i<next.size();i++){
            int width=next[i]-prev[i]-1;
            int height=heights[i];
            int currArea=width*height;
            area.push_back(currArea);
        }
        int maxArea=INT_MIN;
        for(int i=0;i<area.size();i++){
            maxArea=max(maxArea,area[i]);
        }
        return maxArea;
    }
};