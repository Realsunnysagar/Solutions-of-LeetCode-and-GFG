/*
Problem Name : 496. Next Greater Element I
Platform     : LeetCode
Topic        : Stack
Difficulty   : Easy
Link         : https://leetcode.com/problems/next-greater-element-i/description/

Time Complexity : O(n1 + n2)
Space Complexity: O(n^2)
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2= nums2.size();
        unordered_map<int,int>mp;
        stack<int> st;
        vector<int> res;

        for(int i = n2-1;i>=0; i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop(); 
            }
            mp[nums2[i]] = st.empty() ? -1:st.top();
            st.push(nums2[i]);
        }
        for(int num:nums1){
            if(mp.find(num) != mp.end()){
                res.push_back(mp[num]); 
            }else{
                res.push_back(-1);
            }
        }
        return res;
    }
};