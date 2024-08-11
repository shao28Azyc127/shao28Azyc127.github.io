#include<iostream>
#include<cstdio>
using namespace std;
int c,t;
int n,m,k,d;
struct node{
    int x,y,v;
}a[100005];
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++){
            cin>>a[i].x>>a[i].y>>a[i].v;
        }
        long long nlz=0;
        for(int i=1;i<=m;i++){
            long long l=a[i].x-a[i].y+1;
            if(l>0 and a[i].y<=k){
                nlz=max(nlz,nlz-d*a[i].y+a[i].v);
            }
        }
        cout<<nlz<<endl;
    }
    return 0;
}