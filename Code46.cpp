// Extra characters in a string
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    unordered_map<string, int> mp;
    int dfs(int start, string s, int end, vector<int> &dp)
    {
        if (end >= s.size())
            return end - start;
        if (dp[start] != -1)
            return dp[start];
        string temp = s.substr(start, end - start + 1);
        int ans = 1e9;
        // pick
        if (mp.find(temp) != mp.end())
        {
            ans = dfs(end + 1, s, end + 1, dp);
        }
        // not pick
        ans = min(ans, dfs(start, s, end + 1, dp));
        // skip char
        ans = min(ans, end - start + 1 + dfs(end + 1, s, end + 1, dp));
        return dp[start] = ans;
    }
    int minExtraChar(string s, vector<string> &dictionary)
    {
        for (auto word : dictionary)
        {
            mp[word]++;
        }
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return dfs(0, s, 0, dp);
    }
};