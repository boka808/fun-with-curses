// simple curses example; keeps drawing the inputted characters, in columns
// downward, shifting rightward when the last row is reached, and
// wrapping around when the rightmost column is reached

#include <curses.h>  // required
#include <math.h>
#include "gauss.h"

// Delay (usec)
#define DELAY 10000

int r,c,  // current row and column (upper-left is (0,0))
    nrows,  // number of rows in window
    ncols;  // number of columns in window

void draw(char dc)

{  
    move(r,c);  // curses call to move cursor to row r, column c
    delch();  insch(dc);  // curses calls to replace character under cursor by dc
    refresh();  // curses call to update screen
    r++;  // go to next row
    r = (int) ((rand_gauss()*sqrt(nrows)+nrows/2)) % nrows;
    c = (int) ((rand_gauss()*sqrt(ncols)+ncols/2)) % ncols;
}

int main()

{ 
    int i;  char d;  
    WINDOW *wnd;

    srand(time(NULL));

    wnd = initscr();  // curses call to initialize window
    cbreak();  // curses call to set no waiting for Enter key
    noecho();  // curses call to set no echoing
    getmaxyx(wnd,nrows,ncols);  // curses call to find size of window
    clear();  // curses call to clear screen, send cursor to position (0,0)
    refresh();  // curses call to implement all changes since last refresh

    r = 0; c = 0;
    while (1)  {
	d = getch();  // curses call to input from keyboard
	if (d == 'q') break;  // quit?
	draw(d);  // draw the character
	usleep(DELAY);
    }

    endwin();  // curses call to restore the original window and leave

    return 0;
}
