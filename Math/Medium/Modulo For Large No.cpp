//Modulo for large numbers
//Link 1:https://www.hackerrank.com/contests/smart-interviews/challenges/si-string-modulo
//Link 2:https://www.codechef.com/problems/GCD2
/*
It is a distributive over addition, multiplication. i.e.

(A+B)%m = (A%m + B%m) %m

(A*B)%m = (A%m * B%m) %m

These two will help here, mainly the first one.

Consider, 'abcdepqr' is a string of digits, ok?

Is not abcdepqr = (abcde*1000 + pqr) ? Yes, it is.

Similarly, (a*10000000 + bcdepqr), right?

This is the thing we are going to apply.

What will we do is,

Get one variable to store the answer intialized to zero.

Scan the string from left to right,

Everytime multiply the answer by 10 and add the next number and take the modulo and store this as new answer.

E.g. 12345 % 100:
ans = 0
ans = (o*10 + 1)%100
ans = (1*10 + 2)%100
ans = (12*10 + 3)%100
ans = (23*10 + 4)%100
ans = (34*10 + 5)%100
ans = 45.

*/

long long int getModulo(string n,long long p){
    long long ans=0;
    for(long long i=0;i<n.length();i++)
        ans=(ans*10+(n[i]-'0'))%p;
    return ans;
}