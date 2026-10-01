class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price=INT_MAX;
        int max_profit=0;
        int current_price;
        for(int i=0; i<prices.size(); i++){
            min_price=min(prices[i], min_price);
            current_price=prices[i]-min_price;
            max_profit=max(current_price, max_profit);
        }
        return max_profit;
    }
};
