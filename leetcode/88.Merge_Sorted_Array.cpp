class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = m-1, idx2 = n-1, inidx = m + n -1;

        while(idx1 >= 0 && idx2 >= 0){
            int num1 = nums1[idx1];
            int num2 = nums2[idx2];
            
            if(num1 < num2){
                --idx2;
                nums1[inidx--]=num2;
            }
            else{
                --idx1;
                nums1[inidx--]=num1;
            }
        }
        while(idx2>=0){
            nums1[inidx--] = nums2[idx2--];
        }
    }
};