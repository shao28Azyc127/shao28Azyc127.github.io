#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    long long a[10001];
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    int l,k=0,flag=0,h=3;
    for(l=0;flag==0;l++){
        for(int j=0;j<n;j++){
            if(h%3==0&&a[j]!=-1){
                if(a[j]==n) k=l+1;
                a[j]=-1;
                h++;
            }
            if(a[j]!=-1){
                h++;
            }
        }
        h=3;
        for(int j=0;j<n;j++){
            if(a[j]!=-1){
                break;
            }
            if(j+1==n){
                flag=1;
            }
        }
    }
    cout<<l<<" "<<k; 
    fclose(stdin);
    fclose(stdout);
    return 0;
}