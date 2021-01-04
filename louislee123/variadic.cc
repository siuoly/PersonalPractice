#include<iostream>

using namespace std;
inline namespace A
	//namespace
{
	template<typename T>
		void p(const T& arg1)
		{	cout << arg1<< endl; }

	template<typename T, typename...Args>
		void p
		(const T& arg1, const Args&... args) {
#ifdef DEBUG
			p(arg1);
			p(args...);
			//p((args*args)...);
			//p((args*2)...);
#endif
		}
}
int main(){
	p(1,2,3,4);
}
