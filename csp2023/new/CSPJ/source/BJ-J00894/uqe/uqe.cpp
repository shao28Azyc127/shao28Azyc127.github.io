#include <bits/stdc++.h>
using namespace std;
long long t,m,a,b,c,s,x1,x2,x3;
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	//995384(6)
	cin>>t>>m;
	for (int i=1;i<=t;i++){
        cin>>a>>b>>c;
        s=b*b-4*a*c;
        if (s<0){
            cout<<"NO"<<endl;
            continue;
        }
        x1=((-b)+sqrt(s))/(2*a);
        x2=((-b)-sqrt(s))/(2*a);
        x3=max(x1,x2);
        cout<<x3<<endl;
	}
	return 0;
}
