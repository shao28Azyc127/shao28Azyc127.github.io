#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,a,s=0;
    float s2;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n-1;i++){
        cin>>a;
        s+=a;
    }
    cin>>a;
    if(s/m!=int(s/m)){
        cout<<int(s/m)+1;
    }
    else{
        cout<<int(s/m);
    }
    fclose(stdin);
    fclose(stdout);



    return 0;
}
