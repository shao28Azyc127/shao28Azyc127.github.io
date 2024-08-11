#include<iostream>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int a[100001],b[100001];
    int n,cnt=1,id=0,k;
    cin>>n;
    k=n;

    while(k>=1){
        for(int j=1;j<=k;j+=3){

            a[j]=1;
            if(j==k) id=cnt;
        }
        cnt++;

        int l=k;
        k=1;
        for(int j=1;j<=l;j++){
            if(a[j]==0){
                b[k]=a[j];
                k++;
            }
        }
        k--;
        for(int j=1;j<=k;j++){
            a[j]=b[j];
        }
    }
    cout<<cnt-1<<" "<<id;
    return 0;
}
