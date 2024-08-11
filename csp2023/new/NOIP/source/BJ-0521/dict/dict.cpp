#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[3005][3005];
int mi[3005];
int mii;
int mic=0;
int sm[3005];
int b[3005];
int n,m;
bool cmp(int x,int y){
    for(int i=1;i<=m;i++){
        if(a[x][i]<a[y][i])
            return 1;
        if(a[x][i]>a[y][i])
            return 0;
    }
}
bool c1(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(false);
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    for(int i=1;i<=m;i++){
        mi[i]=50;
    }
    for(int i=1;i<=n;i++){
        int mia=2e9;
        int cnt=0;
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            a[i][j]=c-'a'+1;
            b[j]=a[i][j];
            if(a[i][j]<mia){
                mia=a[i][j];
                cnt=1;
            }else if(a[i][j]==mia)
                cnt++;
        }
        if(mia>mi[1])
            continue;
        if(mia==mi[1]&&cnt<mic)
            continue;
        sort(b+1,b+m+1,c1);
        bool flag=0;
        for(int j=1;j<=m;j++){
            if(b[j]<mi[j]){
                flag=1;
                break;
            }
            if(b[j]>mi[j]){
                break;
            }
        }
        if(flag){
            for(int j=1;j<=m;j++){
                mi[j]=b[j];
            }
            mii=i;
            mic=cnt;
        }
    }
    for(int i=1;i<=n;i++){
        bool flag=0;
        for(int j=1;j<=m;j++)
            b[j]=a[i][j];
        sort(b+1,b+m+1);
        if(i==mii){
            cout<<1;
            continue;
        }
        for(int j=1;j<=m;j++){
            if(b[j]<mi[j]){
                cout<<1;
                flag=1;
                break;
            }
            if(b[j]>mi[j]){
                cout<<0;
                flag=1;
                break;
            }
        }
        if(!flag)
            cout<<0;
    }
    cout<<endl;
    return 0;
}
