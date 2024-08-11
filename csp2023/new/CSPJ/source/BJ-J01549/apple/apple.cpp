#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,sum1=-1,sum2=1,c;
    bool flag=1,flag1=1;
    bool a[2000001];
    scanf("%d",&n);
    c=n;
    for(int i=1;i<=n;i++){
        a[i]=1;
    }
    while(flag){
        flag=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=0){
                flag=1;
                break;
            }
        }
        if(flag1){
            for(int i=1;i<=c;i=i+3){
                if(i==c){
                    flag1=0;
                }
            }
        }
        for(int i=1;i<=n;i=i+3){
            if(i<=n&&a[i]!=0){
                c--;
            }
            a[i]=0;
        }
        sum1++;
        sort(a+1,a+n+1,cmp);
        sort(a+1,a+c+1);
        if(flag1){
            sum2++;
        }
    }
    printf("%d",sum1);
    cout<<' ';
    printf("%d",sum2);
    return 0;
}
