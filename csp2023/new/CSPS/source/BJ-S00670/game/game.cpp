#include <bits/stdc++.h>

using namespace std;
char a[2000001],m[2000001];
int Max=0;
int ans;
void xiao(int t1,int t2){
    Max=0;
    for(int i=t1;i<=t2;i++){
        if(Max>(t2-t1+1)/2) return;
        if(a[Max]!=m[i]){
            Max++;
            a[Max]=m[i];
        }else{
            Max--;
        }
    }
    if(Max==0){
        //cout<<t1<<" "<<t2<<endl;
        ans++;
    }
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    cin>>m;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j+=2){
            xiao(i,j);
        }
    }
    cout<<ans<<endl;
    return 0;
}
