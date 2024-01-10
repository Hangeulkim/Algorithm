class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0, sz = nums.size();

        //swap front when duplicate
        //how to know duplicate?
        //nums n = 201
        //length = 30'000
        //n * length = 6'000'000
        
        //first check num 30'000 but use memory 201 * int
        //the most performance is changed with back idx if duplicate


        //1. how to know this is duplicate before all count
        //      or don't duplicate
        // how to solve in O(nums.size())
        //2. how to swap number
        //     it's now problem to swap with back idx

        // use k like stack point
        for(int i=0;i<sz;++i){
            int now = nums[i];
            int know = nums[k];
            if(now != know){
                
            }
        }
    }
};