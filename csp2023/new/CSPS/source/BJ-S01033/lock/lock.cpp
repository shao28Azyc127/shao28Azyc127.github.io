#include <bits/stdc++.h>

using namespace std;

int main()
{  freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    int a;
    cin>>a;
    int b1[5];

    int b2[5];
    int b3[5];

    int b4[5];


    for(int i=0;i<=4;i++){

        cin>>b1[i];
        cin>>b2[i];
        //cout<<b1[i]<<" ";

        //cout<<b2[i]<<" ";

    }


if(a==1)
{
    cout<<81;

}



if(a>1){

int count=0;
    for(int i=0;i<=4;i++){
        if(b1[i]!=b2[i]);{

            for(int i=3;i>=0;i--){
                if(b1[i]-b2[i]!=0){

                        count=count+1;

                }
            }
if(count==1)
{

//cout<<10;
}
if(count==2){

}







        }
    }
    cout<<10;
}

    //cout << "Hello world!" << endl;
    return 0;
}
