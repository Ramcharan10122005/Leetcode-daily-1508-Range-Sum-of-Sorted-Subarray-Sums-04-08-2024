class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod = 1e9 + 7;
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            int cur_sum = 0;
            for (int j = i; j < n; j++) {
                cur_sum += nums[j];
                temp.push_back(cur_sum);
            }
        }
        sort(temp.begin(), temp.end());
        long long ans = 0;
        for (int i = left - 1; i <= right - 1; i++) {
            ans += temp[i];
        }
        return ans % mod;
    }
};
