#include<iostream>
#include<thread>
#include<unistd.h>
#include<ncurses.h>

using namespace std;

void u(){
	time_t now = time(0);
	while(true)
	{
		cout << time(0) - now << endl ;
		sleep(1);
	}
	
}

void f(){
	char c;
	while( (c = getchar())!= 'q' )
	{
		cout << "key:" << c << endl;
	}
}
int main()
{
	//thread t1{u};
	//thread t2{f};
	
	//t1.join();
	//t2.join();
	initscr();
	char c;
	cbreak();
	noecho();
	while( (c = getchar())!= 'q')
	{
		cout << "you input: " << c << '\n';
		refresh();
	}
	endwin();
}

