/**
 * @param number a
 * @param number b
 * @returns number
 */

class Solution {
    gcd(a, b) {
        // code here
        if(b==0)
        {
            return a;
        }
        return this.gcd(b,a%b);
    }
}