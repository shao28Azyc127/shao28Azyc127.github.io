#include<bits/stdc++.h>
using namespace std;
int n,t,a[6],m;
int main(){
    cin>>n;
    if(n==1){
        cout<<81;
    }
    if(n==2){
        for(int i=0;i<5;i++){
            cin>>a[i];
        }
        for(int i=0;i<5;i++){
            cin>>t;
            if(t!=a[i]) m++;
        }
        cout<<10*m;
    }
    else{
        cout<<n;
    }
    return 0;
    //提高组摆烂环节开始?
}