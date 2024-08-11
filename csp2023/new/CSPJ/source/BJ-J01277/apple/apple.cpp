#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100000002];
bool emp(){
for(int i=1;i<=n;i++){
    if(a[i]!=0) return false;
}
return true;
}


int main(){
freopen("apple.in","r",stdin);
freopen("apple.out","w",stdout);
cin>>n;

for(int i=1;i<=n;i++){
    a[i]=i;
}

int cnt=0;
int ans=0;
int ans2;

while(!emp()){
ans++;
    for(int i=1;i<=n;i++){
        if(a[i]!=0 && cnt%3==0){
            //cout<<"del"<<' '<<a[i]<<endl;
            if(a[i]==n) ans2=ans;
            a[i]=0;
            cnt++;

        }
        else if(a[i]!=0) cnt++;

    }

    cnt=0;
    //cout<<"day"<<ans<<endl;
}
if(ans2==0) ans2=1;
cout<<ans<<' '<<ans2;
return 0;

}
