// 顏色功能測試

#include<iostream>
#include<ncurses.h>

using namespace std;
int main()
{
	initsrc();
	
	// has color?
	if(has_color()== false)
	{
		endwin();
		cout << "螢幕不支援顏色\n";
		exit(1);
	}
	// statr color
	start_color();

	init_pair(1 , COLOR_RED , COLOR_BLUE);

	attron()
	// close

}
