#include<bits/stdc++.h>
using namespace std;
int a[11][10];
int vis[11];
int ans[6];
int n;
bool check(int s,int l){
    for(int i=1;i<=n;i++){
        for(int j=s;j<=s+l-2;j++){
            if(i==1){
                ans[j]=a[i][j]-a[i][j+1];
            }else{
                if(a[i][j]-a[i][j+1]!=ans[j]){
                    return 0;
                }
            }
        }
    }
    return 1;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++)
        cin>>a[i][j];
    }
    if(n==1){
        cout<<"81"<<endl;
    }else{
        int d=0;
        bool fflag=0;
        for(int i=1;i<=5;i++){
            fflag=0;
            for(int j=1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    if(a[j][i]!=a[z][i]&&fflag==0){
                        fflag=1;
                        vis[i]=1;
                        d++;
                    }
                }
            }
        }
        if(d==0){
            cout<<"81"<<endl;
            exit(0);
        }else if(d==1){
            cout<<"10"<<endl;
            exit(0);
        }else if(d==2){
            bool flag;
            for(int i=1;i<=5-d+1;i++){
                flag=1;
                for(int j=i;j<=i+d-1;j++){
                    if(vis[j]!=1)flag=0;
                }
                if(flag==1&&check(i,d)){
                    cout<<"10";
                    exit(0);
                }
            }
        }
        cout<<"0"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
