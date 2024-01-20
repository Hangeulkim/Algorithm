class Solution {
public: 
    int jump(vector<int>& nums) {
        int ret = 0, last = 0, maxidx;
        for(int i=0; i<nums.size()-1;++i){
            maxidx = max(maxidx, nums[i]+i);
            if(last == i){
                ++ret;
                last = maxidx;
            }
        }

        return ret;
    }   
};      