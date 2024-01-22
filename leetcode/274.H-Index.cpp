class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        for(int i=citations.size();i>0;--i){
            if(citations[citations.size()-i]>=i){
                return i;
            }
        }
        return 0;
    }
};