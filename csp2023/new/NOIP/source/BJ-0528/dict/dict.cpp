#include<bits/stdc++.h>
using namespace std;
const int maxn=3005;
/*
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch == '-1') f=-1;ch=getchar()}
    while(ch>='0' && ch<='9'){x=x*10+ch-48;ch=getchar()}
    return x*f;
}
*/

int n,m;
char a[maxn];
int maxx[maxn],minn[maxn];
//int tab[maxn][30];

int main(){

    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);

    cin>>n>>m;
    if(n==1){
        cout<<1;
        return 0;
    }
    memset(minn,0x3f,sizeof(minn));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char x;
            cin>>x;
            int tmp=x-'a';
            minn[i]=min(minn[i],tmp);
            maxx[i]=max(maxx[i],tmp);
 //       tab[i][x-'a']++;
        }
 //       cout<<minn[i]<<" "<<maxx[i]<<endl;
    }
    for(int i=1;i<=n;i++){
        bool flag=true;
        for(int j=1;j<=n;j++){
            if(i == j) continue;
            if(minn[i] >= maxx[j]){
                flag=false;
                break;
            }
        }
        if(flag) cout<<1;
        else cout<<0;
    }
    return 0;
}


