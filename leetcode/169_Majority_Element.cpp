class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret = nums[0];
        int cnt = 0;

        for(int num : nums){
            if(!cnt)
                ret = num;
            
            cnt += num == ret ? 1 : -1;
        }

        return ret;
    }
};