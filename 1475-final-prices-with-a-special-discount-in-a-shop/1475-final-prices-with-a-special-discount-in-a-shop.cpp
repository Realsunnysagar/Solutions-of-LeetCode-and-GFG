class Solution {
public:
    vector<int> nse(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, 0);
    stack<int> st;      // stores indices

    for (int i = n - 1; i >= 0; i--) {

        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }

        if (!st.empty())
            ans[i] = arr[st.top()];

        st.push(i);
    }

    return ans;
}
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> discount = nse(prices);
        for(int i = 0 ; i<n; i++){
        prices[i] -= discount[i];
        }

        return prices;
    }
};