#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int a[512345],b[512435],a1[512345],b1[512345],f[2001][2001],f1[2001][2001];
int c,n,m,q;
bool dfs(int x,int y){//a>b
    if(y==m+1){
        bool o=1;
        for(int i=x;i<=n;i++)
        if(a[i]<=b[m]){
            o=0;break;
        }
        return o;
    }
    bool o=0;
    for(int i=x;i<=n;i++)
    {
        if(a[i]<=b[y])   break;
        o=o|dfs(i,y+1);
    }
    return o;
}
bool dfs1(int x,int y){//a<b
    if(y==m+1){
        bool o=1;
        for(int i=x;i<=n;i++)
        if(a[i]>=b[m]){
            o=0;break;
        }
        return o;
    }
    bool o=0;
    for(int i=x;i<=n;i++)
    {
        if(a[i]>=b[y])   break;
        o=o|dfs1(i,y+1);
    }
    return o;
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    if(c<=4){
        cout<<(dfs(1,1)|dfs1(1,1));
        for(int j=1;j<=n;j++)   a1[j]=a[j];
        for(int j=1;j<=m;j++)   b1[j]=b[j];
        for(int i=1;i<=q;i++){
            for(int j=1;j<=n;j++)   a[j]=a1[j];
            for(int j=1;j<=m;j++)   b[j]=b1[j];
            int k1,k2,p,v;
            cin>>k1>>k2;
            for(int j=1;j<=k1;j++)
            {
                cin>>p>>v;
                a[p]=v;
            }
            for(int j=1;j<=k2;j++)
            {
                cin>>p>>v;
                b[p]=v;
            }
            cout<<(dfs(1,1)|dfs1(1,1));
        }
        cout<<endl;
        return 0;
    }
//    for(int i=1;i<=n;i++)   cout<<a[i]<<" ";
//    cout<<endl;
//    for(int j=1;j<=m;j++)   cout<<b[j]<<" ";
//    cout<<endl;
    if(c<=7){
//            cout<<"YDE"<<endl;
        f[0][0]=1;
        f1[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                if(a[i]<b[j])   f[i][j]=(f[i-1][j]|f[i][j-1]|f[i-1][j-1]);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                if(a[i]>b[j])   f1[i][j]=(f1[i-1][j]|f1[i][j-1]|f1[i-1][j-1]);
        }
        cout<<(f[n][m]|f1[n][m]);
//        for(int i=1;i<=n;i++)
//            for(int j=1;j<=m;j++)
//                cout<<"I"<<i<<" "<<"J"<<j<<" "<<f1[i][j]<<endl;
        for(int j=1;j<=n;j++)   a1[j]=a[j];
        for(int j=1;j<=m;j++)   b1[j]=b[j];
        for(int i=1;i<=q;i++){
            for(int j=1;j<=n;j++)   a[j]=a1[j];
            for(int j=1;j<=m;j++)   b[j]=b1[j];
            int k1,k2,p,v;
            cin>>k1>>k2;
            for(int j=1;j<=k1;j++)
            {
                cin>>p>>v;
                a[p]=v;
            }
            for(int j=1;j<=k2;j++)
            {
                cin>>p>>v;
                b[p]=v;
            }
            for(int j=1;j<=n;j++)
                for(int k=1;k<=m;k++)
                    f[j][k]=0,f1[j][k]=0;
            f[0][0]=1;
            f1[0][0]=1;
            for(int j=1;j<=n;j++){
                for(int k=1;k<=m;k++)
                    if(a[j]<b[k])   f[j][k]=(f[j-1][k]|f[j][k-1]|f[j-1][k-1]);
            }
            for(int j=1;j<=n;j++){
                for(int k=1;k<=m;k++)
                    if(a[j]>b[k])   f1[j][k]=(f1[j-1][k]|f1[j][k-1]|f1[j-1][k-1]);
            }
//            if(i==2){
//                for(int j=1;j<=n;j++)   cout<<a[j]<<" ";
//                cout<<endl;
//                for(int j=1;j<=m;j++)   cout<<b[j]<<" ";
//                cout<<endl;
//                for(int j=1;j<=n;j++)
//                    for(int k=1;k<=m;k++)
//                        cout<<"I"<<j<<" "<<"J"<<k<<" "<<f1[j][k]<<endl;;
//            }
            cout<<(f[n][m]|f1[n][m]);
        }
    }
//    if(c>=8&&c<=14){
//
//    }
    return 0;
}
