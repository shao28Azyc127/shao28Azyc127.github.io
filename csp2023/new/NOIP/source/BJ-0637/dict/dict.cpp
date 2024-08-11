#include <bits/stdc++.h>
using namespace std;
const int N=3e3+5;
int n,m;
char s[N][N];
int a[N];
bool f[N];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    if(n==1){
        cout<<"1";
        return 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>s[i][j];
        }
    }
    if(m==1){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(s[i]<s[j]){
                    a[i]=1;
                    f[i]=true;
                    break;
                }
            }
            if(f[i]==true) break;
            else{
                f[i]=false;
                a[i]=0;
            }
        }
        for(int i=1;i<=n;i++){
            cout<<a[i];
        }
    }

    return 0;
}
