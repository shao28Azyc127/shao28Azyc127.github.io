#include <bits/stdc++.h>
using namespace std;

int n,d;
int a[100000];
double b[100000];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    double tot = 0;
    for(int i = 0;i<n-1;i++){
        cin>>a[i];
        tot+=1;
    }
    for(int i = 0;i<n;i++){
        cin>>b[i];


    }

        cout<<ceil(tot / b[1]);




    return 0;
}