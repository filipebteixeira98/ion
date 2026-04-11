#include <stdio.h>
#include <ncurses.h>

int main() {
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();

  int row, col;
  getmaxyx(stdscr, row, col);

  mvprintw(row - 1, 0, "NORMAL");
  move(0, 0);

  int ch = getch();
  
  while (ch != 'q') {
    addch(ch);
    ch = getch();
  }

  refresh();
  endwin();

  return 0;
}
