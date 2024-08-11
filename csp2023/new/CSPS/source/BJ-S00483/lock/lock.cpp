#include<iostream>
using namespace std;
int n,cnt=0;
struct node{
    int a,b,c,d,e;
}t[10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i].a>>t[i].b>>t[i].c>>t[i].d>>t[i].e;
    }
    if(n==1){
        cout<<81;
        return 0;
    }
    for(int i=2;i<=n;i++){
        if(t[i-1].a!=t[i].a) cnt+=10;
        if(t[i-1].b!=t[i].b) cnt+=10;
        if(t[i-1].c!=t[i].c) cnt+=10;
        if(t[i-1].d!=t[i].d) cnt+=10;
        if(t[i-1].e!=t[i].e) cnt+=10;

        if(t[i-1].a!=t[i].a&&t[i-1].a-t[i].a==t[i-1].b-t[i].b&&t[i-1].a-t[i].a!=0) cnt+=10;
        if(t[i-1].b!=t[i].a&&t[i-1].b-t[i].b==t[i-1].c-t[i].c&&t[i-1].b-t[i].b!=0) cnt+=10;
        if(t[i-1].c!=t[i].c&&t[i-1].c-t[i].c==t[i-1].d-t[i].d&&t[i-1].c-t[i].c!=0) cnt+=10;
        if(t[i-1].d!=t[i].d&&t[i-1].d-t[i].d==t[i-1].e-t[i].e&&t[i-1].d-t[i].d!=0) cnt+=10;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}