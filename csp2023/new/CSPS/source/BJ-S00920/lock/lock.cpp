#include<iostream>
#include<cstdio>
#define fup(f,s,e) for(int f=s;f<=e;f++)
using namespace std;
int n,a[10][5],ans;
int f(int x,int y){
    if(y>x){
        return y-x;
    }
    return 9-x+y+1;
}
bool check(int i,int j,int k,int l,int m){
    for(int x=1;x<=n;x++){
        if(i==a[x][0] and j==a[x][1] and k==a[x][2] and l==a[x][3] and m==a[x][4]){
            return false;
        }
        if(j==a[x][1] and k==a[x][2] and l==a[x][3] and m==a[x][4] or 
           i==a[x][0] and k==a[x][2] and l==a[x][3] and m==a[x][4] or 
           i==a[x][0] and j==a[x][1] and l==a[x][3] and m==a[x][4] or 
           i==a[x][0] and j==a[x][1] and k==a[x][2] and m==a[x][4] or 
           i==a[x][0] and j==a[x][1] and k==a[x][2] and l==a[x][3] or 
           k==a[x][2] and l==a[x][3] and m==a[x][4] and (f(i,a[x][0])==f(j,a[x][1]) or f(a[x][0],i)==f(a[x][1],j)) or 
           i==a[x][0] and l==a[x][3] and m==a[x][4] and (f(j,a[x][1])==f(k,a[x][2]) or f(a[x][1],j)==f(a[x][2],k)) or 
           i==a[x][0] and j==a[x][1] and m==a[x][4] and (f(k,a[x][2])==f(l,a[x][3]) or f(a[x][2],k)==f(a[x][3],l)) or 
           i==a[x][0] and j==a[x][1] and k==a[x][2] and (f(l,a[x][3])==f(m,a[x][4]) or f(a[x][3],l)==f(a[x][4],m))){
            // i=a[x][0];
            // j=a[x][1];
            // k=a[x][2];
            // l=a[x][3];
            // m=a[x][4];
        }else{
            return false;
        }
    }
    return true;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    fup(i,1,n){
        cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4];
    }
    fup(i,0,9){
        fup(j,0,9){
            fup(k,0,9){
                fup(l,0,9){
                    fup(m,0,9){
                        if(check(i,j,k,l,m)){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}