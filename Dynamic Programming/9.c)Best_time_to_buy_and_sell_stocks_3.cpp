//PROBLEM LINK
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE
//Soltuion credit post: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/39613/My-C%2B%2B-solution-(O(N)-time-O(1)-space-8ms)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int states[4] = {INT_MIN, 0, INT_MIN, 0};
        for(int i=0;i<prices.size();i++){
            states[3] = max(states[3], states[2] + prices[i]);
            states[2] = max(states[2], states[1] - prices[i]);
            states[1] = max(states[1], states[0] + prices[i]);
            states[0] = max(states[0], -prices[i]);
        }
        return max(states[1], states[3]);
    }    
};