#include<bits/stdc++.h>
using namespace std;
const int Nmax=3e3+5;
int n,m;
int a[Nmax];
string w[Nmax];
int cmp(string s,string t){
    for(int u=0;u<m;u++){
        if(s[u]!=t[u]){
            return s[u]>t[u];
        }
    }
    return 0;
}
int main(){
    freopen("dict.in","r",stdin);
    cin>>n>>m;
    if(n==1){
        freopen("dict.out","w",stdout);
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    freopen("dict.out","w",stdout);
    for(int i=1;i<=n;i++){
        int bo=0;
        for(int y=0;y<m;y++){
            a[y]=w[i][y];
        }
        sort(a,a+m);
        for(int y=0;y<m;y++){
            w[i][y]=a[y];
        }
        for(int j=1;j<=n;j++){
            if(j!=i){
                if(cmp(w[j],w[i])==0){
                    for(int o=0;o<m;o++){
                        a[o]=w[j][o];
                    }
                    sort(a,a+m);
                    for(int o=0;o<m;o++){
                    w[j][o]=a[m-1-o];
                    }
                    if(cmp(w[j],w[i])==0){
                        printf("%d",0);
                        bo=1;
                        break;
                    }
                }
            }
        }
        if(bo==0){
            printf("%d",1);
        }
    }
    return 0;
}
