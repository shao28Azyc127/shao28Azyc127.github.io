#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n=0;
bool a[1000000002]; //ture:��ƻ��, flase:û��ƻ��;

int main() {
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	
	cin >> n;
	
	//��1��n��λ�÷���ƻ��;
	memset(a, false, sizeof(a));
	for(int i=1; i<=n; i++) {
		a[i]=true;
	}
	
	//����ÿһ��;
	int day=0; //����
	int n_day=0; //��n��ƻ�����������
	bool x=false; //n_day�Ƿ��Ѿ����
	while(true) {
		int t=0; //����ƻ���ĸ���;
		bool all_false=true; //true:û��ƻ����, false:����ƻ��
		for(int i=1; i<=n; i++) {
			if(a[i]==true) {
				t++;
			}
			if(t-1==0 && a[i]==true) {
				a[i]=false;
			}
			if(t==2) {
				t=0;
			}
			if(i==n && t==0 && a[i]==true) {
				a[i]=false;
			}
			//�жϴ�λ���Ƿ���ƻ��
			if(a[i]==true) {
				all_false=false; //����ƻ��
			}
		}
		
		day++;
		//�жϵ�n��ƻ���Ƿ�����;
		if(a[n]==false && x!=true) {
			n_day=day;
			x=true;
		}
		if(all_false==true) {
			day--;
			break;
		}
	}
	
	cout << day << ' ' << n_day << endl;
	
	return 0;
}