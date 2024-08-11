#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("apple.in","r",stdin);
freopen("apple.out","w",stdout);
int n;
cin>>n;
int sum=0;
int count=0;
int a[1000002];
for(int i=1;i<=n;i++){
    a[i]=0;
}
for(int i=1;i<=n;i++){
    count=0;
    if(sum!=n){
      for(int j=i;j<=n;j++){
        if(count%3==0&&a[j]==0){
            a[j]=i;
            sum++;
            count=1;

        }
      if(a[j]==0){
        count++;
      }
      }
    }else{
          break;
    }
}

int max=-1;
for(int j=1;j<=n;j++){
    if(a[j]>=max){
        max=a[j];
    }
}
cout<<max<<" ";
cout<<a[n];
fclose(stdin);
fclose(stdout);
return 0;
}
