int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    int max_i = 0;
    cout << dp[0] << " ";
    for(size_t i=0; i<nums.size(); i++){
        for(size_t j=0; j<i; j++){
            if(nums[j]<nums[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    return *max_element(dp.begin(), dp.end());
}
