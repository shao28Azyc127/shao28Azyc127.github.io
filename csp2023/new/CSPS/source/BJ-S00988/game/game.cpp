#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string a;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    cin>>a;
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
    return 0;
}