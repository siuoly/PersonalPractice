#include<iostream>
#include<map>
using namespace std;
void sol(){
	int len=0,time=0 , num=0;
	cin >> len >> time >> num;
	int pos[10001];
	char dir[10001];
	char anpos[10000]={ 0 };
	for(int i=0;i<num;i++)
		cin >> pos[i] >> dir[i];
	for(int i=0;i<time;i++)
	{
		for(int j=0;j<num;j++)
		{
			if(dir[j]=='L') pos[j]--;
			else if(dir[j]='R') pos[j]++;
			else ;
			anpos[ posi[j] ] = j;
		}
		for(int =0;j<10000<j++)
		{
			
		}
	}
}

int main(){
	int kase=0;
	cin >>kase;

	while(kase--)
	{
		sol();
	}

}
