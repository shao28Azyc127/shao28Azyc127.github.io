#include<bits/stdc++.h>
using namespace std;
const int N=11;
int n;
int a[N][6];
unordered_map<int,int> st[N];
int b[N];
int getval(){
    int res=0;
    for(int i=1;i<=5;i++){
        res*=10;
        res+=b[i];
    }
    return res;
}
int ans;
void dfs(int x){
    if(x>5){
        int cnt=getval();
        for(int i=1;i<=n;i++){
            if(st[i][cnt]!=1) return;
        }
        ans++;
        return;
    }
    for(int i=0;i<10;i++){
        b[x]=i;
        dfs(x+1);
    }
}
signed main(){
    //freopen!!!
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
            b[j]=a[i][j];
        }
        //yi ge
        for(int j=1;j<=5;j++){
            for(int k=1;k<=9;k++){
                int cnt=b[j];
                b[j]=(b[j]+k)%10;
                st[i][getval()]=1;
                b[j]=cnt;
            }
        }

        for(int j=1;j<=4;j++){
            for(int k=1;k<=9;k++){
                int cnt1=b[j],cnt2=b[j+1];
                b[j]=(b[j]+k)%10;
                b[j+1]=(b[j+1]+k)%10;
                st[i][getval()]=1;
                b[j]=cnt1;
                b[j+1]=cnt2;
            }
        }
    }

    dfs(1);
    cout<<ans<<endl;
    return 0;
}
