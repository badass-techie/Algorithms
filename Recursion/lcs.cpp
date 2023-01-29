// longest common subsequence (LCS) algorithm
// this problem involves finding the longest sequence of characters that appear in the same order in both strings
// they do not have to be contiguous

#include <iostream>

using namespace std;

string lcs(string s1, string s2)
{
    if (s1.empty() || s2.empty())   // base case (if either string is empty, there is no common subsequence)
        return "";
    if (s1[0] == s2[0])             // if the first characters of both strings are the same, add it to the result
        return s1[0] + lcs(s1.substr(1), s2.substr(1));
    string s1_ = lcs(s1.substr(1), s2);
    string s2_ = lcs(s1, s2.substr(1));
    return s1_.size() > s2_.size() ? s1_ : s2_;  // otherwise return the longer of the two possible subsequences at this point
}

int main()
{
    string s1 = "1834853584";
    string s2 = "1345838";
    cout << lcs(s1, s2) << endl;
    return 0;
}