#include<bits/stdc++.h>

using namespace std;

int n,a[10][5],ans,mem[100][5],b[5];
bool flag[100];

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
cin>>n;
for(int i=0;i<5;i++){cin>>a[0][i];

}
for(int j=0;j<5;j++){
            cin>>b[j];}
for(int i=0;i<45;i++){
    for(int j=0;j<5;j++){
        for(int k=1;k<10;k++){

    mem[i][j]=(a[0][j]+k)%10;

        }
}

}

    for(int i=45;i<81;i++){
        for(int j=0;i<4;j++){for(int k=1;k<10;k++){
            mem[i][j]=(a[0][j]+k)%10;
        mem[i][j+1]=(a[0][j]+k)%10;
        }

        }
    }
    ans=81;
    if(n>1){ans=0;
        for(int j=0;j<5;j++){
        for(int k=1;k<10;k++){
                int p=b[j];

    b[j]=(b[j]+k)%10;
    bool x=false;
    for(int i=0;i<81;i++){
        if(!flag[i]){

                for(int l=0;l<5;l++){
                 if(b[l]==mem[i][l]) {
                    x=true;

                 }


        }if(x==false){flag[i]=true;}
        if(x==true)ans++;
    }
x=false;


}
b[j]=p;
}}
for(int j=0;j<4;j++){
    for(int k=1;k<10;k++){
            bool x=false;
            int p=b[j];
        b[j]=(b[j]+k)%10;
        b[j+1]=(b[j]+k)%10;
        for(int i=0;i<81;i++){

        if(!flag[i]){

                for(int l=0;l<5;l++){
                 if(b[l]==mem[i][l]) {
                    x=true;
                 }
                }

        }if(x==false){flag[i]=true;}
        if(x==true)ans++;

    }b[j]=p;
    }

    }


    }


cout<<ans;
return 0;}
