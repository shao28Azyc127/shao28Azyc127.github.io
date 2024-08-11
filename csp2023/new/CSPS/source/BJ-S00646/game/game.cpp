#include<iostream>
#include<cstdio>
using namespace std;
struct zifu{
    char c;
    int flag=0,a;
}a[2000000];
int n,ans=0,cnt=0,c=1;
char tmp;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    while(n--){
        int flag=0;
        cin>>tmp;
        if(a[cnt].c==tmp){
                ans++;
                cnt--;

                if(a[cnt].flag==1){
                    ans++;

                }
                a[cnt].flag=1;
                flag=1;
            }
        if(flag==0){
            a[++cnt].c=tmp;
            a[cnt].flag=0;
        }


    }
    cout<<ans;
    return 0;
}
