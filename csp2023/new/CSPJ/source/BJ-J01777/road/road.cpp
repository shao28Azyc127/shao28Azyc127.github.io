#include<iostream>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    long long suma=0;
    int a[n-1];
    int b[n];
    for(int i=0;i<n-1;i++){
    cin>>a[i];
    }
    for(int i=0;i<n;i++){
    cin>>b[i];
    }
    for(int i=0;i<n-1;i++){
    suma+=a[i];
    }
    if(suma%b[0]==0){
    cout<<suma/b[0];
    }
    else{
    cout<<suma/b[0]+1;
    }
    return 0;
}
