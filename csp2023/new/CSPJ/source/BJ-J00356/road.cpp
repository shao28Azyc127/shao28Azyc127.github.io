#include<bits/stdc++.h>
using namespace std;
int n,m;
int a1[100010],a2[100010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=0;i<n-1;i++) cin>>a1[i];
    for(int i=0;i<n;i++) cin>>a2[i];
    int j=0;
    double mi=0;
    a2[n-1]=-1;
    while(j<n-1){
        int min1;
        for(int i=j;i<n;i++){
            if(a2[i]<a2[j]){
                min1=i;
                break;
            }
        }
        int lu=0;
        for(int i=j;i<min1;i++){
            lu+=a1[i];
        }
        while(mi*m<lu){
            mi++;
            sum+=a2[j];
        }
        mi-=lu/(m*1.0);
        j=min1;
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
