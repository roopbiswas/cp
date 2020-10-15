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
 
int a[size1],par[size1];
 
int find1(int x){
    if(par[x] == x){
        return x;
    }
    return par[x] = find1(par[x]);
}
 
void union1(int x,int y){
     int p = find1(x);
     int q = find1(y);
     par[q] = p;
}
 
int connect(int x){
    a[x] = 1;
    if(par[x] == x ){
        return x;
    }
    return par[x] = connect(par[x]);
}
int main()
{
    boost1;
    boost2;
    ll n,m,i,j,t,x,y,w;
    ll cost = 0;
    cin>>t;
    while(t--){
        cost = 0;
        vector<pair<ll,pii > > v;
        cin>>n>>m;
        mem(a);
        
        for(i=1;i<=n;i++){
            cin>>a[i];
            par[i] = i;
        }
        for(i=0;i<m;i++){
            cin>>x>>y>>w;
            v.pb(make_pair(w,make_pair(x,y)));
        }
        sort(v.begin(),v.end());
         //sort(v.begin(),v.end());
        
        for(i=0;i<m;i++){
            x = v[i].se.fi; 
            y = v[i].se.se;
            w = v[i].fi;
            if((find1(x) != find1(y))){
                if(a[find1(x)] + a[find1(y)] == 1){
                    if(!a[find1(x)]){
                        connect(x);
                    }else{
                        connect(y);
                    }
                    union1(x,y);
                    cost += w;
                }else if(a[find1(x)] + a[find1(y)] == 0){
                    union1(x,y);
                    cost += w;
                }
            }
        }
        int flag = 1;
        for(i=1;i<=n;i++){
            if(!a[find1(i)]){
              //  debug(i);
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            cout<<cost<<endl;
        }else{
            cout<<"impossible"<<endl;
        }
        v.clear();
    }
 
    return 0;
}
