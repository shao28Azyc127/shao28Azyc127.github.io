#include<bits/stdc++.h>
using namespace std;
int a[10000001];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,m,ans,t=0;
    cin>>n;
    m=n;
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    while(n>0){
        for(int i=1;i<=n;i+=3){
            if(a[i]==m){
                ans=t;

            }
        }
        int k=1,s=n;
        for(int i=1;i<=s;i+=3){
            if(i==1){
                for(int j=i;j<=s;j++){
                    a[j]=a[j+1];
                }
            }else{
                for(int j=i-k++;j<=s;j++){
                    a[j]=a[j+1];
                }
            }    //fclose(stdin);
    //fclose(stdout);
            n--;
        }
        t++;
    }
    cout<<t<<" "<<ans+1<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}