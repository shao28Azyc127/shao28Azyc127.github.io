#include<bits/stdc++.h>
using namespace std;
int n,d;
struct station{
	int s,p;
}a[100000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	
	//输入
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i].s;
	for(int i=1;i<n;i++)
		cin>>a[i].p;
	
	int prise=0,flag=1,oil=0;
	while(true){
		int flag1=0;
		int way=0;//定义 现在所在站 - 油价更低站的距离 
		for(int i=flag+1;i<=n;i++){
			way+=a[i-1].s;
			if(a[i].p<a[flag].p){
				if((way-oil)%d==0){
					prise+=(way-oil)/d*a[flag].p;
					oil=0;
				}else if((way+oil)%d==0){
					prise+=(way+oil)/d*a[flag].p;
					oil=0;
				}else{
					if(way%d!=0){
						prise+=((way/d)+1)*a[flag].p;
						oil+=((way/d)+1)*d-way;
					}else{
						prise+=(way/d)*a[flag].p;
					}
				}
				flag=i;
				flag1=1;
				break;
			}
		}
		if(flag1==0){
			if((way-oil)%d==0){
					prise=(way-oil)/d*a[flag].p;
					oil=0;
				}else{
					if(way%d!=0){
						prise+=((way/d)+1)*a[flag].p;
						oil+=((way/d)+1)*d-way;
					}else{
						prise+=(way/d)*a[flag].p;
					}
				}
			break;
		}
	}	
	fclose(stdin);
	fclose(stdout);
	cout<<prise;
	return 0;
}
