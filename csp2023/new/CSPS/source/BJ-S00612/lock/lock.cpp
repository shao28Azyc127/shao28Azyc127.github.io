#include <bits/stdc++.h>
using namespace std;
const int N=21;
int n;
int a[N][10];
int hsh[100005];
inline int get_hsh(int x[]){
    int res=0;
    int pw=1;
    for(int j=1;j<=5;j++){
        res+=x[j]*pw;
        pw*=10;
    }
    return res;
}
int tot=0;
int b[15];
inline void solve(int id){

    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            b[j]=a[id][j];
        }
        for(int j=0;j<=9;j++){
            b[i]=j;
            if(hsh[get_hsh(b)]==-1) continue;
            if((hsh[get_hsh(b)])&(1<<id)) continue;
            hsh[get_hsh(b)]|=(1<<id);
        }
    }
    int tmp,tmp1;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=5;j++){
            b[j]=a[id][j];
        }
        tmp=b[i];
        tmp1=b[i+1];
        for(int j=1;j<=9;j++){
            
            b[i]=(tmp+j)%10;
            b[i+1]=(tmp1+j)%10;
            if(hsh[get_hsh(b)]==-1) continue;
            if((hsh[get_hsh(b)])&(1<<id)) continue;
            hsh[get_hsh(b)]|=(1<<id);
        }
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            scanf("%d",&a[i][j]);
        }
        hsh[get_hsh(a[i])]=-1;
    }
    for(int i=1;i<=n;i++){
        solve(i);
    }
    int ans=0;
    int goal=((1<<(n+1))-2);
    for(int i=0;i<=99999;i++){
        if(hsh[i]==-1) continue;
        if(hsh[i]==goal) ans++;
    }
    cout<<ans;
    return 0;
}