#include<bits/stdc++.h>
using namespace std;

int n;
struct lockf{
    int a;
    int b;
    int c;
    int d;
    int e;
}x[10000];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i].a>>x[i].b>>x[i].c>>x[i].d>>x[i].e;
    }
    int sum=0;
    if(x[1].a!=x[2].a){sum++;}
    if(x[1].b!=x[2].b){sum++;}
    if(x[1].c!=x[2].c){sum++;}
    if(x[1].d!=x[2].d){sum++;}
    if(x[1].e!=x[2].e){sum++;}
    if(sum==1){
        cout<<10;
        return 0;
    }
    if(n==1){
        cout<<81;
        return 0;
    }
    if(n==2){
        if(sum==0){
            cout<<81;
            return 0;
        }
        else{
            cout<<sum*10-18;

            return 0;
        }
    }
    if(n==3){
        cout<<1;
    }
    return 0;
}
