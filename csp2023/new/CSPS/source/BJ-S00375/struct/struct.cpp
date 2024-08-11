//唉，大模拟......

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#define int long long
using namespace std;

int n;
int usedpos; //最后的已用字节
int strnum, elenum; //根结构体和根元素的个数
int st[110], en[110]; //存储第i个根元素的起始和结束精确位置
string eletype[110]; //存储第i个根元素属于什么类型
//-1为byte，-2为short，-4为int，-8为long
int strsize[110]; //存储第i个根结构体的确切大小
string strname[110]; //存储第i个根结构体的名称
string elename[110]; //存储第i个根元素的名称
int childnum[110]; //如果i个根类型是结构体，那么它有多少个子类型

string innername[110][110]; //第i个根结构体类型的第j个元素名称
string innertype[110][110]; //第i个根结构体类型的第j个元素类型
int innerst[110][110]; //第i个根结构体类型的第j个元素在根内相对起点
int inneren[110][110]; //第i个根结构体类型的第j个元素在根内相对终点
 
int type2size(string type)
{
    if(type=="byte") return 1;
    if(type=="short") return 2;
    if(type=="int") return 4;
    if(type=="long") return 8;

    for(int i = 1; i <= strnum; i++)
    {
        if(type == strname[i]) return strsize[i];
    }
    return -1;
}

int up24(int pos)
{
    if(pos % 4 == 0) return pos;
    return (pos / 4 + 1) * 4;
}

bool is_basic(string t)
{
    if(t=="short") return true;
    if(t=="byte") return true;
    if(t=="long") return true;
    if(t=="int") return true;
    return false;
}

int type2id(string t)
{
    for(int i = 1; i <= strnum; i++)
    {
        if(t == strname[i]) return i;
    }
    return -1;
}

void find_addr(int tar, int l, string t, string na, string bui)
{
    if(is_basic(t))
    {
        if(l + type2size(t) - 1 < tar)
        {
            printf("ERR\n");
        }
        else
        {
            cout<< bui + '.' + na <<endl;
        }
    }
    else //在相对位置中寻找相对位置恰好为tar的  
    {
        int aaa = type2id(t);
        int L = 1, r = childnum[aaa], nt = tar - l;
        int key;
        bool f = false;
           while(L<r)
           {
               int m = (L+r) / 2; //中间的元素
               if(innerst[aaa][m] <= nt && inneren[aaa][m] >= nt)
               {
                   key = m;
                    f = true;
                   break;
               }
              else if(innerst[aaa][m] > nt)
               {
                   r = m-1;
               }
               else
               {
                L = m+1;
               }
          }
        if(f) L = key;
        find_addr(tar, innerst[aaa][L] + l, innertype[aaa][L], innername[aaa][L], bui + '.' + innername[aaa][L]);
    }
}

signed main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);

    scanf("%lld",&n);
    for(int i = 1; i <= n; i++)
    {
        int op;
        scanf("%lld",&op);
        if(op == 1) //定义一个结构体
        {
            strnum++;

            string sname;
            int k; //成员数量
            cin >> sname;
            strname[strnum] = sname;
            scanf("%lld",&k);
            childnum[strnum] = k;
            int calc = 0, nowpos = 0;
            // st[strnum] = up24(usedpos+1);
            for(int j = 1; j <= k; j++) //第j个成员
            {
                string Memname, Memtype;
                cin >> Memtype >> Memname;
                innername[strnum][j] = Memname;
                innertype[strnum][j] = Memtype;
                int csize = type2size(Memtype);
                nowpos = up24(nowpos);
                innerst[strnum][j] = nowpos;
                inneren[strnum][j] = nowpos + csize - 1;
                nowpos += csize;
            }
            // en[strnum] = nowpos - 1;
            strsize[strnum] = inneren[strnum][childnum[strnum]] + 1;
            // printf("成功创建结构体，参数如下：\n");
            // cout<<"名称："<<strname[strnum]<<"大小："<<strsize[strnum]<<"成员数量:"<<childnum[strnum]<<endl;
            // printf("成员如下：\n");
            // for(int j = 1; j <= childnum[strnum]; j++)
            // {
            //     cout<<"-类型："<<innertype[strnum][j]<<" 名称："<<innername[strnum][j]<<",";
            //     printf("在结构体中的相对位置:%lld~~%lld\n",innerst[strnum][j],inneren[strnum][j]);
            // }
        }

        else if(op == 2) //定义一个元素
        {
            elenum++;

            string Elename, Eletype;
            cin >> Elename >> Eletype;
            elename[elenum] = Elename;
            st[elenum] = up24(usedpos+1); //元素起始位置
            en[elenum] = st[elenum] + type2size(Eletype) - 1;
            usedpos = en[elenum];
        }
        else if(op == 3) //查询元素位置
        {

        }
        else //查找地址对应的元素
        {
            int addr;
            scanf("%lld",&addr);
            int l = 1, r = elenum, key;
            bool  f = false;
            while(l<r)
            {
                int m = (l+r) / 2; //中间的元素
                if(st[m] <= addr && en[m] >= addr)
                {
                    key = m;
                    f = true;
                    break;
                }
                else if(st[m] > addr)
                {
                    r = m-1;
                }
                else
                {
                    l = m+1;
                }
            }
            if(f) l = key;
            // printf("查找结果为:%lld\n",l);
            //m为下表对应的根元素的位置
            find_addr(addr, st[l], eletype[l], elename[l], elename[l]);
        }
    }
    return 0;
}