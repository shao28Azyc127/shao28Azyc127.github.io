#include<bits/stdc++.h>
using namespace std;
int comp(int *a,int left,int right){
    int targ=a[0];
    int di=0;
    for(int i=left;i<right-1;i++){
        if(a[i]<targ){
            targ=a[i];
            di=i;
        }
    }
    return di;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int v[n-1];
    int a[n];
    for(int i=0;i<n-1;i++){
        int v0;
        cin>>v0;
        v[i]=v0;
    }
    for(int j=0;j<n;j++){
        int a0;
        cin>>a0;
        a[j]=a0;
    }
    int ans=0;
    if(comp(a,0,n)==0){
        int sum=0;
        for(int i=0;i<n-1;i++){
            sum=sum+v[i];
        }
        if(sum%d==0){
            cout<<(sum/d)*a[0];
            return 0;
        }
        else{
            cout<<(sum/d+1)*a[0];
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;

}