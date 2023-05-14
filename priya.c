#include <stdio.h>

void print_board(char board[9]) {
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
    printf("   |   |   \n");
}

int check_win(char board[9]) {
    int win_combinations[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
    for (int i = 0; i < 8; i++) {
        if (board[win_combinations[i][0]] == board[win_combinations[i][1]] && board[win_combinations[i][1]] == board[win_combinations[i][2]] && board[win_combinations[i][0]] != ' ') {
            return 1;
        }
    }
    return 0;
}

int check_tie(char board[9]) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            return 0;
        }
    }
    return 1;
}

int get_move(char player, char board[9]) {
    int valid_move = 0;
    int move;
    while (!valid_move) {
        printf("%c, enter a number (1-9) to place your mark: ", player);
        scanf("%d", &move);
        move--;
        if (move >= 0 && move < 9 && board[move] == ' ') {
            valid_move = 1;
        } else {
            printf("Invalid input. Please enter a number from 1 to 9 for an unoccupied space.\n");
        }
    }
    return move;
}

void play_game() {
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char players[2] = {'X', 'O'};
    int current_player = 0;
    print_board(board);
    while (!check_win(board) && !check_tie(board)) {
        int move = get_move(players[current_player], board);
        board[move] = players[current_player];
        print_board(board);
        if (check_win(board)) {
            printf("Congratulations, %c wins!\n", players[current_player]);
        } else if (check_tie(board)) {
            printf("It's a tie!\n");
        } else {
            current_player = (current_player + 1) % 2;
        }
    }
}

int main() {
    play_game();
    return 0;
}
