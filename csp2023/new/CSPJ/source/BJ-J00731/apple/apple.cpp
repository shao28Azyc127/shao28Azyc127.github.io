#include<bits/stdc++.h>
using namespace std;
int a[1000000000];
int main(){
    int n,e=0,x;
    bool flag=0;
    cin>>n;
    int s=0,k=n;
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    while(k){
        for(int i=1;i<=n;i++){
            if(a[i]!=0){
                s++;
            }
            if(flag==0&&s==1){
                a[i]=0;
                s=0;
                k--;
                if(a[i]==n){
					x=e;
				}
            }
            if(s==3){
                a[i]=0;
                k--;
                s=0;
                flag=1;
                if(a[i]==n){
					x=e;
				}
            }
        }
        e++;
    }
    cout<<e<<" "<<x;
    return 0;
}

