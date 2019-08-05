#include <chrono>
#include <thread>
#include "grid.h"
#include "direction.h"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
 
int kbhit()
{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}

void Delay()
{
	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono; // nanoseconds, system_clock, seconds
	
	sleep_for(milliseconds(100));
}

int main()
{
	Grid grid = Grid(70);
   	Direction X = Direction::E;

	while (true){
		bool live;
		do {
			Delay();
			live = grid.update(false, X);
			if (!live) return 0;
		} while (!kbhit());
	       
		char inp = getchar();
        		if (inp == 'w') {
				X = Direction::N;
				live = grid.update(true, X);
			}
			else if (inp == 'a') {
                       		X = Direction::W;
                       		live = grid.update(true, X);
                	}
			else if (inp == 's') {
                        	X = Direction::S;
                        	live = grid.update(true, X);
                	}
			else if (inp == 'd') {
                       		X = Direction::E;
                        	live = grid.update(true, X);
                	}
			else live = grid.update(false, X);
			
			if (!live) return 0;
		Delay();
        }	
}
