#include<curses.h>
#include<cstdlib>
#include<cstdio>
#include<unistd.h>

int main()
{
	initscr();
	WINDOW *pad;
	
	int lin = 10,col=10;
	int sx=1,sy=1,px=0,py=0,pex=10,pey=10;
	pad = newpad( lin ,col);
	
	prefresh( pad , sx ,sy ,px , py , pex, pey);


	delwin(pad);
	endwin();

}
