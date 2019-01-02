#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
using namespace std;
int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
long long READ(){
    long long xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
char one(){
	char ch=getchar();
	while(ch==' '||ch=='\n')
		ch=getchar();
	return ch;
}
inline int rnd(int x){
	int ret=int(1.0*(rand()+1)/32768*x);
	return ret;
}
const int ws_[4]={0,1,0,-1},ad_[4]={1,0,-1,0};
struct edge{
	int x,y,v;
}E[1000010];
int cnt;
inline int get_id(int xx,int yy)
{return (xx-1)*10+yy;}
inline void ins(int xx,int yy,int vv){
	E[++cnt].x=xx;
	E[cnt].y=yy;
	E[cnt].v=vv;
}
int main(){
	freopen("in","w",stdout);
	int N=100000;
	for(int i=1;i<=10000;i++)
		for(int j=1;j<9;j++){
			ins(get_id(i,j),get_id(i,j+1),1);
			ins(get_id(i,j+1),get_id(i,j),1);
		}
	for(int i=1;i<=10000;i++)
		for(int j=1;j<=10;j++)
			for(int k=0;k<4;k++){
				int tx=i+ws_[k],ty=j+ad_[k];
				if(tx>=1&&tx<=10000&&ty>=1&&ty<=10){
					ins(get_id(i,j),get_id(tx,ty),rand());
					ins(get_id(tx,ty),get_id(i,j),rand());
				}
			}
	printf("%d %d\n",N,cnt);
	for(int i=1;i<=cnt;i++)
		printf("%d %d %d\n",E[i].x,E[i].y,E[i].v);
	return 0;
}

