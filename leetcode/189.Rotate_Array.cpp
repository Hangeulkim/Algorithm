class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        k %= sz;
        
        reverse(nums.begin(), nums.begin()+(sz-k));
        reverse(nums.begin()+(sz-k),nums.end());
        reverse(nums.begin(),nums.end());
    }
};