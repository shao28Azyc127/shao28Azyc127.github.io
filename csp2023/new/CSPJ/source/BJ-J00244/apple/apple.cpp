#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n=0,cnt=0,num=0,k=0;
    int a[100000001];
    cin>>n;
    k=1;
    cnt=2;
    for(int i=1;i<=n;i++){
        a[i]=0;
    }
    while(1){
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                if(cnt ==2){
                    cnt=0;
                    a[i]=k;
                    num++;
                }
                else{
                    cnt++;
                }
            }
        }
        cnt=2;
        if(num==n){
            break;
        }
        k++;


    }
    cout<<k<<" "<<a[n];
    fclose(stdin);
    fclose(stdout);
    return 0;
}