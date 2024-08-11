#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
const int N=3e3+5;
string s;
int n,m,nm,nmm;
char a[N][N],mn[N],mmn[N];
bool b;
signed main() {
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<m;i++)
        mn[i]=mmn[i]='z';
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sort(a[i],a[i]+m,greater<char>());
        b=true;
        for(int j=0;j<m;j++){
            if(a[i][j]>mn[j]){
                b=false;
                break;
            }
            if(a[i][j]<mn[j]){
                b=true;
                break;
            }
        }
        if(b){
            for(int j=0;j<m;j++){
                mmn[j]=mn[j];
            }
            for(int j=0;j<m;j++){
                mn[j]=a[i][j];
            }
            nmm=nm;
            nm=i;
        }
        else{
            b=true;
            for(int j=0;j<m;j++){
                if(a[i][j]>mmn[j]){
                    b=false;
                    break;
                }
                if(a[i][j]<mmn[j]){
                    b=true;
                    break;
                }
            }
            if(b){
                for(int j=0;j<m;j++){
                    mmn[j]=a[i][j];
                }
                nmm=i;
            }
        }
    }
    for(int i=1;i<=n;i++){
        sort(a[i],a[i]+m);
        if(nm!=i){
            b=true;
            for(int j=0;j<m;j++){
                if(a[i][j]>mn[j]){
                    b=false;
                    break;
                }
                if(a[i][j]<mn[j]){
                    b=true;
                    break;
                }
            }
            if(a[i][m-1]==mn[m-1])
                b=false;
        }
        else{
            b=true;
            for(int j=0;j<m;j++){
                if(a[i][j]>mmn[j]){
                    b=false;
                    break;
                }
                if(a[i][j]<mmn[j]){
                    b=true;
                    break;
                }
            }
            if(a[i][m-1]==mmn[m-1])
                b=false;
        }
        cout<<b;
    }
    return 0;
}
