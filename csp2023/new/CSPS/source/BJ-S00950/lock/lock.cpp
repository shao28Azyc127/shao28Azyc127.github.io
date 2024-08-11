#include <bits/stdc++.h>
#define ll long long
#define ldb long double
using namespace std;
int n;
bool fl;
int st[10][10],di[10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>st[i][j];
        }
    }
    int cnt=0;
    if(n==1){
        printf("%d\n",5*9+4*9);
        return 0;
    }
    for(int i=1;i<=5;i++){
        for(int j=1;j<n;j++){
            if(st[j][i]!=st[j+1][i]){di[cnt++]=i;break;}
        }
    }
    for(int i=0;i<cnt-1;i++){
        if(di[i+1]-di[i]>1) fl=0; 
    }
    cout<<cnt;
    if(cnt>2||fl==0){
        printf("%d\n",0);
        return 0;
    }
    // 1
    int tmp;
    if(cnt==1){
        printf("%d\n",10);
        return 0;
    }else{
        tmp=st[1][di[0]]-st[1][di[1]];
        for(int i=1;i<=n;i++){
            if(st[i][di[0]]-st[i][di[1]]!=tmp){
                printf("%d\n",0);
                return 0;
            }
        }
        printf("%d\n",10);
        return 0;
    }
    return 0;
}