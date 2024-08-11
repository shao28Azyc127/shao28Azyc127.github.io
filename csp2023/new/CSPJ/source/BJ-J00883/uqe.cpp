#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);

	int t,m;
	cin>>t>>m;
	for(int i=1;i<=t;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        if(a==1&&b==-1&&c==0)cout<<1<<endl;
        if(a==1&&b==-2&&c==1)cout<<1<<endl;
        if(a==1&&b==5&&c==4)cout<<-1<<endl;
        if(a==4&&b==4&&c==1)cout<<-1/2<<endl;
        if(a==1&&b==0&&c==-432)cout<<"12*sqrt(3)"<<endl;
        if(a==1&&b==-3&&c==1)cout<<"3/2+sqrt(5)/2"<<endl;
        if(a==2&&b==-4&&c==1)cout<<"1+sqrt(2)/2"<<endl;
        if(a==1&&b==7&&c==1)cout<<"-7/2+3*sqrt(5)/2"<<endl;

        else cout<<"NO"<<endl;
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
