// link :: https://www.spoj.com/problems/CNTDO/
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
 
int a[size1],f[20005];
 
int main()
{
    boost1;
    //boost2;
    int n,m,i,j,ans,t,x,y,w;
    cin>>t;
    while(t--){
        mem(f);
        ans = 0;
        cin>>n;
        for(i=0;i<n;i++){
            cin>>x;
            a[i] = x;
            f[x+10000]++;
        }
        for(i=0;i<n;i++){
            if((a[i]%2) == 0 && f[a[i]/2 + 10000]){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
 
 
    return 0;
}
