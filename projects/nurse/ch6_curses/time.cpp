#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<curses.h>
using namespace std;

/*
1 time 結構
2 ctime 字串
2 localtime ( time ) tm結構
2 gmtime( time )  tm結構
3 asctime(tm)  字串結構

mktime(tm)  time_t回傳
difftime(  time1 , time2)  double回傳


*/
int main(){
	time_t now = time(0);

	cout << "1970至今經過秒數:" << now <<endl ;
	cout << sizeof(tm) << endl;
	
	tm *ltm = localtime( &now);
	cout <<"年"  << 1900 + ltm->tm_year << endl;
	cout <<"月"  <<   ltm->tm_mon +1  << endl;
	cout <<"日"  << 	ltm->tm_mday  <<  endl;
	cout <<"時間"<< 	ltm->tm_hour  << "時" 
							 <<		ltm->tm_min << "分" 
							 << 	ltm->tm_sec	<< "秒" <<endl;

}
