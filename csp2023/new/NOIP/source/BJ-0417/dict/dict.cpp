#include<bits/stdc++.h>
using namespace std;
struct zyz{
    string s,s1,s2;
}a[3001];
int n,m,c[3001];
string Big(string x){
    memset(c,0,sizeof(c));
    for(int i=1;i<=m;i++)c[i]=int(x[i-1]);
    sort(c+1,c+m+1);
    for(int i=1;i<=m;i++)x[i-1]=char(c[i]);
    return x;
}string Small(string x){
    memset(c,0,sizeof(c));
    for(int i=1;i<=m;i++)c[i]=int(x[i-1]);
    sort(c+1,c+m+1);
    for(int i=m;i>=1;i--)x[m-i]=char(c[i]);
    return x;
}bool bida(string x,string y){
    for(int i=0;i<m;i++){
        if(x[i]>y[i])return 0;
        if(y[i]>x[i])return 1;
    }
    return 0;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)cin>>a[i].s;
    if(n==1){
        printf("1");
        return 0;
    }if(m==1){
        int mx=2147483647,mxnum=0,mxshu=0;
        for(int i=1;i<=n;i++){
            if(a[i].s[0]<mx){
                mx=a[i].s[0];
                mxnum=i;
                mxshu=1;
            }else if(a[i].s[0]==mx)++mxshu;
        }
        if(mxshu>1){
            for(int i=1;i<=n;i++)printf("0");
        }if(mxshu==1){
            for(int i=1;i<mxnum;i++)printf("0");
            printf("1");
            for(int i=mxnum+1;i<=n;i++)printf("0");
        }
        return 0;
    }for(int i=1;i<=n;i++){
        a[i].s1=Big(a[i].s);
        a[i].s2=Small(a[i].s);
    }for(int i=1;i<=n;i++){
        bool lzp=0;
        for(int j=1;j<=n;j++){
            if(j==i)continue;
            if(!bida(a[i].s1,a[j].s2)){
                lzp=1;
                break;
            }
        }
        if(lzp==0)printf("1");
        if(lzp==1)printf("0");
    }
    return 0;
}
