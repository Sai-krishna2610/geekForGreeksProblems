/**
 * @param {number[]} prices
 * @param {number} k
 * @returns {number[]}
 */
class Solution {
    minMaxCandy(prices, k) {
        let i=0;
        let j=prices.length-1;
        let ans=[];
        prices.sort((a,b)=>a-b);
        let minValue=0;
        while(i<=j)
        {
            minValue+=prices[i];
            i++;
            j-=k;
        }
        ans.push(minValue);
        i=prices.length-1;
        j=0;
        let maxValue=0;
        while(i>=j)
        {
            maxValue+=prices[i];
            i--;
            j+=k;
        }
        ans.push(maxValue);
        return ans;
    }
}
