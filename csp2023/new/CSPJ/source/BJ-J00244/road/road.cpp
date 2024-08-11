#include<bits/stdc++.h>
using namespace std;
int m[10001],o[10001];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,num=0;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>m[i];
    }
    for(int i=1;i<=n;i++){
        cin>>o[i];
    }
    int money=0,oil=0,k=0,p=0,a=0;
    for(int i=1;i<n;i++){
        k=o[i+1];
        while(o[i]<k){
            p++;
            k=o[i+1+p];
        }
        for(int j=i;j<p+i;j++){
            num +=m[i];
            a+=m[i];
        }
        if(num%d==0){
            num = num/d;
            oil=a-num*d;
        }
        if(num%d+oil>=d){
            num = num/d;
            oil=a-num*d+a-num*d-oil;
        }
        else{
            num = num/d+1;
            oil=a-num*d;
        }
        money+=num*o[i];
    }
    cout<<money;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
