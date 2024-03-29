//Special permutations
#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    int dp[16][1<<14];
    int n ,mod =1e9+7;
    int findperm(vector<int>&v,int vis,int prev){
        if(vis == (1<<n)-1) return 1;      // if all element visited after satisfy the condition return 1 
        if(dp[prev+1][vis] != -1) return dp[prev+1][vis];
        int ans =0;
        if( prev !=-1 ){
        for( int i =0; i<n;i++)
        {
            if(((vis>>i)&1)==0 && (v[i]%v[prev]==0 || v[prev]%v[i]==0)) /// first checking cur index i is visited or not then  given condition 
               ans =( ans +  findperm(v, vis|(1<<i),i))%mod;    //mark visited ith index element now prev element is ith element so prev = i
            
        }
            }
        else {                                    // if prev =-1 it means there is nothing 
           for( int i =0; i<n;i++)
                ans =( ans +  findperm(v, vis|(1<<i),i))%mod;
        }
       return dp[prev+1][vis] =ans;
    }
    
    int specialPerm(vector<int>& v) {
    memset(dp,-1,sizeof(dp))    ;
        n = v.size();
        return findperm(v,0,-1);
    }
};