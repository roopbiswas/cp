// link :: https://www.spoj.com/problems/MPILOT/
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
#define INF 999999999999999
 
int tc,ta,n;
vpll v;
ll dp[5005][5005];
ll fun(int c,int a,int idx){
    if(idx == -1){
        return 0;
    }
    ll ans1 = INF,ans2 = INF;
 
    if(dp[c][a] != -1){
        return dp[c][a];
    }
 
    if(c < tc){
        ans1 = v[idx].first + fun(c+1,a,idx-1);
    }
 
    if(a < ta && c > a){
        ans2 = v[idx].se + fun(c,a+1,idx-1);
    }
 
    return dp[c][a] = min(ans1,ans2);
}
 
int main()
{
    boost1;
    boost2;
    int m,i,j,t,x,y,w;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>x>>y;
        v.pb(make_pair(x,y));
    }
    tc = ta = n/2;
   // reverse(v.begin(),v.end());
    mem1(dp);
    cout<<fun(1,0,n-2)+v[n-1].fi;
    return 0;
}
