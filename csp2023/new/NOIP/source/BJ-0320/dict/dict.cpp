#include<iostream>
#include<cstring>
using namespace std;
char c[10000][2];

int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);


    string str;
    int n,m;
    cin>>n>>m;
    if(n==1){
        cout<<1;
        return 0;
    }

    for(int i=0;i<n;i++){
        cin>>str;
        c[i][0]='z';c[i][1]='a';
        for(int j=0;j<m;j++){
            if(str[j]<c[i][0])
                c[i][0]=str[j];
            if(str[j]>c[i][1])
                c[i][1]=str[j];
        }

    }


       // for(int i=0;i<n;i++)
         //   cout<<c[i][0]<<c[i][1]<<endl;

    for(int i=0;i<n;i++){
        bool ans=1;
        for(int j=0;j<n;j++){
            if(j==i)continue;
            if(!ans)break;
            ans&= c[i][0]<c[j][1];
        }
        cout<<(int)ans;

    }






    return 0;
}

