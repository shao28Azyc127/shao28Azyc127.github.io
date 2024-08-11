#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    /*int n,i;
    bool f=true;
    int a[50]={0};
    int h[26]={0};
    cin>>n;
    for(i=0;i<26;i++){
        cin>>a[i];
    }
    for(int k=0;k<26;k++){
        if(h[k]%2==1){
            f=false;
            break;
        }
    }
    if(f==true){
        cout<<1;
    }
    else{
        cout<<0;
    }
    */
    int n;
    char s[8000]="";
    int h[26]={0};
    int i,j,k,num=0;
    cin>>n;
    cin>>s;
    bool f;
    int d=0;
    for(i=0;i<n;i++){
        for(int t=0;t<26;t++){
            h[t]=0;
        }
        h[s[i]-'a']=1;
        f=true;
        for(j=i+1;j<n;j++){
            h[s[j]-'a']++;
            /*for(k=0;k<26;k++){
                cout<<h[k]<<" ";
            }
            cout<<endl;*/
            d++;
            for(k=0;k<26;k++){
                if(h[k]%2==1){
                    f=false;
                    num++;
                    break;
                }
            }
        }
    }
    printf("%d",d-num);
    return 0;
}
