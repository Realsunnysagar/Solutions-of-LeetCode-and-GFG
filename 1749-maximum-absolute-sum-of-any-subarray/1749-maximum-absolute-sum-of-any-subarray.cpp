class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxCurr = 0, minCurr = 0;
        int maxSum = INT_MIN, minSum = INT_MAX;
        // just used the Kandane's algo 2 times 
        //for max
        for(int i =0; i< n; i++){
            maxCurr = max(nums[i], maxCurr + nums[i]);
            maxSum = max(maxSum, maxCurr);
        }
        // for min
        for(int i =0; i< n; i++){
            minCurr = min(nums[i], minCurr + nums[i]);
            minSum = min(minSum, minCurr);
        }
       
        return maxSum = max(maxSum, abs(minSum));
    }
};