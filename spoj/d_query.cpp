// problem link :: https://www.spoj.com/problems/DQUERY/

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef double db;
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define boost1 ios::sync_with_stdio(0)
#define boost2 cin.tie(0)
#define size1 300005
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
 
int a[size1],last[(int)1e6+5];
 
typedef struct Node{
    int val;
    struct Node *left,*right;
 
    Node(){
        val = 0;
        left = NULL;
        right = NULL;
    }
}Node;
 
Node* build(int l,int r){
    if(l == r){
        return new Node();
    }
    int mid = (l+r)/2;
 
    Node *temp = new Node();
    temp->left = build(l,mid);
    temp->right = build(mid+1,r);
 
    return temp;
}
 
Node* update(Node* root,Node *temp,int l,int r,int pos,int val){
    if(pos<l || pos > r) {
        if(temp) return temp;
        return root;
    }
    if(l == r){
        if(temp == NULL){
            temp = new Node();
        }
        temp->val = val;
        return temp;
    }
    int mid = (l+r)/2;
 
    if(temp == NULL){
        temp = new Node();
    }
    temp->left = update(root->left,temp->left,l,mid,pos,val);
    temp->right = update(root->right,temp->right,mid+1,r,pos,val);
    temp->val = temp->left->val + temp->right->val;
 
    return temp;
}
 
int query(Node *root,int l,int r,int low,int high){
    if(r<low || high < l) return 0;
 
    if(low<=l && r <= high){
        return root->val;
    }
    int mid = (l+r)/2;
 
    return query(root->left,l,mid,low,high) + query(root->right,mid+1,r,low,high);
}
int main()
{
    boost1;
    boost2;
    int n,m,i,j,t,x,y,w,l,r,q;
 
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mem1(last);
    Node* root[n+1];
    for(int i=1;i<=n;i++){
        root[i] = NULL;
    }
 
    root[0] = build(0,n-1);
    for(int i=0;i<n;i++){
        if(last[a[i]] != -1){
            root[i+1] = update(root[i],root[i+1],0,n-1,last[a[i]],0);
        }
      //  if(i == 1)
       // debug(root[i+1]->val);
        root[i+1] = update(root[i],root[i+1],0,n-1,i,1);
 
        last[a[i]] = i;
    }
    cin>>q;
    while(q--){
        cin>>l>>r;
        l--;
        r--;
        cout<<query(root[r+1],0,n-1,l,r)<<endl;
    }
    return 0;
}
