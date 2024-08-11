#include<bits/stdc++.h>
using namespace std;
int t, m;
int a, b, c;
int dt;
void work(){
	bool ylg=0;
	int p, q;
	int pa, qa, gh;
	cin >> a >> b >> c;
	dt=b*b-4*a*c;
	if(dt<0){
		cout <<"NO\n";
		return;
	}
	if((int)sqrt(dt)*(int)sqrt(dt)==dt){
		ylg=1;
		p=-b;
		q=2*a;
		pa=(int)sqrt(dt);
		qa=2*a;
		if(q<0){
			q=-q;
			qa=-qa;
			p=-p;
		}
		//cout <<"["<<p<<" "<<q<<" "<<pa<<" "<<qa<<"]";
		p/=__gcd(p,q);
		q/=__gcd(p,q);
		if(q==qa){
			p+=pa;
			p/=__gcd(abs(p),q);
	                q/=__gcd(abs(p),q);
			if(q==1)
				cout <<p<<"\n";
			else if(p!=0)
				cout <<p<<"/"<<q<<"\n";
			else
				cout <<"0\n";
		//	cout <<"["<<p<<" "<<q<<" "<<pa<<" "<<qa<<"]";
		}else{	
			pa/=__gcd(pa,qa);
	                qa/=__gcd(pa,qa);
			if(q==1&&p!=0)
                                cout <<p<<"\n";
                        else if(p!=0)
                                cout <<p<<"/"<<q<<"\n";
                        
			if(pa>0&&p!=0)
				cout <<"+";
			if(pa==0){
				if(p==0)
					cout <<"0\n";
				else
					cout <<"\n";
			}else{
				if(qa==1)
					cout <<pa<<"\n";
				else
					cout <<pa<<"/"<<qa<<"\n";
			}
		}
	}/*else{
		cout <<"abcde";
		for(int i = (int)sqrt(dt); i >= 1; i--){
			if((int)sqrt(i)*(int)sqrt(i)==i){
				
			}
					
		}
	}*/
}

int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t >> m;
	while(t--){
		work();
	}
	return 0;
}