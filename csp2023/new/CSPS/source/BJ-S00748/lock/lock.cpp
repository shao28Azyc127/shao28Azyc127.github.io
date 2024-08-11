#include<bits/stdc++.h>
using namespace std;
int n,a[9][6],ans,b[6];
int abs(int a,int b){
    if(a-b<0){
        return b-a;
    }
    else{
        return a-b;
    }
}
void dfs(int k,int b[]){
    if(k!=5){
        for(int i=b[k];i<=9;i++){
            b[k]=i;
            dfs(k+1,b);
        }
    }
    else{
        int flag=0,ch=0;
        bool db=false;
        for(int i=1;i<=n;i++){
            int wr=-1;
            for(int j=1;j<=5;j++){
                if(b[j]!=a[i][j]){
                    if(db==true){
                        flag++;
                        break;
                    }
                    else if(j-1==wr&&db==true){
                        if(abs(b[j],a[i][j])!=ch){
                            flag++;
                            break;
                        }
                    }
                    else if(j-1==wr){
                        db=true;
                        ch=abs(b[j],a[i][j]);
                    }
                    else if(wr!=-1){
                        flag++;
                        break;
                    }
                    else{
                        wr=j;
                    }
                }
            }
        }
        if(flag==n){
            ans++;
        }
    }
    return;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    if(n==1){
        cout<<"81";
        return 0;
    }
    dfs(1,b);
    cout<<ans;
    return 0;
}
