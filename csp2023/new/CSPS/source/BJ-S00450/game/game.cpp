#include<bits/stdc++.h>
using namespace std;

const int N=2e6+10;
int n;
char x;
struct node{
    char c;
    int gs;
}a[N];

bool fun(string s){
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(i!=0&&s[i]!=s[i-1]){
            cnt++;
        }
        a[cnt].c=s[i];
        a[cnt].gs++;
    }

	bool x=true;
	while(x){
        x=false;
        for(int i=0;i<=cnt;i++){
            if(a[i].gs>=2){
                x=true;
                a[i].gs=0;
                a[i].c=x;
            }
        }

        for(int i=1;i<=cnt;i++){
            if(a[i-1].gs==0){
                for(int j=i-1;j>=0;j--){
                    if(a[j].c==a[i].c){
                        a[j].gs+=a[i].gs;
                        a[i].gs=0;
                    }
                }
            }
        }
	}


	for(int i=0;i<=cnt;i++){
        if(a[i].gs!=0){
            for(int i=0;i<=cnt;i++){
                a[i].c=x;
                a[i].gs=0;
            }
            return false;
        }
	}
	return true;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);

    string s;
    cin>>n;
    cin>>s;
    long long ans=0;

    for(int i=0;i<n;i++){
        for(int j=2;j<=n-i;j++){
            if(fun(s.substr(i,j))){
                ans++;
            }
        }
    }

    cout<<ans;
	fclose(stdin);
	fclose(stdout);
    return 0;
}
