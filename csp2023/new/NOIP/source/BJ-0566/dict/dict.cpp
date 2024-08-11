#include <iostream>
using namespace std;
const int N=3010;
int a[N][30];
int s[N][30];
int b[N];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char tmp;
            cin>>tmp;
            a[i][tmp-'a']++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int k=0;k<=25;k++){
            s[i][k]=s[i][k-1]+a[i][k];
        }
    }
    for(int i=1;i<=n;i++){
        for(int k=0;k<=25;k++){
            if(a[i][k]==0) continue;
            b[i]=k;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        bool flag=true;
        for(int j=1;j<=n;j++){
            if(!flag) break;
            if(i==j) continue;
            if(s[j][25]-s[j][b[i]]==0) flag=false;
        }
        if(flag) cout<<"1";
        else cout<<"0";
    }
    cout<<endl;
    return 0;
}
