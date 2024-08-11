#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
char x[100005];
int f[100005];
bool d[100005][100005];
int n;
int find(int a){
    if(f[a]==a){
        return a;
    }else{
        return f[a]=find(f[a]);
    }
}
bool floyd(int y){
    int i,j,k;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            for(k=1;k<=n;k++){
                    if(d[i][k]+d[k][j]==1){
                        d[i][j]=1;
                    }
                }
            }
         for(j=1;j<=n;j++){
            if(d[y][i]==1&&d[y][j]==1&&d[i][j]==1){
                return 1;
            }
         }
    }
    return 0;
}
int main(){
    int z,c,t,i,m,o,p,ans=0;
    char v;
    freopen("r","tribool.in",stdin);
    freopen("w","tribool.out",stdout);
    cin>>c>>t;
    for(z=0;z<t;z++){
        ans=0;
        cin>>n>>m;
        for(i=1;i<=n;i++){
            f[i]=i;
        }
        for(i=1;i<=m;i++){
            cin>>v;
            if(v=='T'||v=='U'||v=='F'){
                cin>>o;
                x[o]=v;
            }
            if(v=='+'){
                cin>>o>>p;
                f[o]=find(f[p]);
            }
            if(v=='-'){
                cin>>o>>p;
                f[o]=find(f[p]);
                d[o][p]=1;
                d[p][o]=1;
            }
            for(i=1;i<=n;i++){
                if(x[find(f[i])]=='U'){
                    ans++;
                }
                if(x[find(f[i])]==0&&floyd(i)!=0){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
 return 0;
}
