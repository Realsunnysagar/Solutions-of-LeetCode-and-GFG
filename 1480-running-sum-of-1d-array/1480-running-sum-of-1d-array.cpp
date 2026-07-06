class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // int sum = 0;
        // vector<int> Sum(nums.size());
        for(int i = 1; i<nums.size(); i++){
            nums[i] += nums[i-1];
        }
        return nums;
    }
};