#include <bits/stdc++.h>
using namespace std;
int B[1];
int game(long long int a,long long int b,string c,int p){
    if(b-a==1){
        if(c[a]==c[b]){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        int yes = 1;
        for(int i=0;(i<=(b-a)/2)&&yes==1;i++){
            if(c[a+i]!=c[b-i]) yes = 0;
        }
        if(yes==1) {
            return 1;
        }
        else{
            int yes=1;
            for(int k=b-a-1;k>=2;k-=2){
                yes = 1;
                for(int i=a;i<b&&yes==1;i+=k){
                    if(i+k-1<=b){
                        if(game(i,i+k-1,c,1)==0) yes=0;
                    }
                    else{
                        for(int j=k-2;j>=2&&i+j-1>=b;j-=2){
                            if(i+j-1==b){
                                if(game(i,i+j-1,c,1)==0) yes = 0;
                            }
                        }
                    }
                }
                if(yes==1) k = 0;
            }
            if(yes==0) return 0;
            else return 1;
        }
    }
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    long long int n,ans;
    ans = 0;
    cin>>n;
    string A;
    cin>>A;
    for(int k=2;k<=n;k+=2){
        for(int i=0;i<=n-k;i++){
            if(game(i,i+k-1,A,0)==1)ans++;
        }
    }
    cout<<ans;
    return 0;
}