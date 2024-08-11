#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,ans;
int a[10][5];

bool check(int p){
    int pa=-1,pb=-1;
    for(int i=0;i<5;i++){
        if(a[9][i]!=a[p][i]){
            if(pa==-1){
                pa=i;
            }
            else if(pb==-1){
                pb=i;
            }
            else{
                return false;
            }
        }
    }
    if(pa==-1){
        return false;
    }
    if(pb==-1){
        return true;
    }
    if(pa!=-1&&pb!=-1&&pb!=(pa+1)){
        return false;
    }
    int na=a[9][pa]-a[p][pa],nb=a[9][pb]-a[p][pb];
    if(na<0){
        na+=10;
    }
    if(nb<0){
        nb+=10;
    }
    if(na!=nb){
        return false;
    }
    return true;
}

signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4];
    }
    for(int i=0;i<5;i++){
        for(int j=1;j<=9;j++){
            a[9][0]=a[1][0];
            a[9][1]=a[1][1];
            a[9][2]=a[1][2];
            a[9][3]=a[1][3];
            a[9][4]=a[1][4];
            a[9][i]=(a[1][i]+j)%10;
            bool flag=true;
            for(int k=1;k<=n;k++){
                flag=flag&&check(k);
            }
            if(flag){
                ans++;
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=1;j<=9;j++){
            a[9][0]=a[1][0];
            a[9][1]=a[1][1];
            a[9][2]=a[1][2];
            a[9][3]=a[1][3];
            a[9][4]=a[1][4];
            a[9][i]=(a[1][i]+j)%10;
            a[9][i+1]=(a[1][i+1]+j)%10;
            bool flag=true;
            for(int k=1;k<=n;k++){
                flag=flag&&check(k);
            }
            if(flag){
                ans++;
            }
        }
    }
    cout<<ans;

    return 0;
}
