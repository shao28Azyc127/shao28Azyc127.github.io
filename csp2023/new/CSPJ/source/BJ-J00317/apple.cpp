#include<bits/stdc++.h>
using namespace std;
struct node{
    int nxt,pre;
}a[1000005];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i==1){
            a[i].pre=n;
        }else{
            a[i].pre=i-1;
        }
        if(i==n){
            a[i].nxt=1;
        }else{
            a[i].nxt=i+1;
        }
    }
    int now=1;
    int ls=1;
    int nls;
    int lst=n;
    while(1){
        //cout<<ls<<" "<<now<<" "<<a[now].nxt<<endl;
        if(now==n){
            nls=ls;
        }
        if(lst==now){
            lst=a[now].pre;
        }
        if(a[now].pre==now&&a[now].nxt==now){
            break;
        }
        a[a[now].pre].nxt=a[now].nxt;
        a[a[now].nxt].pre=a[now].pre;
        if(now>=a[now].nxt||a[now].nxt>=a[a[now].nxt].nxt||a[a[now].nxt].nxt>=a[a[a[now].nxt].nxt].nxt){
            now=a[lst].nxt;
            ls++;
        }else{
            now=a[a[a[now].nxt].nxt].nxt;
        }
    }
    //cout<<a[8].nxt<<endl;
    cout<<ls<<" "<<nls;
    return 0;
}
