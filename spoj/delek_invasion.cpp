    #include <bits/stdc++.h>
    using namespace std;
     
    typedef long long ll;
    typedef double db;
    #define debug(x) cout<<#x<<" :: "<<x<<endl;
    #define boost1 ios::sync_with_stdio(0)
    #define boost2 cin.tie(0)
    #define size1 100005
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
     
    int level[size1],p[size1],dp[30][size1],maxi[30][size1],par[size1];
    vector<pair<int,int > > v[size1];
    int logBase2(int x){
        int cnt = 0;
        while(x >>= 1)
            ++cnt;
        return cnt;
    }
    void dfs(int u,int parr,int l){
        p[u] = parr;
        level[u] = l;
        for(auto x : v[u]){
            if(x.first != parr){
                dfs(x.first,u,l+1);
            }
        }
    }
     
    void pre(int n){
        int maxiHeight = logBase2(n) + 1;
        int i,j;
        for(i=0;i<n;i++){
            dp[0][i] = p[i];
            for(auto x : v[i]){
                if(x.first == p[i]){
                    maxi[0][i] = x.second;
                    break;
                }
            }
        }
     
        for(i=1;i<maxiHeight;i++){
            for(j=0;j<n;j++){
                if(dp[i-1][j] == -1){
                    dp[i][j] = -1;
                    maxi[i][j] = maxi[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][dp[i-1][j]];
                    maxi[i][j] = max(maxi[i-1][j],maxi[i-1][dp[i-1][j]]);
                }
            }
        }
    }
     
    int findLca(int n,int u,int v){
        if(level[v] < level[u]){
            swap(u,v);
        }
        int diff = level[v] - level[u];
     
        while(diff > 0){
            int log2 = logBase2(diff);
            v = dp[log2][v];
            diff  = diff - (1<<log2);
        }
     
        while(u!=v){
            int i = logBase2(level[u]);
            for(;i>0 && dp[i][u] == dp[i][v];){
                i--;
            }
            u = dp[i][u];
            v = dp[i][v];
        }
     
        return u;
    }
     
    int find1(int x){
        if(par[x] == x) return x;
     
        return par[x] = find1(par[x]);
    }
     
    void union1(int x,int y){
        int p = find1(x);
        int q = find1(y);
        par[q] = p;
    }
     
     
    int findMax(int n,int u,int l){
        if(u == l) return 0;
        int log2 = logBase2(level[u] - level[l]);
        int mx = 0;
        while(log2 >= 0){
            mx = max(mx,maxi[log2][u]);
            u = dp[log2][u];
            if(u == l) return mx;
            log2 = logBase2(level[u] - level[l]);
        }
        return mx;
    }
     
    typedef struct{
        int a,b,idx,w;
    }Node;
     
    int mark[size1];
    unordered_map<ll,int> mp;
     
    void fun(int a,int l,int w){
        if(a == l || a == 0 || level[a] < level[l]) return ;
        //cout<<a<<" "<<l<<endl;
        if(mark[a] == 0){
            mark[a] = 1;
            mp[min(a,p[a])*size1 + max(a,p[a])] = w;
            //debug(min(a,p[a])*size1 + max(a,p[a]));
        }
        //cout<<a<<" "<<p[a]<<endl;
        fun(p[a],l,w);
        p[a] = l;
    }
     
    int main()
    {
        //boost1;
        //boost2;
        int n,m,i,j,t,x,y,w,k=1,q;
        cin>>n>>m;
     
        for(i=0;i<n;i++) par[i] = i;
     
        vector<Node> edge;
        for(i=0;i<m;i++){
            cin>>x>>y>>w;
            x--;
            y--;
            if(x > y) swap(x,y);
            edge.push_back({x,y,i,w});
        }
        sort(edge.begin(),edge.end(),[](Node &a,Node &b){
                return  a.w < b.w;
             });
        ll ans[m];
     
        for(auto &x : edge){
            if(find1(x.a) != find1(x.b)){
                union1(x.a,x.b);
                v[x.a].push_back({x.b,x.w});
                v[x.b].push_back({x.a,x.w});
                ans[x.idx] = x.w;
            }else{
                 x.w = -x.w - 1;
            }
        }
     
        dfs(0,-1,0);
        pre(n);
     
        for(auto &x : edge){
            if(x.w < 0){
                int a = x.a;
                int b = x.b;
                int l = findLca(n,a,b);
                //debug(l);
    //            cout<<a<<" "<<b<<" "<<l<<endl;
    //            cout<<p[1]<<endl;
                fun(a,l,-x.w - 1);
                fun(b,l,-x.w - 1);
            }
        }
     
        for(auto x : edge){
            if(x.w >= 0){
                //debug(x.a*size1 + x.b);
                if(mp.find(x.a*size1 + x.b) == mp.end()){
                    ans[x.idx] = 1000000000;
                }else{
                    ans[x.idx] = mp[x.a*size1 + x.b];
                }
                continue;
            }
            int l = findLca(n,x.a,x.b);
            int mx = max(findMax(n,x.a,l),findMax(n,x.b,l));
            ans[x.idx] = mx;
        }
     
        for(i=0;i<m;i++){
            cout<<ans[i]<<endl;
        }
        return 0;
    }
