// 時間軸顯現

/*輸入時間 任務名 
	工具會建立時間軸
	依時間比例倒數計時
	時間到開始提醒(程式可以設定鈴聲)
*/


#include<iostream>
#include<ncurses.h>
#include<unistd.h>
using namespace std;

void initial();
int inputTime();
void timeAxis(int);
void tfresh(int& ,int, int);

int main(){
	
	//初始化
	initial();
	
	//輸入時間
	int num = inputTime();

	//建立倒數時間軸
	timeAxis(num);	
	
	//時間前5秒 鈴聲響

	//時間截止 秀出字樣

	//建立多時間軸

	//建立彩色時間軸

	endwin();
}

void initial(){
	initscr();
	cbreak();
	noecho();
	refresh();
}

int inputTime(){
	echo();
	int numOfTime=0;   scanw( "%d", &numOfTime);
	noecho();
	return numOfTime;
}

void timeAxis(int numOfTime){
	//取得xy
	int x,y;
	getmaxyx(stdscr, y, x);
	
	//在螢幕第三行 畫線 由左至右
	move(2,0);
	printw("%d ", numOfTime);
	hline('O', x-5 );  x-=5;
	
	//刷新: 在舊線末端 塗白 
	while(numOfTime > 0)
		tfresh(numOfTime ,2 ,--x);
	
	mvaddstr(4,0,"end");
	refresh();
	getch();
}

void tfresh(int &n ,int py, int px){
	mvaddch(py ,px ,' ');
	n--;
	refresh();
	sleep(1);
}

