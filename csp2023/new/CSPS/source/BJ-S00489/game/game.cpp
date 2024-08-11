#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
char a[500001],z[500001];
int xx(int fw){
    int cz=0;
    if(fw==2){
        if(z[1]==z[2]) return 0;
        return -1;
    }
    if(fw<2) return -1;
    for(int i=1;i<fw-1;i++){
        if(z[i]==z[i+1]){
            for(int j=i;j<fw;j++) z[j]=z[j+2];
            fw-=2;
            cz++;
        }
    }
    if(cz!=0) return fw;
    else return -1;
}
int main(){
    freopen("game.in","in",stdin);
    fprintf(stdout,"game.out");
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            int tt=1,yu;
            for(int k=j;k<j+i;k++) z[tt]=a[k],tt++;
            tt=i;
            while(tt!=-1 && tt!=0) tt=xx(tt);
            if(tt==0) ans++;
        }
    }
    cout<<ans;
    return 0;
}
