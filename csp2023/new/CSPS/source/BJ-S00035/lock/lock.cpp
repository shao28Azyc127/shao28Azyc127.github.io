#include<bits/stdc++.h>
using namespace std;
int n,a[10],b[10],c[10],d[10],e[10],ans;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
  //  cout<<clock();
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];
    }
    if(n==1){cout<<81;
    fclose(stdin);
    fclose(stdout);
    return 0;}
    bool p;
    bool dir[9][5]={{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1},{1,1,0,0,0},{0,1,1,0,0},{0,0,1,1,0},{0,0,0,1,1}};
    for(int i=1;i<=9;i++){
        for(int j=0;j<9;j++){
            int a1=(a[1]+dir[j][0]*i)%10;
            int b1=(b[1]+dir[j][1]*i)%10;
            int c1=(c[1]+dir[j][2]*i)%10;
           int  d1=(d[1]+dir[j][3]*i)%10;
           int  e1=(e[1]+dir[j][4]*i)%10;

            for(int k=2;k<=n;k++){


                            bool ad=a1==a[k];
                            bool bd=b1==b[k];
                            bool cd=c1==c[k];
                            bool dd=d1==d[k];
                            bool ed=e1==e[k];
                            bool ab=a1!=a[k];
                            bool bb=b1!=b[k];
                            bool cb=c1!=c[k];
                            bool db=d1!=d[k];
                            bool eb1=e1!=e[k];
                            int ac=(a1-a[k]+10)%10;
                            int bc=(b1-b[k]+10)%10;
                            int cc=(c1-c[k]+10)%10;
                            int dc=(d1-d[k]+10)%10;
                            int ec=(e1-e[k]+10)%10;
                            if((ab&&bd&&cd&&dd&&ed)||(ad&&bb&&cd&&dd&&ed)||(ad&&bd&&cb&&dd&&ed)||(ad&&bd&&cd&&db&&ed)||(ad&&bd&&cd&&dd&&eb1)||(ab&&bb&&cd&&dd&&ed&&ac==bc)||(ad&&bb&&cb&&dd&&ed&&bc==cc)||(ad&&bd&&cb&&db&&ed&&cc==dc)||(ad&&bd&&cd&&db&&eb1&&dc==ec))p=1;
                            else p=0;
                            if(!p)break;
                           // cout<<1;

                        }
                        if(p){ans++;/*cout<<a1<<b1<<c1<<d1<<e1<<endl;*/}
                        //cout<<ans<<" "<<i<<" "<<j<<endl;

            //cout<<1;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
