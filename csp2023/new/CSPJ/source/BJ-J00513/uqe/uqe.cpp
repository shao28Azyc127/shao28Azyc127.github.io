#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int t,m,a[100][4],p,ans,k,d,ai,bi,ci,sum;
int main(){
freopen("uqe.in","r",stdin);
freopen("uqe.out","w",stdout);


scanf("%d %d",&t,&m);

for(int i=1;i<=t;i++){

    scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);


if(a[i][2]==0&&a[i][3]==0){
for(int i=0;i<t;i++){

    cout<<0<<endl;
}
}else if(a[i][2]==0){

    if(a[i][1]<0&&a[i][3]<0){
        printf("NO/n");

    }else if(a[i][1]>0&&a[i][3]>0){
    printf("NO/n");
    }else if(a[i][1]>0&&a[i][3]<0){
    p=a[i][3]*(-1);
    k=p/a[i][1];
    ans=sqrt(k);
    printf("%d/n",ans);
    }else if(a[t][1]<0&&a[t][3]>0){
    p=a[i][1]*(-1);
    k=a[i][3]/p;
    ans=sqrt(k);
    printf("%d/n",ans);
    }


  }else if(a[i][3]==0){
  ai=a[i][1];
  bi=a[i][2];
  if(bi*bi>4*ai){
     dui=b/((-1)*2*ai);
     sum=b/((-1)*ai);

        ans=(-1)*bi+squr(4*ai);
        printf("%d/n",ans/2);


  }else{
  printf("NO");
  }

}
}


return 0;


}
