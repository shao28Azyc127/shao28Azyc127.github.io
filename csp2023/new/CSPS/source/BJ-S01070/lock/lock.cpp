#include<bits/stdc++.h>
using namespace std;
int n;
int code[10][10];
int judge(int a[], int b[]){
    int dif=0;
    int di[2], di2[2];
    int last=-5;
    if(a[1]!=b[1]) dif++;
    for(int i=2;i<=5;i++){
        if(a[i]!=b[i]){
            dif++;
            if(dif>=3) return 0;
            if(dif==2 & a[i-1]==b[i-1]) return 0;
            if(a[i-1]!=b[i-1]){
                di[0]=a[i-1];
                di[1]=a[i];
                di2[0]=b[i-1];
                di2[1]=b[i];
            }
        }

    }
    if(dif==0) return 0;
    if(dif==1){
        return 1;
    }
    int x=di[1]-di[0], y=di2[1]-di2[0];
    if(x<0){
        x=10+x;
    }
    if(y<0){
        y=10+y;
    }
    if(x==y) return 1;
    return 0;
}
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>code[i][j];
        }
    }
    int res=0;
    for(int i=1;i<=99999;i++){
        int flag=1;
        for(int j=1; j<=n;j++){
            int pas[10]={};
            int k=i;
            int index_=5;
            while(k){
                pas[index_]=k%10;
                k/=10;
                index_--;
            }
            if(!judge(pas, code[j])){
                flag=0;
            }
        }
        if(flag==1){
            res++;
        }
    }
    cout<<res;
    return 0;
}
