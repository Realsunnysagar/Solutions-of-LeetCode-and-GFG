class Solution {
public:
    int func(vector<int> &nums, int goal){
        int left = 0, right = 0, cnt = 0;
        int sum = 0;
        if(goal < 0) return 0;
        while(right < nums.size()){
            sum += nums[right];
            while(sum > goal){
                sum -= nums[left];
                left++;
            }
            cnt = cnt + (right - left + 1);
            right++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int ans = func(nums, goal) - func(nums, goal-1);
        return ans;
    }
};