#include<ncurses.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include <thread>

void initial();
void time_bar();
void usemovecursor();
void movecursor(int * ,int *, int);

using namespace std;

void showtime()
{
    time_t time = 0;
    while(time<20){
        mvaddch(0 , COLS - 4, time/10);
        addch(time%10);
        refresh();
        sleep(1);
    }
}

int main(){

	usemovecursor();

}

void movecursor(int *x ,int *y ,int ch ){
		
		switch(ch){
			case KEY_UP : (*y)--; break;
			
			case KEY_DOWN : (*y)++; break;

			case KEY_LEFT : (*x)--; break;

			case KEY_RIGHT : (*x)++; break;
		}
}

void usemovecursor(){
	
	initial();
	int x=0 , y=0, ch=0;
	
	refresh();

    thread t1{showtime};

	while(true){
		ch = getch();
		
		movecursor( &x, &y , ch);

		if(ch=='q')		break;
		
		y = (y+LINES) % LINES; x= (x+COLS) % COLS; 

		move(y,x);
		refresh();
	}// while
    t1.join();
	
    endwin();
}


void time_bar(){

		initial();
    int time =5;
    int x = 0, y= 0;
    while(time != 0)
    {
        move(y,x);
        for(int i=0; i< time; i++)
            mvaddch(y, x++, '*');
        for(int i=100-time ;i< 100 ;i++)
            mvaddch(y, x++, ' ');
        mvprintw(1,0,"%d ",time);
        refresh();
        sleep(1);
        time--; x=0;
        beep();
    }
    endwin();

}

void initial()                       /* 自定開啟 curses 函式 */
{
    initscr();
    cbreak();
    nonl();
    noecho();
    intrflush(stdscr,FALSE);
    keypad(stdscr,TRUE);
    refresh();
}
