#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int a[10001]={};
    int ansa=0,ansb;
    int now=3;
    for(int l=n;l>0;ansa++){
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                continue;
            }
            if(now==3){
                a[i]=1;
                if(i==n){
                    ansb=ansa;
                }
                l--;
                now=0;
            }
            now++;
        }
        now=3;
    }
    cout<<ansa<<' '<<ansb+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}