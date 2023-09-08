// Time Complexity: O(N)
// Space Complexity: O(1)

/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
    let buy = -prices[0]
    let sell = 0
    for (let i = 1; i < prices.length; ++i) {
        buy = Math.max(buy, -prices[i]);
        sell = Math.max(sell, buy + prices[i])
    }
    return sell
};