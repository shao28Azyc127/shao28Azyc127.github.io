#include<iostream>
#include<cstdio>
using namespace std;
struct dat{
    int w,p,c;

};
const int N=1e9 + 7;
dat a[N];
dat cnt;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int zan;
    cin>>zan;
    for(int i=1;i<=N;i++){
        a[i].p=0;
        a[i].w=0;
        a[i].c=0;
    }
    for(int i=1;i<=zan;i++){
        a[i].p=1;
        a[i].w=i;
    }
    if(zan<=3){
        cout<<zan<<" "<<zan;
        return 0;
    }
    for(int i=1;i<=zan;i++){
        for(int j=1;j<=zan;j++){
            if(a[j].p=1){
                cnt.p=a[j].p;
            }
        }
        if(cnt.p=0){
            cnt.w=i;
            break;
        }
        for(int j=1;j<=zan;j++){
            if(a[j].p=1){
                a[j].p=0;
                a[j].c=i;
            }
        }


    }
    cout<<cnt.w<<" "<<a[zan].c;
    return 0;
}
