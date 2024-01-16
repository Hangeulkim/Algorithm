class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int maxnum = 0;

        for(int i=prices.size()-1;i>=0;--i){
            if(ret < maxnum-prices[i])
                ret = maxnum-prices[i];
            if(maxnum < prices[i])
                maxnum = prices[i];
        }

        return ret;
    }
};