#include<iostream>
int sum(std::initializer_list<int> li){
	int s = 0;
	for(auto it = li.begin(); it != li.end(); it++)
		s += *it;
	return s;
}

int sum2(std::initializer_list<int> li){
	int s = 0;
	for(const auto& a:li)
		s += a;
	return s;
}

int main(){
	std::cout << sum( {1,2,3,45,12} ) << '\n';
	std::cout << sum( {} ) <<'\n';
	std::cout << sum2( {1,2,3,45,12} ) << '\n';
	std::cout << sum2( {} );
}
