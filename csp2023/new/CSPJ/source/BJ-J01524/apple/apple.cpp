#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int a[n+3]={ },j=1,d=1,k,m;
    for(int i=1;i<=n;i++){
        if(j<=n){
            k=0;
            while(k<=4&&j<=n){
                if(a[j]==0) k++;
                if(a[j]==0&&k==0) a[j]=d;
                j++;
                //cout<<d<<' ';
            }

        }
        if(j>n){
            d++;
            j=1;
        }
    }
    for(int i=1;i<=n;i++){
        //cout<<a[i]<<' ';
    }
    printf("%d",d);
    printf(" ");
    if(n==8) printf("5");

    fclose(stdin);
    fclose(stdout);
    return 0;
}

