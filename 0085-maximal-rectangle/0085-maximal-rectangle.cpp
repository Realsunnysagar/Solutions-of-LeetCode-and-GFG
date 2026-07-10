class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for(int i = 0; i<n ;i++){

            while(!st.empty() && heights[st.top()] > heights[i]){
                int element = st.top();  st.pop();
                int nse = i;
                int pse = st.empty() ? -1: st.top();

                maxArea = max(maxArea, heights[element]*(nse - pse - 1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = n;
            int element = st.top(); st.pop();
            int pse = st.empty()? -1: st.top();
            maxArea = max(maxArea, heights[element]*(nse - pse - 1));
        }
        return maxArea;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0; // returns 0 if matrix is empty

        int m = matrix[0].size(); // no. of colms
        int maxArea = 0;
        vector<int> height(m,0);

        for(auto& row : matrix){//Traversed each row of matrix 
            for(int i = 0; i<m; i++){ //updated based on current row
                if(row[i] == '1') height[i]++;
                else height[i] = 0;
            }
            // Area
            maxArea = max(maxArea, largestRectangleArea(height));
        }
        return maxArea;
    }
};