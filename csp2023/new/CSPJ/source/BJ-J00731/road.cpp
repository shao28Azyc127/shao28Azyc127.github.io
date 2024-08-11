#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,d,x,e,s=0;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>x;
        s+=x;
    }
    for(int i=1;i<=n;i++){
        cin>>x;
        if(i=1){
           e=x;
        }
    }
    if(s%e==0){
        cout<<s/e*d;
    }
    else{
        cout<<s/e*d+d;
    }
    return 0;
}

