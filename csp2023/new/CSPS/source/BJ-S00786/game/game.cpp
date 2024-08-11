#include <iostream>
#include<cstdio>
#include<string>
using namespace std;
int n;
string s;
int a[4000005];
unsigned long long cnt=0;
void manach(){
    int c=2,r=0;
    for(int i=1;i<s.size()-1;i++){
        while(s[i-a[i]-1]==s[i+a[i]+1]) a[i]++;
        if(c<i+a[i]){
            c=i;
            r=a[i];
        }
        for(int j=c+1;j<=c+r;j++){
            if(c-r>=2*c-j-a[2*c-j]){
                a[j]=c-j+r;
            }else{
                a[j]=a[2*c-j];
            }
        }
    }
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    //cout<<n<<endl;
    //cout<<s<<endl;
    s="-#";
    for(int i=0;i<n;i++){
        char x;
        cin>>x;
        s=s+x+"#";
        //cout<<s<<endl;
    }
    s=s+"+";
    manach();
    for(int i=1;i<s.size();i+=2){
        cnt+=a[i]/2;
    }

    for(int i=1;i<s.size();i+=2){
        for(int j=i+4;j<s.size();j+=2){
            //cout<<i<<" "<<j<<endl;
            if(i+a[i]>j-a[j]&&a[i]!=0&&a[j]!=0){
                cout<<i<<" "<<j<<endl;
                cnt+=(max(i+a[i],j-2)-max(j+a[j],i+2))/2;
            }else if(i+a[i]==j-a[j]&&a[i]!=0&&a[j]!=0){
                cnt++;
            }
        }
    }


    cout<<cnt;
    return 0;
}
