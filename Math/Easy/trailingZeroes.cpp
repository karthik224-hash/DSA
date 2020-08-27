//Trailing Zeroes
//Link:https://leetcode.com/problems/factorial-trailing-zeroes/
//Iterative Solution
 /*
        The ZERO comes from 10.
        The 10 comes from 2 x 5
        And we need to account for all the products of 5 and 2. likes 4×5 = 20 ...
        So, if we take all the numbers with 5 as a factor, we'll have way more than enough even numbers to pair with them to get factors of 10

 */
int trailingZeroes(int n) {
        int res=0;
        for(long long int i=5;n/i>0;i*=5){
            res+=n/i;
        }
        return res;
 }
 
 //Recursive Solution
 
int trailingZeroes(int n) {
       return n==0?0:n/5+trailingZeroes(n/5);
}