 // link :: https://www.spoj.com/problems/MBLAST/
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef double db;
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define boost1 ios::sync_with_stdio(0)
#define boost2 cin.tie(0)
#define size1 200005
#define mod 1000000007
#define vll         vector < ll >
#define vpll        vector < pair < ll ,ll> >
#define pii         pair < int,int >
#define pll         pair < ll,ll >
#define fi          first
#define se          second
#define pb(x)       push_back(x)
#define endl        "\n"
#define mem1(x)     memset(x,-1,sizeof x)
#define mem(x)      memset(x,0,sizeof x)
#define mem63(x)    memset(x,63,sizeof x)
 
int dp[2005][2005];
 
int main()
{
    boost1;
    //boost2;
    int n,m,i,j,t,x,y,w,k,diff;
    string str1,str2;
    cin>>str1>>str2>>k;
    n = str1.length();
    m = str2.length();
    mem(dp);
    for(i=0;i<=max(m,n);i++){
        dp[0][i] = i*k;
        dp[i][0] = i*k;
    }
    dp[0][0] = 0;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            diff = abs(str2[i-1] - str1[j-1]);
            dp[i][j] = min(k+dp[i-1][j],min(dp[i-1][j-1]+diff,k+dp[i][j-1]));
        }
    }
//    for(i=0;i<=m;i++){
//        for(j=0;j<=n;j++){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    cout<<dp[m][n];
    return 0;
}
