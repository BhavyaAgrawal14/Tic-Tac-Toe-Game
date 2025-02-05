#include <stdio.h>

char board[3][3];

void initialize()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void display()
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < 2)
                printf("|");
        }
        printf("\n");
        if (i < 2)
            printf("---|---|---\n");
    }
}

int won()
{
    for (int i = 0; i < 3; i++)
    {

        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' '))
        {
            return 1;
        }
    }

    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '))
    {
        return 1;
    }
    return 0;
}

void game()
{
    int player = 1;
    int row, col;
    int count = 0;
    display();
    while (1)
    {
        printf("Player %d, Enter row and coloumn (Between 1-3) :\n ", player);
        scanf("%d %d", &row, &col);
        row--;
        col--;
        count++;
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ')
        {
            printf(" Ooops.....Invalid step! Try again\n");
            count--;
            continue;
        }

        if (player == 1)
        {
            board[row][col] = 'X';
        }
        else
        {
            board[row][col] = 'O';
        }
        display();
        if (won())
        {
            printf("Woooohooo... Player %d won!! :)", player);
            return;
        }
        if (count >= 9)
        {
            printf(" Its a draw!");
            return;
        }
        if (player == 1)
        {
            player = 2;
        }
        else
        {
            player = 1;
        }
    }
}
int main()
{
    initialize();
    game();
    return 0;
}