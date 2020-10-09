#include<iostream>
#include<ncurses.h>
using namespace std;

int main(){
	int x,y;
	initscr();
	getmaxyx(stdscr ,y,x);
	printw("y:%d x:%d \n",y,x);
	refresh();
	getch();
	erase();
	clearok(stdscr , TRUE);
	refresh();
	getch();
	endwin();
}
