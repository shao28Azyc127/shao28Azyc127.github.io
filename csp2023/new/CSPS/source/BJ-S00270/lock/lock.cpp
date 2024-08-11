#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n],b[n],c[n],d[n],e[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];
    }
    int fool=0;
    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(a[i]==a[j]) fool++;
            if(b[i]==b[j]) fool++;
            if(c[i]==c[j]) fool++;
            if(d[i]==d[j]) fool++;
            if(e[i]==e[j]) fool++;
        }
    }
    cout<<81-fool;
    return 0;
}