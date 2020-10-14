// link :: https://www.spoj.com/problems/CHOCOLA/
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
 
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.fi > b.fi;
}
 
 
int main()
{
    //boost1;
    //boost2;
    int n,m,i,j,t,x,y,w;
    vector<pair<int,int> > v;
    cin>>t;
    while(t--){
        cin>>m>>n;
        ll res = 0;
        for(i=0;i<m-1;i++){
            cin>>x;
            v.pb(make_pair(x,1));
        }
        for(i=0;i<n-1;i++){
            cin>>x;
            v.pb(make_pair(x,2));
        }
        sort(v.begin(),v.end(),cmp);
        x = y = 1;
        for(i=0;i<v.size();i++){
            if(v[i].se == 1){
                res += x*(v[i].fi);
                y++;
            }else{
                res += y*(v[i].fi);
                x++;
            }
        }
        cout<<res<<endl;
        v.clear();
    }
 
    return 0;
}
