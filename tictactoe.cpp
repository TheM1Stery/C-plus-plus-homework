#include <iostream>
#include <windows.h>


void print_board(char board[][3], const int size = 3)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 'X' || board[i][j] == 'O' || (board[i][j] >= '1' && board[i][j] <= '9'))
            {
                std::cout << " " << board[i][j] << " ";
            }
            else
            {
                std::cout << " " << " " << " ";
            }
            if (j != 2)
            {
                std::cout << "|";
            }

        }
        std::cout << "\n";
        if (i != 2)
        {
            for (int k = 0; k < 12; k++)
            {
                std::cout << "-";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
}

bool check_pos(char board[][3], int pos)
{
    if (pos < 1 || pos > 10)
    {
        return false;
    }
    if (board[0][pos - 1] == 'X' || board[0][pos - 1] == 'O')
    {
        return false;
    }
    return true;
}
void enter_the_position_on_the_board(char board[][3], int pos, int count)
{
    if (count % 2 == 0)
    {
        board[0][pos - 1] = 'X';
    }
    if (count % 2 != 0)
    {
        board[0][pos - 1] = 'O';
    }

}
void starting_menu()
{
    std::cout << "Welcome to Tic Tac Toe!!!\n\n";
    Sleep(300);
    std::cout << "In this game you need to allign your characters(X or O) in three squares diagonally, horizontally or vertically.\n\n";
    Sleep(300);
    char diagonal[3][3] =
    {
        {'X', ' ', ' '},
        {' ', 'X', ' '},
        {' ', ' ', 'X'}
    };
    std::cout << "This is how you win by alligning x'es diagonally: \n";
    print_board(diagonal);
    Sleep(300);
    std::cout << "Horizontally: \n";
    char horizontally[3][3] =
    {
        {'X', 'X', 'X'},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    print_board(horizontally);
    Sleep(300);
    std::cout << "Vertically: \n";
    char vertically[3][3] =
    {
        {'X', ' ', ' '},
        {'X', ' ', ' '},
        {'X', ' ', ' '}
    };
    print_board(vertically);
    Sleep(300);
    std::cout << "Putting x'es and o's to their square: \n";
    std::cout << "If you want to put, let's say X, to the middle left square you would need to enter 4 or if you want to put O to lower left square you would need to enter 7: \n";
    char pos[3][3] =
    {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    print_board(pos);
    std::cout << "If you understood the rules: \n";
    system("pause");
    system("cls");
}

bool check_equal(char check_arr[3])
{
    int item = check_arr[0];
    for (int i = 0; i < 3; i++)
    {
        if (item != check_arr[i])
        {
            return false;
        }
    }
    return true;
}

int linear_search(char board[][3],int item, const size_t size = 3)
{
    for (int i = 0; i < size * size; i++)
    {
        if (item == board[0][i])
        {
            return i;
        }
    }
}


void bot(char board[][3], int count, const size_t size = 3)
{
    // int pos[9];
    // int c = 0;
    bool check_corner = false;
    for (int i = 0; i < size * size; i++)
    {
        if ((i + 1) % 2 == 0 && (i + 1) != 5 && check_pos(board, 5) && board[0][i] == 'X')
        {
            check_corner = true;
        }
        
    }
    if (check_corner)
    {
        enter_the_position_on_the_board(board, 5,count);
        return;
    }
    for (int i = 0; i < size * size; i++)
    {
        int check_hor = 0;
        int check_ver = 0;
        int check_diag = 0;
        bool check_hor = false, check_ver = false; check_diag = false;
        for (int j = 0; j < 3;j++)
        {
            check_hor += 1;
            check_diag += 2;
            check_ver += 3;
        }
    }
}

bool winning_condition(char board[][3], const size_t size)
{
    char main_diagonale[3];
    char side_diagonale[3];
    char vertical[3];
    char horizontal[3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                main_diagonale[i] = board[i][j];
            }
            if (i + j == size - 1)
            {
                side_diagonale[i] = board[i][j];
            }
            vertical[j] = board[j][i];
            horizontal[j] = board[i][j];
        }
        if (check_equal(vertical) || check_equal(horizontal))
        {
            return true;
        }

    }
    if (check_equal(main_diagonale) || check_equal(side_diagonale))
    {
        return true;
    }
    return false;
}

void game()
{
    starting_menu();
    char X_and_Os[3][3] =
    {
        {'s','a','l'},
        {'a', 'm', 's'},
        {'a', 'o', 'l'}
    };
    bool condition = false;
    bool pos_check = true;
    int pos;
    int count = 0;
    while (!condition)
    {
        if (count % 2 == 0)
        {
            std::cout << "It's X's turn: \n\n";
        }
        else
        {
            std::cout << "It's O's turn: \n\n";
        }
        if (count == 9)
        {
            std::cout << "It's a draw." << std::endl;
            std::cout << "Summary: \n";
            print_board(X_and_Os);
            return;
        }
        print_board(X_and_Os);
        std::cout << "Enter the position in the board: \n> ";
        std::cin >> pos;

        pos_check = check_pos(X_and_Os, pos);
        system("cls");
        if (!pos_check)
        {
            continue;
        }
        
        enter_the_position_on_the_board(X_and_Os, pos, count);
        condition = winning_condition(X_and_Os, 3);
        count++;

    }
    if (count % 2 != 0)
    {
        std::cout << "Congratulions! X has won!\n";
    }
    if (count % 2 == 0)
    {
        std::cout << "Congratulions! O has won!\n";
    }

    std::cout << "Summary: \n";
    print_board(X_and_Os);
    std::cout << "\n\n";
}


int main()
{
    game();

}