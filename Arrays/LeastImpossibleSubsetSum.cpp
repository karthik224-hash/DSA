#include <bits/stdc++.h>
using namespace std;
//link: https://www.geeksforgeeks.org/find-smallest-value-represented-sum-subset-given-array/
// C++ program to find the smallest positive value that cannot be
// represented as sum of subsets of a given sorted array


//we can solve this by dp subset sum with complexity O(arraysum*arraysize)

//More efficiently we can solve in O(nlogn+n) as below

//first sort the array
// we will initialize a variable res to get the minimum subset sum which is not possible
//Everytime we consider ith element we have two choices
//1) If the required sum (res) calculated after traversing i-1 elements is  res and  ar[i] is greater than res
//then it means there is a gap. res sum is not possible return that
//2) If the ar[i] is lesser than or equal to res than next sum to check is res+ar[i]
// ex: 1 2 3 4
// res 1 2 4 7
//note when  sum 4 is possible observe that we can get 5(2+3),6(1+2+3) with i-1 elements sonext we check for 7 (res+ar[i]) directly
int findSmallest(int arr[], int n)
{
    int res = 1; // Initialize result

    // Traverse the array and increment 'res' if arr[i] is
    // smaller than or equal to 'res'.
    for (int i = 0; i < n && arr[i] <= res; i++)
        res = res + arr[i];

    return res;
}

// Driver program to test above function
int main()
{
    int arr1[] = {1, 3, 4, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << findSmallest(arr1, n1) << endl;

    int arr2[] = {1, 2, 6, 10, 11, 15};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << findSmallest(arr2, n2) << endl;

    int arr3[] = {1, 1, 1, 1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << findSmallest(arr3, n3) << endl;

    int arr4[] = {1, 1, 3, 4};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    cout << findSmallest(arr4, n4) << endl;

    return 0;
}
