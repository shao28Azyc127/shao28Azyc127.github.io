#include<bits/stdc++.h>
using namespace std;

int k[10][6],ans;

int shu(int id){
    return k[id][1]*10000+k[id][2]*1000+k[id][3]*100+k[id][4]*10+k[id][5]*1;
}

int s[100005];

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    memset(s,0,sizeof(s));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>k[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        s[shu(i)]=-1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            for(int t=1;t<=10;t++){
                k[i][j]++;
                k[i][j]%=10;
                int num=shu(i);
                if(num!=-1) s[num]++;
            }
        }
        for(int j=1;j<=4;j++){
            for(int t=1;t<=10;t++){
                k[i][j]++;
                k[i][j+1]++;
                k[i][j]%=10;
                k[i][j+1]%=10;
                int num=shu(i);
                if(num!=-1) s[num]++;
            }
        }
    }
    for(int i=1;i<=100000;i++){
        if(s[i]==n){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
