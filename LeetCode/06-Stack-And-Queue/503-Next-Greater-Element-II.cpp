/*
Problem Name : 503. Next Greater Element II
Platform     : LeetCode
Topic        : Stack
Difficulty   : Medium
Link         : https://leetcode.com/problems/next-greater-element-ii/description/

Time Complexity : O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;

        for(int i = 2*n-2; i>=0; i--){
            int idx = i%n;
            while(!st.empty() && nums[idx]>=st.top()){
                st.pop();
                
            }
                if(i<n){
                    result[idx] = st.empty() ? -1:st.top();
                }
            st.push(nums[idx]);
        }
        return result;
    }
};