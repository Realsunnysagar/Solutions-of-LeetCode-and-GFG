class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int cnt = 0, n = arr.size();
        int sum = 0;
        int target = k * threshold;

        for(int i = 0; i< k ; i++){
            sum += arr[i];
        }

        if(sum >= target) cnt++;

        for(int i = k ; i<n ; i++){
            sum += arr[i] - arr[i-k];
            if(sum >= target) cnt++;
        }

        return cnt;
    }
};