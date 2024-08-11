#include<iostream>
#include <cstdio>
#include <cstring>
//#define ll long long
using namespace std;
long long n,cnt=0,a[15][15],gz[15];
/*
bool check(int f){//a[f],gz[]
    int cntx=0;
    for(int i=1;i<=5;i++){
        if(a[f][i]!=gz[i]){
            cntx++;
        }
    }
    if(cntx>2||cntx<1){
        return 0;
    }
    if(cntx==1){
        return 1;
    }else {
        for(int i=1;i<5;i++){
            if(a[f][i]!=gz[i]&&a[f][i+1]!=gz[i+1]){
                if(a[f][i]-gz[i]==a[f][i+1]-gz[i+1]){
                    return 1;
                }
            }
        }
    }
}*/
void dfs(long long p){
    if(p>5){
        for(int i=1;i<=n;i++){
            int cntx=0;
            bool flag=0;
            for(int j=1;j<=5;j++){
                if(a[i][j]!=gz[j]){
                    cntx++;
                }
            }
            if(cntx>2||cntx<1){
                flag=0;
            }else if(cntx==1){
                flag=1;
            }else {
                for(int j=1;j<5;j++){
                    if(a[i][j]!=gz[j]&&a[i][j+1]!=gz[j+1]){
                        bool flag1=0,flag2=0;
                        if(gz[j]<a[i][j]){
                            gz[j]+=10;
                            flag1=1;
                        }
                        if(gz[j+1]<a[i][j+1]){
                            gz[j+1]+=10;
                            flag2=1;
                        }
                        if(a[i][j]-gz[j]==a[i][j+1]-gz[j+1]){
                            flag=1;
                        }
                        if(flag1){
                            gz[j]-=10;
                        }
                        if(flag2){
                            gz[j+1]-=10;
                        }
                    }
                }
            }
            if(flag==0){
                return;
            }
        }
        //cout<<gz[1]<<' '<<gz[2]<<' '<<gz[3]<<' '<<gz[4]<<' '<<gz[5]<<endl;
        cnt++;
        return;
    }
    for(int i=0;i<=9;i++){
        gz[p]=i;
        dfs(p+1);
    }
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
    dfs(1);
    cout<<cnt<<endl;
    return 0;
}
