#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;
int a[N];
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
    scanf("%d",&n);
    int nn=n;
    int cnt=0;
    int s=0;
    while(1){
        cnt++;
        s=0;
        if(nn%3!=0){
            s++;
        }
        s+=(nn/3);
        nn-=s;
        if(nn<=0){
            break;
        }
    }
    cout<<cnt<<" ";
    int cnt2=1,str=0;
    while(str!=n){
        for(int i=1;i<=3;i++){
            str++;
            if(str>n){
                str=1;
                cnt2++;
                break;
            }
            if(a[str]==1){
                while(a[str]!=1){
                    str++;
                }
                if(str>n){
                    str=1;
                    cnt2++;
                    break;
                }
            }
        }
        if(a[str]!=1) a[str]=1;
    }
    printf("%d\n",cnt);
    return 0;
}