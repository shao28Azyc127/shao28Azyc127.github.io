#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    double a[100100];
    int b[100100];
    int n,d,y=0,s=0,c;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        if(y*d<a[i]){
            c=a[i]-y*d;
            c=c%d;
            s=s+c*b[i];
            y+=c;
        }else{
            y=y*d-a[i];
        }
    }
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
