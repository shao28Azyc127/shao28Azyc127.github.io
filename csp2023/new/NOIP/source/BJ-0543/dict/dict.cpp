#include<bits/stdc++.h>
using namespace std;
const int N=3010;
int n,m;
struct node{
    char s[N],smax[N];
    int id;
}a[N];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        a[i].id=i;
        cin>>a[i].s;
        sort(a[i].s,a[i].s+m);
    }
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=m-1;j>=0;j--){
            a[i].smax[cnt++]=a[i].s[j];
        }
    }
    for(int i=1;i<=n;i++){
        bool flag=1;
        for(int j=1;j<=n;j++){
            for(int k=0;k<m;k++){
                if(a[i].s[k]>a[j].smax[k]){flag=0;break;}
                if(a[i].s[k]<a[j].smax[k]){break;}
            }
            if(!flag){break;}
        }
        if(!flag){cout<<0;continue;}
        cout<<1;
    }
    return 0;
}
