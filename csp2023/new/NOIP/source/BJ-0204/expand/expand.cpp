#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
const int maxn1=4e4+10;
const int maxq=65;

int C,nn,mm,q;
int tx[maxn],ty[maxn];
int xx[maxn],yy[maxn];
bitset <maxn1> f[2];
bool ans[maxq];
int n,m;
int x[maxn],y[maxn];
bool sw=0;

ifstream fin("expand.in");
ofstream fout("expand.out");

void dp(int t){
    if((ll)(xx[1]-yy[1])*(xx[nn]-yy[mm])<=0)
        ans[t]=0;
    else{
        if(xx[1]<yy[1])
            sw=1;
        else
            sw=0;
        if(sw){
            n=mm;m=nn;
            for(int i=1;i<=n;i++)
                x[i]=yy[i];
            for(int i=1;i<=m;i++)
                y[i]=xx[i];
        }
        else{
            n=nn;m=mm;
            for(int i=1;i<=n;i++)
                x[i]=xx[i];
            for(int i=1;i<=m;i++)
                y[i]=yy[i];
        }
            
        for(int i=1;i<=m;i++)
            f[0][i]=f[1][i]=0;
        f[0][0]=1;
        for(int i=1;i<=n;i++){
            f[i&1][0]=0;
            for(int j=1;j<=m;j++){
                if(x[i]>y[j])
                    f[i&1][j]=f[i&1][j-1]|f[(i&1)^1][j-1]|f[(i&1)^1][j];
                else
                    f[i&1][j]=0;
            }
            if(t==-1){
                for(int j=0;j<=m;j++)
                    cout<<f[i&1][j]<<' ';
                cout<<endl;
            }
        }
        ans[t]=f[n&1][m];
    }
}

int main(){
    ios::sync_with_stdio(0);
    fin.tie(0);fout.tie(0);
    fin>>C>>nn>>mm>>q;
    for(int i=1;i<=nn;i++)
        fin>>tx[i];
    for(int i=1;i<=mm;i++)
        fin>>ty[i];
    
    for(int i=1;i<=nn;i++)
        xx[i]=tx[i];
    for(int i=1;i<=mm;i++)
        yy[i]=ty[i];
    dp(0);
    for(int t=1;t<=q;t++){
        int kx,ky;
        int p,v;
        fin>>kx>>ky;
        for(int i=1;i<=nn;i++)
            xx[i]=tx[i];
        for(int i=1;i<=mm;i++)
            yy[i]=ty[i];
        for(int i=1;i<=kx;i++){
            fin>>p>>v;
            xx[p]=v;
        }
        for(int i=1;i<=ky;i++){
            fin>>p>>v;
            yy[p]=v;
        }
        dp(t);
    }
    for(int i=0;i<=q;i++)
        fout<<ans[i];
    fout<<endl;

    return 0;
}