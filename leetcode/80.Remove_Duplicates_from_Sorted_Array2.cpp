class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int cnt = 0;

        for(int i=0;i<nums.size();++i){
            if(nums[k] != nums[i] || cnt++ < 2){
                nums[k++]=nums[i];
            }
            else if(cnt >= 2){
                cnt = 0;
            }
        }
        return k;
    }
};