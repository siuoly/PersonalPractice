// 顏色功能測試

#include<iostream>
#include<ncurses.h>

using namespace std;
int main()
{
	initscr();
	
	// has color?
	if(has_colors()== false)
	{
		endwin();
		printw("螢幕不支援顏色");
		exit(1);
	}
	// statr color
	start_color();

	init_pair(1 , COLOR_RED , COLOR_BLUE);

	attron(COLOR_PAIR(1));
	printw("this is my color");
	
	getch();

	// close
	endwin();
}
