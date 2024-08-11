#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a,b,c[100050],d[100050];
	cin>>a>>b;
	for(int i=1;i<=a-1;i++)cin>>c[i];
	for(int i=1;i<=a;i++)cin>>d[i];
	int num=1,cnt=0,cot=0;
	for(int j=1;j<10;j++){
		if(num>=a){
			cout<<cnt<<endl;
			return 0;
		}
		int u=num;
		for(int i=num;i<=a;i++){
			if(d[i]<d[u]){
				num=i;
				break;
			}
            if(i==a){
                int o=0;
                for(int i=u;i<a;i++)o+=c[i];
                    if((o-cot)%b==0){
                        cnt+=o/b*d[u];
                        cot=0;
                    }
                    else {
                    cnt+=((o-cot)/b+1)*d[u];
                    cot=(((o/b+1)*b)+cot)%o;
                }
                cout<<cnt<<endl;
                return 0;
            }
		}
		int o=0;
		for(int i=u;i<num;i++)o+=c[i];
		//cout<<o-cot<<endl;
		if((o-cot)%b==0){
            cnt+=o/b*d[u];
            cot=0;
		}
		else {
            cnt+=((o-cot)/b+1)*d[u];
            cot=(((o/b+1)*b)+cot)%o;
		}
		//cout<<num<<' '<<cot<<' '<<o<<' ';
		//cout<<cnt<<endl;
	}
	return 0;
}
