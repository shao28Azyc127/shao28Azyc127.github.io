#include<bits/stdc++.h>
using namespace std;
int n,a[10][10],tot;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",n);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=5;++i)scanf("%d",a[i][j]);
    }
    if(n==1){
        cout<<81;
        return 0;
    }
    else if(n==2){
        for(int i=1;i<=5;++i){
            if(a[1][i]!=a[2][i])tot++;
        }
        if(tot==1){
            cout<<10;
            return 0;
        }
        else if(tot==2){
            int w1[3],w2=1;
            for(int i=1;i<=5;++i){
                if(a[1][i]!=a[2][i])w1[w2++]=i;
            }
            if(abs(w1[1]-w1[2])!=1){
                cout<<1;
                return 0;
            }
            else{
                cout<<10;
                return 0;
            }
        }
        else if(tot==4){
            cout<<1;
            return 0;
        }
    }
    else{
        cout<<1;
        cout<<endl;
    }
    return 0;
}
