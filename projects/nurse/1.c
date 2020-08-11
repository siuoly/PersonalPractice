#include<unistd.h>
//#include<iostream>
//#include<cstdlib>
#include<stdlib.h>
#include<curses.h>

void do1(){
	move(5,15);
	printw("%s","Hello");
	refresh();

	sleep(1);
}

void setScreen()
{
	cbreak();
	noecho();
	if( keypad(stdscr , TRUE)== ERR )
	{	
		printf("false keypad");
		endwin();
		exit(0);
	}
}



void Input()
{
	int c = 0;
	int x=0 , y=0;
	
	refresh();
	
	while(c!='q')
	{
		c = getchar();
		switch(c){
			case KEY_RIGHT : 
				printw("%s" , "right key"); break;
			case 'c' :
				printw("%s" , " \'c\' input"); break;
		}
		refresh();
	}
}
int main(){
	initscr();

	setScreen();
	
	Input();

	do1();
	
	endwin();
	exit(EXIT_SUCCESS);

}
