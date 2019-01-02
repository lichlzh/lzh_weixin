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
int main(){
	freopen("in","w",stdout);
	int N=5000,M=1000000;
	printf("%d %d\n",N,M);
	for(int i=1;i<=M;i++)
		printf("%d %d %d\n",rnd(N),rnd(N),rand());
	return 0;
}

