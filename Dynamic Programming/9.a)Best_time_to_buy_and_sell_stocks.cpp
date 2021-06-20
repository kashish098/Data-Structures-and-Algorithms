//PROBLEM LINK
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

//Solution 1, O(n) time,O(n) space complexity
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i,n = prices.size();
        if(n == 0) return 0;
        int min_buy_price = prices[0];
        vector<int> profit(n,0);
        for(i=1;i<n;i++){
            if(prices[i] > min_buy_price){
                profit[i] = prices[i] - min_buy_price;
            }
            else{
                min_buy_price = prices[i];
            }
        }
        return *max_element(profit.begin(), profit.end()); 
    }
};

//Solution 2, O(n) time,O(1) space complexity
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i,n = prices.size();
        if(n == 0) return 0;
        int min_buy_price = prices[0];
        int maxProfit = 0;
        for(i=1;i<n;i++){
            if(prices[i] > min_buy_price){
                maxProfit = max(maxProfit, prices[i] - min_buy_price);
            }
            else{
                min_buy_price = prices[i];
            }
        }
        return maxProfit; 
    }
};