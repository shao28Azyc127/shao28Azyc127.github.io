#include <bits/stdc++.h>
using namespace std;
int ans;
int n;
string a;
/*void find(int x)
{
	stack<int> s;
	for(int i=x;i<=n-1;i++)
	{
		if(!s.empty() && a[i]-'0'==s.top())
		{
			s.pop();
		}
		else s.push(a[i]-'0');
		
		if(s.empty()==true) ans++;
	}
	cout<<ans<<endl;
}*/
void find(int begin,int end)
{
	//��������
	if(begin==end)
	{
		//cout<<begin<<endl;//
		return ;
	}
	//�ж��������������ӵĲ���
	//cout<<a[((begin+end+1)/2-1)]<<" "<<a[((begin+end+1/2))]<<endl;//
	//cout<<((begin+end+1)/2-1)<<" "<<((begin+end+1)/2)<<endl;//
	if(a[((begin+end+1)/2-1)]==a[((begin+end+1)/2)])
	{
		ans++;
		//cout<<a[((begin+end+1)/2-1)]<<" "<<a[((begin+end+1/2))]<<endl;//
	}
	//�ж��ܷ�����
	stack<int> s;
	for(int i=begin;i<=end;i++)
	{
		if(!s.empty() && a[i]-'0'==s.top())
		{
			s.pop();
		}
		else s.push(a[i]-'0');
		//cout<<a[i];//
	}
	//cout<<endl;//
	if(s.empty()) ans++;
	//cout<<ans<<endl;//
	//����Ѱ��
	find(begin,(begin+end+1)/2-1);
	find((begin+end+1)/2,end);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>a;
	find(0,n-1);
	cout<<ans<<endl;
	return 0;
}
