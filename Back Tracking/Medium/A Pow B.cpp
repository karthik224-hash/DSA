//Compute a pow b
//Link:https://www.hackerrank.com/contests/smart-interviews/challenges/si-compute-a-power-b
int a_pow_b(int a,int b,int m){
    if(b==0)
        return 1;
    /* Calling the function for one time and storing its value */
    int t=a_pow_b(a,b/2,m);
    if(b%2==0)
        return (t%m*t%m)%m;
    else
        return (a%m*t%m*t%m)%m;
}