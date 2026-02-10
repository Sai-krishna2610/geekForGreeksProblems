/**
 * @param {number} n
 * @returns {number}
 */
class Solution {
    findMin(n) {
        let currency=[10,5,2,1];
        let ans=[];
        let i=0;
        while(n>0)
        {
            let count=Math.floor(n/currency[i]);
            while(count>0)
            {
                ans.push(currency[i]);
                count--;
            }
            n=n%currency[i];
            i++;
        }
        return ans.length;
    }
}