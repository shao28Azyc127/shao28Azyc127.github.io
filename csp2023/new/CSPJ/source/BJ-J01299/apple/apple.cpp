#include <bits/stdc++.h>
using namespace std;
long long a[100000001]={},day=0,namber,b[100000001]={},n,maxa=1;
int main(){
    //freopen("apple2.in","r",stdin);
    //freopen("apple2.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    while(maxa){
        maxa=0;
        int t=0;
        day++;
        for(int i=1;i<=n;i++){
            if(a[i]!=0){
                if(a[i]==n) namber=day;
                a[i]=0;
                break;
            }
        }


        for(int i=1;i<=n;i++){
            if(t==2&&a[i]!=0){
                if(a[i]==n) namber=day;
                a[i]=0;
                t=0;
            }else if(a[i]!=0) t++;

        }



        for(int i=1;i<=n;i++){
            if(a[i]>maxa) maxa=a[i];

        }

    }
    cout<<day<<" "<<namber;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
