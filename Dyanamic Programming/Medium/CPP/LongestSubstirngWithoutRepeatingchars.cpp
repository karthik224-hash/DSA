/*
    Given a string, find the length of the longest substring without repeating characters.
    Input: "abcabcbb"
    Output: 3 
    Explanation: The answer is "abc", with the length of 3.
    */
int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    if (n <= 1)
        return n;
    int result = 1;
    vector<int> v(256, 0);
    //Maintain two pointers ,move the right pointer and store the
    //corrresponding positions of characters
    // if a character is already found move the right pointer to 1 greater than the previous
    // position where the character was repeating
    // everytime the update the result with the max(result,j-i+1)
    for (int i = 0, j = 0; j < n; j++)
    {
        i = (v[s[j]] > 0) ? max(i, v[s[j]]) : i;
        v[s[j]] = j + 1;
        result = max(result, j - i + 1);
    }
    return result;
}