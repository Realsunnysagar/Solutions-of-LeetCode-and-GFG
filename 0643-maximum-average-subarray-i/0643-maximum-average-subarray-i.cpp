class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        long long sum = 0;
        int i = 0;
        while(i < k){
            sum = sum + nums[i];
            i++;
        }
        long long maxSum = sum;
        while(i<nums.size()){
            sum += nums[i];
            sum -= nums[i - k];
            maxSum = max(sum, maxSum);
            i++;
        }
        return (double)maxSum/k;
    }
};