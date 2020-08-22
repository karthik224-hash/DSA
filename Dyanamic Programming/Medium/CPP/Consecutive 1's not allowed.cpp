//Consecutive 1's not allowed
//Link:https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed/0
/*
		Consider the pattern for size 1,2,3,4... and analyse it..
		
		for n=1 ..  0--0,1--1 (res=2)
		
		for n=2 ..  00    10
					01	  11  
					
					---   ---
					2	+	1  ==3
							
							
		for n=3 ..  000		100
					001		101
					010		110  
					011		111
					----	----
					 3		2	==5
					
		for n=4..  	0000	1000		
					0001	1001
					0010	1010
					0011	1011
					0100	1100
					0101	1101
					0110	1110
					0111	1111 
					----	----
					5		3    ==8
					
		Same as Fibonnaci series and can be done using dp
*/
#define int long long 
#define mod 1000000007
int cntbinstr(int n){
	int x[n],y[n];
    x[0]=y[0]=1;
    for(int i=1;i<n;i++){
        x[i]=(x[i-1]%mod+y[i-1]%mod)%mod;
        y[i]=x[i-1]%mod;
    }
	return (x[n-1]+y[n-1])%mod;
}
