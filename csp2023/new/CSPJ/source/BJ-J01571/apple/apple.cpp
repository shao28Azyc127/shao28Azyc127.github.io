#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
int main()
{
   freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    if(n==1)
    {
        cout<<"1"<<" "<<"1";
        return 0;
    }else if(n==2){
        cout<<"2"<<" "<<"2";
        return 0;
    }else if(n==3){
        cout<<"3"<<" "<<"3";
        return 0;
    }else if(n==4){
        cout<<"3"<<" "<<"1";
        return 0;
    }else if(n==5){
        cout<<"4"<<" "<<"4";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
    }
    int jishu=0;
    int qq=0;
    int aa=1;
    while(1){
        jishu++;


       for(int i=1;i<=n;i+=aa)
        {
            aa=1;

            if(a[i]!=-1)
            {

                int ans=0;
                int sum=i;
                while(1)
                {
                    if(a[sum]!=-1)
                    {
                        ans++;
                        sum++;
                        if(ans==3)
                        {

                            aa=sum-i;
                            break;
                        }
                    }else{
                        if(sum==n)
                        {
                            break;

                        }
                        sum++;

                    }
                }
                if(a[i]==n){
                    qq=jishu;
                }
                a[i]=-1;

            }

        }
        bool qaz=true;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=-1){
                qaz=false;
            }

        }
        if(qaz==true){
            break;
        }

    }
    int ans1=0;
    for(int i=3;;i=i+2)
    {

        if(ans1>n){

            ans1=ans1+5;
            if(n<ans1-i/2)
            {
                cout<<jishu<<" "<<qq;
                return 0;

            }else{
                cout<<jishu+1<<" "<<qq;
                return 0;
            }

        }
        ans1=ans1+i;

    }

    return 0;
}
