#ifndef utils_h
#define utils_h
#include <string>
using std::string;

const int MAX_ROWS = 20;
const int MAX_COLS = 20;

const int TOAD_HEIGHT = 2;
const int TOAD_WIDTH = 4;

const int RING_SIZE = 4;

const int MAX_STEPS = 50;

const char ALIVE = 'X';
const char DEAD = '.';

void clearScreen();
void delay(int ms);
void report();

#endif
