#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[1000010];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,cnt=0,i;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i].ch;
    }
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            int b[1000010]={},q=0;
            for(x=i;x<=j;x++){
                q++;
                b[q]=a[x];
                if(b[q]==b[q-1]){
                    q-=2;
                }
            }
            if(q==0){
                cnt++;
            }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
