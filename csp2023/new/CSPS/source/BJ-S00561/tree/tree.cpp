#include<bits/stdc++.h>
#define maxn 100001
using namespace std;
int a[maxn],b[maxn],c[maxn];
int u[maxn],v[maxn],w[maxn];
int sum[maxn];
int ans[maxn];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    cin>>n;
    bool flag1=1,flag2=1,flag3=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        if(c[i]!=0)flag1=0;
    }
    for(int i=1;i<=n-1;i++){
        cin>>u[i]>>v[i]>>w[i];
        if(u[i]!=i||v[i]!=i+1)flag2=0;
        if(u[i]!=1)flag3=0;
    }

        int d=1;
        int mmax=0;
        for(int i=1;i<=n;i++){
            d=i;
            while(sum[i]<a[i]){
                sum[i]+=max(b[i]+d*c[i],1);
                ans[i]=d;
                d++;
            }
            mmax=max(mmax,d);
        }
        cout<<mmax<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
