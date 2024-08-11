#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string a;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n>>a;
    if(n%2==0){
        bool flag=true;
        for(int i=0;i<n/2;i++){
            if(a[i]!=a[n-1-i]) flag=false;
        }
        if(flag) cout<<n/2;
        else{
            int ans=0;
            while(a.length()>0){
                int i=0;
                while(i<a.length()){
                    if(a[i]==a[i+1]){
                        ans++;
                        a.erase(i,i+1);
                        i+=2;
                    }else i++;
                }
            }
            cout<<ans+n/2-1;
        }
    }else{
        int ans=0;
        while(a.length()>0){
            int i=0;
            while(i<a.length()){
                if(a[i]==a[i+1]){
                    ans++;
                    a.erase(i,i+1);
                    i+=2;
                }else i++;
            }
        }
        cout<<ans;
    }

    return 0;
}
