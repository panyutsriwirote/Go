#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>
#include <ctype.h>

// Coordinate of board's slot
#define BOARD_SIZE 798
typedef enum _coord {
    A9 =  82, B9 =  86, C9 =  90, D9 =  94, E9 =  98, F9 = 102, G9 = 106, H9 = 110, I9 = 114,
    A8 = 162, B8 = 166, C8 = 170, D8 = 174, E8 = 178, F8 = 182, G8 = 186, H8 = 190, I8 = 194,
    A7 = 242, B7 = 246, C7 = 250, D7 = 254, E7 = 258, F7 = 262, G7 = 266, H7 = 270, I7 = 274,
    A6 = 322, B6 = 326, C6 = 330, D6 = 334, E6 = 338, F6 = 342, G6 = 346, H6 = 350, I6 = 354,
    A5 = 402, B5 = 406, C5 = 410, D5 = 414, E5 = 418, F5 = 422, G5 = 426, H5 = 430, I5 = 434,
    A4 = 482, B4 = 486, C4 = 490, D4 = 494, E4 = 498, F4 = 502, G4 = 506, H4 = 510, I4 = 514,
    A3 = 562, B3 = 566, C3 = 570, D3 = 574, E3 = 578, F3 = 582, G3 = 586, H3 = 590, I3 = 594,
    A2 = 642, B2 = 646, C2 = 650, D2 = 654, E2 = 658, F2 = 662, G2 = 666, H2 = 670, I2 = 674,
    A1 = 722, B1 = 726, C1 = 730, D1 = 734, E1 = 738, F1 = 742, G1 = 746, H1 = 750, I1 = 754,
    EDGE = BOARD_SIZE - 1 // Index of the null terminator
} coord;

// Struct representing possible moves
typedef struct _mov {
    enum _mov_type {PASS, UNDO, PLACE_STONE} type;
    coord coordinate;
} mov;

// A 9x9 board
typedef struct _board {
    char board[BOARD_SIZE];
    struct _board* prev;
    mov prev_move;
} board;

extern board* cur_board;
void show_cur_board(); // Define in display.c
void next_board(mov prev_move);
void undo(bool undo_by_player);
#define slot(i) (cur_board->board[i])
#define last_move (cur_board->prev_move)

// String-coord conversion
#define to_coord(string) (80 * (':' - string[1]) + 2 + 4 * (toupper(string[0]) - 'A'))

// Edge checking functions
bool is_top(coord coordinate);
bool is_bottom(coord coordinate);
bool is_leftmost(coord coordinate);
bool is_rightmost(coord coordinate);

// Board transversal
#define up(coordinate) (coordinate - 80)
#define down(coordinate) (coordinate + 80)
#define left(coordinate) (coordinate - 4)
#define right(coordinate) (coordinate + 4)

#define every_row coord i = A9; i <= A1; i = down(i)
#define every_column coord coordinate = i, right_edge = i + 32;\
                        coordinate <= right_edge;\
                        coordinate = right(coordinate)

#endif