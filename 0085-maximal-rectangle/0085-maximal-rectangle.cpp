class Solution {
private:
    void nextSmallerElement(vector<int>& arr, vector<int>& nextAns) {
        stack<int> st;
        st.push(-1);
        int n = arr.size();

        for(int i = n - 1; i >= 0; i--) {
            while(st.top() != -1 && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nextAns.push_back(st.top());
            st.push(i);
        }
    }

    void prevSmallerElement(vector<int>& arr, vector<int>& prevAns) {
        stack<int> st;
        st.push(-1);
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            while(st.top() != -1 && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            prevAns.push_back(st.top());
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextAns;
        vector<int> prevAns;

        nextSmallerElement(heights, nextAns);
        reverse(nextAns.begin(), nextAns.end());

        // agar next smaller nahi mila to n consider karenge
        for(int i = 0; i < nextAns.size(); i++) {
            if(nextAns[i] == -1) {
                nextAns[i] = nextAns.size();
            }
        }

        prevSmallerElement(heights, prevAns);

        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++) {
            int width = nextAns[i] - prevAns[i] - 1;
            int height = heights[i];
            maxArea = max(maxArea, width * height);
        }
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> v(n, vector<int>(m, 0));

        // char -> int conversion
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                v[i][j] = matrix[i][j] - '0';
            }
        }

        int area = largestRectangleArea(v[0]);

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(v[i][j] == 1)
                    v[i][j] += v[i - 1][j];
                else
                    v[i][j] = 0;
            }
            area = max(area, largestRectangleArea(v[i]));
        }
        return area;
    }
};