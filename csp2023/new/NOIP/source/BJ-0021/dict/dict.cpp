#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3005;
struct Node{
    int id;
    int sum1[30];
}d[N];
string t[N];
int sum[N];
int sum1[N];
int n,m;
bool cmp(Node x,Node y){
    for(int i=25;i>=0;i--){
        if(x.sum1[i]<y.sum1[i])return 1;
        if(x.sum1[i]>y.sum1[i])return 0;
    }
    return 1;
}
bool cmp1(string s1,string s2){
    for(int i=0;i<m;i++){
        if(s1[i]<s2[i])return 1;
        if(s1[i]>s2[i])return 0;
    }
    return 1;
}
bool cmp2(Node x,Node y){
    int lf,rf;
    for(int i=0;i<25;i++){
        if(x.sum1[i]){
            lf=i;
            break;
        }
    }
    for(int i=25;i>=0;i--){
        if(y.sum1[i]){
            rf=i;
            break;
        }
    }
    if(lf<rf)return 1;
    else return 0;
}
int ans[N];
signed main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>t[i];
        for(int j=0;j<=26;j++)sum[j]=0;
        for(int j=1;j<=m;j++){
            sum[t[i][j-1]-'a']++;
        }
        d[i].id=i;
        for(int j=0;j<=25;j++){
            d[i].sum1[j]=sum[j];
        }
    }
    if(n==1){
        cout<<1<<"\n";
        return 0;
    }
    sort(d+1,d+n+1,cmp);
    int limit=n;
    for(int i=2;i<=n;i++){
        bool flag=1;
        for(int j=0;j<=25;j++){
            if(d[i].sum1[j]!=d[i-1].sum1[j])flag=0;
        }
        if(!flag){
            limit=i-1;
            break;
        }
    }
    string min_n=t[d[1].id];
    int min_id=1;
    for(int i=2;i<=limit;i++){
        if(!cmp1(min_n,t[d[i].id])){
            min_n=t[d[i].id];
            min_id=i;
        }
    }
    for(int i=1;i<=n;i++){
        if(i!=min_id){
            ans[d[i].id]=cmp2(d[i],d[min_id]);
        }
        else ans[d[i].id]=1;
    }
    for(int i=1;i<=n;i++)cout<<ans[i];
    cout<<"\n";
    return 0;
}