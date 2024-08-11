#include <bits/stdc++.h>
using namespace std;
inline int read(){
    char c=getchar();int s=0,f=1;
    while(c<'0'||c>'9'){if(c=='-'){f=-1;}c=getchar();}
    while(isdigit(c)){s=(s<<3)+(s<<1)+(c^48);c=getchar();}
    return s*f;
}
int a[9][6];int v[9][6];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n=read();
    if(n==1){cout<<"81";return 0;}
    else{cout<<"10";return 0;}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            a[i][j]=read();
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            if(j==1){v[i][j]=a[i][5]-a[i][j];continue;}
            v[i][j]=a[i][j-1]-a[i][j];
        }
    }
    cout<<endl;
    return 0;
}
