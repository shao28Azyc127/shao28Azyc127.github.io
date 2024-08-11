#include<bits/stdc++.h>
using namespace std;
double t, m, a, b, c;
double data;
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.ans", "w", stdout);
    cin>>t>>m;
	for(int i=0;i<t;i++){
		int ans=0;
		cin>>a>>b>>c;
		dt=b*b-4*a*c;
		if(dt<0){
			cout<<"NO"<<endl;
			continue;
		}
		if(b!=0){
			if((b*-1)%(2*a)==0){
				cout<<(b*-1)/(2*a);
			}else{
				cout<<b*-1<<"/"<<2*a;
			}
			data=sqrt(dt)*100;
		}
		if(data%10!=0){
			cout<<"+sqrt("
			cout<<dt<<")"
			cout<<"/"<<2*a;
		}else{
			if(sqrt(dt)/2*a==0){
				cout<<"+"<<sqrt(dt)/2*a<<endl;
			}else{
				cout<<"+"<<sqrt(dt)/1<<"/"<<2*a;
			}
		}
	}
	fclose(stdin);
    fclose(stdout);
    return 0;
}
