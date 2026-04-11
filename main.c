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
  addch(ch);

  while (ch != 'q') {
    ch = getch();
    if (ch == 263) {
      int x, y;
      getyx(stdscr, y, x);
      move(y, x - 1);
      delch();
    } else {
      addch(ch);
    }
  }

  refresh();
  endwin();

  return 0;
}
