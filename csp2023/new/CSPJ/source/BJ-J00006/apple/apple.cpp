include<bits/stdc++.h>
using namespace std;
short  v[1000000];
int isempty(short v0[],int n){
    for(int i=0;i<n;i++){
        if(v0[i]!=1)return 0;
    }
    return 1;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long n,a=1,s=1,i=1;
    cin>>n;
    while(isempty(v,n)==0){
        int r,j=0;
        while(v[j]==1)j++;
        if(i<=2){
            for(int k=j;k<n;k+=i+2){
                v[k]=1;
            }
        }else{
            int f=1,h=0,g=j;
            while(f<4){
                if(v[g]==1)f++;
                h++;
                g++;
                if(g==n)g=0;
            }
            for(int k=j;k<n;k+=i+h){
                v[k]=1;
            }
        }
        if(v[n-1]==1)a=i;
        i++;
    }
    s=i;
    cout<<s-1<<" "<<a;
    return 0;
}