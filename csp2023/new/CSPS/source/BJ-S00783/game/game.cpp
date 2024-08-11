
#include<bits/stdc++.h>
using namespace std;
int b;
int main(){
    int n;
    cin>>n;
    string a;
    for(int i=1;i<=n;i++){
        cin<<a;
        if(a[i]==a[i+1])
            b+=2;
    }
    cout<<b;
}
