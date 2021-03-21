#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

struct Permutation{
	static const int NUM=5;
	bool use[NUM]; int a[NUM];

	Permutation(){
		// initialize
		for(int i=0;i<NUM;i++) use[i]=false;
		// permutation
		backtrack(0 ,NUM);
	}

	void print()
	{	for(int i=0; i<NUM;i++) cout << a[i]; 
		cout<<endl;}
	
	void backtrack(int n, int N)
	{
		if(n==N){ print(); return;	}

		for(int i=0;i<N;i++)
			if(!use[i])
			{
				use[i]=true;
				a[n]=i;
				backtrack(n+1,N);
				use[i]=false;
			}
	}
};

int main(){
	//cout << sum*4.0;
	struct Permutation p;
}


/*
	double i=1.0;
	double add=1.0 , sum=0.0;
	for(int i=1 ; ; i++)
	{
			add = 1.0/2*i+1;
			if(i%2==0) sum-=add;
			else sum+=add;
			if(add < 1e-6)	break;
	
	}

int main(){
	int cont=0 ,n; cin >>n;
	const int ub = pow(10.0 ,9.0); //uper bound
	while(n!=1 && n<ub )
	{
		if(n%2==1)	n=3*n+1;
		else n/=2;
		cont++;
	}
	cout <<cont <<endl;

}
*/

/*
// 判斷n是否為 aabb形式
bool aabb(int n)
{
	if(n<1000 || n>9999)
		return false;
	int aa = n/100 , bb= n%100;
	if(aa%11==0 && bb%11==0 )
		return true;
	return false;
}
bool isSquare(int n)
{
	int r = (int)sqrt(n);
	return r*r==n? true:false;
}
int main(){
	for(int i=31 ; i< 100; i++)
		if(aabb(i*i))		cout << setw(5) << i*i <<endl;
	for(int i =11 ; i<100 ;i+=11)
	for(int j =11 ; j<100 ;j+=11)
		if(isSquare( i*100+j ) ) cout<<i*100+j<<endl;
}
*/
