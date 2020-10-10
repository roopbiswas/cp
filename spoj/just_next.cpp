// link :: https://www.spoj.com/problems/JNEXT/
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef double db;
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define boost1 ios::sync_with_stdio(0)
#define boost2 cin.tie(0)
#define size1 1000005
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
 
int a[size1];
 
 
int main()
{
//    boost1;
//    boost2;
    int n,m,i,j,t,x,y,w,k;
    int mark[10];
    cin>>t;
    while(t--){
        cin>>n;
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        mem1(mark);
        int flag = 0;
        for(i=n-1;i>0;i--){
            mark[a[i]] = i;
            if(a[i] > a[i-1]){
                flag = 1;
                break;
            }
        }
        if(!flag){
            cout<<-1<<endl;
            continue;
        }
        for(j=0;j<10;j++){
            if(mark[j] != -1 && j > a[i-1] ){
                swap(a[mark[j]],a[i-1]);
                //debug("cfd");
                break;
            }
        }
        sort(a+i,a+n);
        for(i=0;i<n;i++){
            cout<<a[i];
        }
        cout<<endl;
    }
    return 0;
}
