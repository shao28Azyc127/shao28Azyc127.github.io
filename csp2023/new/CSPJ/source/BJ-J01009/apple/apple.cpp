#include<bits/stdc++.h>
using namespace std;
int a[100000001];
int n,s=3,c,d=0,f=10;
int b(){
for(int i=1;i<=n;i++){
    if(a[i]!=-1) return 1;
}
return 0;
}
int main(){
freopen("apple.in","r",stdin);
freopen("apple.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    a[i]=i;
}
while(b()){
        d++;
    for(int i=1;i<=n;i++){
        if(a[i]!=-1&&s==3){
            if(a[i]==n) {
                    c=d;

            }
            a[i]=-1;
            s=1;
        }else{
            if(s!=3&&a[i]!=-1) s++;
    }
    }
    s=3;
}
cout<<d<<' '<<c;
fclose(stdin);
fclose(stdout);
return 0;
}
