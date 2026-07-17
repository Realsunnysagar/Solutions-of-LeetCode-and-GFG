class Solution {
public:
    int niceSub(vector<int> &nums, int k){
        int left = 0 , right = 0, cnt = 0 , sum =0;
        while(right < nums.size()){
            sum += (nums[right] % 2);
            while(sum > k){
                sum -= (nums[left]%2);
                left++;
            }
            cnt = cnt + (right - left + 1);
            right++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int result = niceSub(nums, k) - niceSub(nums, k-1);
        return result;
    }
};