#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=10;

ifstream fin("lock.in");
ofstream fout("lock.out");
int n;
int a[maxn][6];

int b[90][6];
bool f[90];
int c[6],d[6];

int add(int x,int y){
    return x+y>=10?x+y-10:x+y;
}

bool check(int k,int id){
    for(int p=1;p<=5;p++)
        c[p]=b[id][p];
    for(int p=1;p<=5;p++)
        d[p]=a[k][p];
    int p1=0,p2=0;
    for(int i=1;i<=5;i++){
        if(c[i]!=d[i]){
            if(p1==0)
                p1=i;
            else if(p2==0)
                p2=i;
            else
                return 0;
        }
    }
    if(p1==0)
        return 0;
    if(p2==0)
        return 1;
    if(p1+1!=p2)
        return 0;
    return add(c[p1],d[p2])==add(d[p1],c[p2]);
}

int main(){
    ios::sync_with_stdio(0);
    fin>>n;
    if(n==1){
        fout<<81<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            fin>>a[i][j];
    for(int i=1;i<=81;i++){
        for(int j=1;j<=5;j++)
            b[i][j]=a[1][j];
    }
    int id=0;
    for(int p=1;p<=5;p++){
        for(int x=1;x<=9;x++){
            id++;
            b[id][p]=add(b[id][p],x);
        }
    }
    for(int p=1;p<=4;p++){
        for(int x=1;x<=9;x++){
            id++;
            b[id][p]=add(b[id][p],x);
            b[id][p+1]=add(b[id][p+1],x);
        }
    }
    for(int i=1;i<=81;i++)
        f[i]=1;
    for(int i=2;i<=n;i++){
        for(id=1;id<=81;id++){
            if(f[id]==0)
                continue;
            if(check(i,id)==0)
                f[id]=0;
        }
    }
    int ans=0;
    for(int i=1;i<=81;i++){
        if(f[i]){
            // for(int p=1;p<=5;p++)
                // cout<<b[i][p]<<' ';
            // cout<<endl;
            ans++;
        }
    }
    fout<<ans<<endl;

    return 0;
}