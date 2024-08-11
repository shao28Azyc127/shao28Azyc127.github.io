#include<bits/stdc++.h>
using namespace std;
int main(){
int t,m;
cin>>t>>m;
int a[10000],b[10000],c[10000];
for(int i=0;i<t;i++){
    cin>>a[i]>>b[i]>>c[i];
}
for(int i=0;i<t;i++){
if(b[i]==0&&c[i]==0){
    cout<<0;
    }
    else{
    cout<<"NO";
    }
}
return 0;
}
