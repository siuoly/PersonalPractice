#include<iostream>
#include<ncurses.h>
using namespace std;

int main(){
	int x,y;
	initscr();
	getmaxyx(stdscr ,y,x);
	printw("%d %d \n",y,x);
	refresh();
	getch();
	endwin();
}
