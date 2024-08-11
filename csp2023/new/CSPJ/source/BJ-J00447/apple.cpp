#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int a[1000001];
    int n;
    cin>>n;
    int m=n;
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    int sum=0,k;
    while(m>0){
        int num=2;
        for(int i=1;i<=n;i++){
            if(a[i]!=0){
                if(num==2){
                    if(a[i]==n){
                        k=sum;
                    }
                    m--;
                    a[i]=0;
                    num=0;
                }else{
                    num++;
                }
            }

        }
        sum++;
    }
    cout<<sum<<" "<<k+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
