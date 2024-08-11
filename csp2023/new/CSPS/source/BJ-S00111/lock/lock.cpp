#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=8+2,M=5+2;
//idea: find all the possible combinations and check if they are ok
int a[N][M];
int now[N];
int n;
/*

*/
bool check(int A,int b,int c,int d,int e){
    /*
    how to check if they are ok?
    1.if n=1 then if a,b,c,d,e has 2/more different from a[i] and the different isn't near each other
        or it doesn't has the same amount -> false 
        else: true
    2.if n=2:
    we have the following sequence:  28350 28352 28353 28354 28356 28357 28358 28359 28311 28395
    28355
    28351
    so,we just have to check if it is all possible.
    */
    int d1,pc,tw;
    now[1]=A;now[2]=b;now[3]=c;now[4]=d;now[5]=e;
    for(int i=1;i<=n;i++){
        d1=pc=tw=0;
        for(int j=1;j<=5;j++){
            if(now[j]!=a[i][j]){
                if((pc!=0&&pc!=j-1)||tw)return false;
                if(pc==j-1&& j!=1){
                    tw=1;
                    if(d1!=(a[i][j]-now[j])&& d1!=(a[i][j]-now[j])-10) return false;
                }
                else{
                    pc=j;
                    d1=(a[i][j]-now[j]);//pianyiliang
                }
            }
        }
        if(!d1&&!pc)return false;//same
    }
   //cerr<<A<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
    return true;
    
}
signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }    
    ll ans=0;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                for(int l=0;l<=9;l++){
                    for(int m=0;m<=9;m++){
                        ans+=check(i,j,k,l,m);
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}