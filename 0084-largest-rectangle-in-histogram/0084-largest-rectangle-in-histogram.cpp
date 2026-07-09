class Solution {
public:
    vector<int> findNSE(vector<int> &arr){
        int n = arr.size();
        vector<int> nse(n, n); //if no such elment exist then size of arr
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSE(vector<int> &arr){
        int n = arr.size();
        vector<int> pse(n , -1); //if no such element exist then -1
        stack<int> st;

        for(int i = 0; i<n ; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse = findNSE(heights);
        vector<int> pse = findPSE(heights);

        int maxArea = 0; 
        for(int i = 0; i<n ; i++){
            maxArea = max(maxArea, heights[i]*(nse[i] - pse[i] - 1));
        }

        return maxArea;
    }
};