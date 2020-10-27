#include <bits/stdc++.h>
  using namespace std;

  typedef long long ll;
  typedef double db;
  #define debug(x) cout<<#x<<" :: "<<x<<endl;
  #define debug1(x,y) cout<<#x<<" :: "<<x<<"   "<<#y<<" :: "<<y<<endl;
  #define boost1 ios::sync_with_stdio(0)
  #define boost2 cin.tie(0)
  #define size1 300005
  #define size2 15000001
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
  #define flush       fflush(stdout)

  int a[size1],dp[size2];

  void pre(){
      mem1(dp);
      dp[0] = dp[1] = 1;
      ll i,j;
      for(i=2;i<size2;i++){
          if(dp[i] == -1){
              dp[i] = i;
              for(j=i*i;j<size2;j+=i){
                  dp[j] = i;
              }
          }
      }
  }
  int main()
  {
      boost1;
      boost2;
  //    freopen("input.txt", "r", stdin); // redirects standard input
  //	freopen("output.txt", "w", stdout); // redirects standard output

      ll n,m,i,j,t,x,y,w,k;
      pre();

      cin>>n;
      for(i=0;i<n;i++){
          cin>>a[i];
      }
      int g = a[0];
      for(i=1;i<n;i++){
          g = __gcd(g,a[i]);
      }
      for(i=0;i<n;i++){
          a[i] /= g;
      }
      unordered_map<int,int> mp;
      int temp;
      for(i=0;i<n;i++){
          x = a[i];
          while(x != 1){
              temp = dp[x];
              mp[temp]++;

              if(temp == 1) break;
              while(x % temp == 0){

                  x /= temp;
              }
          }
      }
      ll mini = n;
      for(auto x : mp){
          mini = min(mini,n - mp[x.first]);
      }
      if(mini == n) {
          cout<<(-1)<<endl;
      }else{
          cout<<mini<<endl;
      }
      return 0;
  }
