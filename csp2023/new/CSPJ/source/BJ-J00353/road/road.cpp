#include<bits/stdc++.h>
using namespace std;
int oal1,oal2;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
        int v[n-1],a[n];
        for(int i=0;i<n-1;i++){
            cin>>v[i];
        }
        for(int i=0;i<n-1;i++){
            oal1+=v[i];
        }
        oal2=oal1/d;
        if(oal2*d!=oal1){
            oal2++;
        }
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int min1=114514;
        int min1_i;
        for(int i=0;i<n-1;i++){
            if(a[i]<min1){
                min1=a[i];
                min1_i=i;
            }
        }

        if(min1_i==0){
            cout<<a[0]*oal2;
        }
    fclose(stdin);
    fclose(stdout);
    return 0;
}