#include <bits/stdc++.h>
using namespace std;
/*Given an array of size n, find the majority element. 
The majority element is the element that appears more than ⌊ n/2 ⌋ times.*/
//Solve the problem in O(n) time complexity and O(1) space complexity

//Element which is repeated more than n/2 times is called majority element
//Function to find the Majority element

//Two steps in the process
//1st Find the candidate key (it may or may be the answer)
//check if the candidate element is really a majority element
int CandidateElement(int a[], int n)
{
    int maj_index = 0;
    int cnt = 1; //since we already chose the element once
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[maj_index])
            cnt--;
        else
            cnt++;
        if (cnt == 0)
        {
            maj_index = i;
            cnt = 1;
        }
    }
    //cout<<a[maj_index];
    return a[maj_index];
}
bool CheckMajority(int a[], int n, int cand)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == cand)
            cnt++;
    }
    return (cnt > n / 2);
}
void PrintMajorityElement(int a[], int n)
{
    int cand = CandidateElement(a, n);
    if (CheckMajority(a, n, cand))
    {
        cout << cand << "\n";
    }
    else
        cout << "No element is major\n";
}
int main()
{
    int a[] = {2, 2, 3, 2, 3};
    int size = (sizeof(a)) / sizeof(a[0]);
    PrintMajorityElement(a, size);
}