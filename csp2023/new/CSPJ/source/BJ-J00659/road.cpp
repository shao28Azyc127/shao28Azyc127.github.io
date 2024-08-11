#include<iostream>
using namespace std;
int a[100001],b[100001];
int main(){
    int n;
    int d;
    cin>>n>>d;
    int aq;
    for(int i=1;i<n;i++){
        cin>>aq;
        a[i]=a[i-1]+aq;

    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int quint=0;
    int min=b[1];
    int ans=0;
    int ls=0;
    for(int i=2;i<n;i++){
        if(b[i]<min){

            if((a[i-1]-a[quint])%d==0){
                ans+=b[quint+1]*((a[i-1]-a[quint])/d);
            }else{

                ans+=b[quint+1]*(1+(a[i-1]-a[quint])/d);
                ls+=d*(1+(a[i-1]-a[quint])/d)-(a[i-1]-a[quint]);
            }
            quint=i-1;
            min=b[i];
        }
    }
    cout<<ans;
}

