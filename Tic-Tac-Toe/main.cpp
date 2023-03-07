#include <iostream>
#include <Windows.h>

using namespace std;

char field[3][3];
bool fieldWinner[3][3];
int moves;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void ShowField()
{
    SetConsoleTextAttribute(hConsole, 11); // Türkis
    cout << "  1 2 3" << endl;
    for(int i = 0 ; i < 3; i++)
    {
        SetConsoleTextAttribute(hConsole, 11); // Türkis
        cout << i+1 << " ";
        for(int j = 0 ; j < 3; j++)
        {
            if(fieldWinner[j][i])
                SetConsoleTextAttribute(hConsole, 12); // helles rot
            else
                SetConsoleTextAttribute(hConsole, 15); // helles weiß

            cout << field[j][i];
            SetConsoleTextAttribute(hConsole, 15); // helles weiß
            if(j < 2)
                cout << "|";
        }
        cout << endl;
        if(i < 2)
            cout << " --------" << endl;
    }
}

int WinnerFinder() //0: Niemand 1: X, 2: O
{
    for (int i = 0; i < 3; i++) // Zeilen
    {
        if (field[i][0] != ' ' && field[i][0] == field[i][1] && field[i][1] == field[i][2])
        {
            fieldWinner[i][0] = true;
            fieldWinner[i][1] = true;
            fieldWinner[i][2] = true;
            if(field[i][0] == 'X')
                return 1;
            else
                return 2;
        }
    }

    for (int i = 0; i < 3; i++) // spalten
    {
        if (field[0][i] != ' ' && field[0][i] == field[1][i] && field[1][i] == field[2][i])
        {
            fieldWinner[0][i] = true;
            fieldWinner[1][i] = true;
            fieldWinner[2][i] = true;
            if(field[0][i] == 'X')
                return 1;
            else
                return 2;
        }
    }
    //diagonal
    if (field[0][0] != ' ' && field[0][0] == field[1][1] && field[1][1] == field[2][2])
    {
        fieldWinner[0][0] = true;
        fieldWinner[1][1] = true;
        fieldWinner[2][2] = true;
        if(field[0][0] == 'X')
            return 1;
        else
            return 2;
    }
    if (field[0][2] != ' ' && field[0][2] == field[1][1] && field[1][1] == field[2][0])
    {
        fieldWinner[0][2] = true;
        fieldWinner[1][1] = true;
        fieldWinner[2][0] = true;
        if(field[0][2] == 'X')
            return 1;
        else
            return 2;
    }
    return 0;
}

void Easy()
{
    int x,y;
    do{
    x = rand() % 3;
    y = rand() % 3;
    }while(field[x][y] != ' ');
    field[x][y] = 'O';
}

void Hard()
{
    for(int i = 0; i < 3; i++) // Zeilen
    {
        if(field[i][2] == ' ' && field[i][0] != ' ' && field[i][0] == field[i][1])
        {
            field[i][2] = 'O';
            return;
        }
        if(field[i][1] == ' ' && field[i][0] != ' ' && field[i][0] == field[i][2])
        {
            field[i][1] = 'O';
            return;
        }
        if(field[i][0] == ' ' && field[i][1] != ' ' && field[i][1] == field[i][2])
        {
            field[i][0] = 'O';
            return;
        }
    }

    for(int i = 0; i < 3; i++) // Spalten
    {
        if(field[2][i] == ' ' && field[0][i] != ' ' && field[0][i] == field[1][i])
        {
            field[2][i] = 'O';
            return;
        }
        if(field[1][i] == ' ' && field[0][i] != ' ' && field[0][i] == field[2][i])
        {
            field[1][i] = 'O';
            return;
        }
        if(field[0][i] == ' ' && field[1][i] != ' ' && field[1][i] == field[2][i])
        {
            field[0][i] = 'O';
            return;
        }
    }
    //Diagonale links oben
    if(field[2][2] == ' ' && field[0][0] != ' ' && field[0][0] == field[1][1])
    {
        field[2][2] = 'O';
        return;
    }
    if(field[1][1] == ' ' && field[0][0] != ' ' && field[0][0] == field[2][2])
    {
        field[1][1] = 'O';
        return;
    }
    if(field[0][0] == ' ' && field[1][1] != ' ' && field[1][1] == field[2][2])
    {
        field[0][0] = 'O';
        return;
    }

    //Diagonale rechts oben
    if(field[2][0] == ' ' && field[0][2] != ' ' && field[0][2] == field[1][1])
    {
        field[2][0] = 'O';
        return;
    }
    if(field[1][1] == ' ' && field[0][2] != ' ' && field[0][2] == field[2][0])
    {
        field[1][1] = 'O';
        return;
    }
    if(field[0][2] == ' ' && field[1][1] != ' ' && field[1][1] == field[2][0])
    {
        field[0][2] = 'O';
        return;
    }
    //Kein Risiko ab hier:
    if(field[1][1] == ' ')
    {
        field[1][1] = 'O';
        return;
    }
    if(field[1][1] == 'X')
    {
        if(field[0][0] == ' ')
        {
            field[0][0] = 'O';
            return;
        }
        if(field[2][2] == ' ')
        {
            field[2][2] = 'O';
            return;
        }
        if(field[0][2] == ' ')
        {
            field[0][2] = 'O';
            return;
        }
        if(field[2][0] == ' ')
        {
            field[2][0] = 'O';
            return;
        }
    }
    else
    {
        if(field[0][1] == ' ')
        {
            field[0][1] = 'O';
            return;
        }
        if(field[1][0] == ' ')
        {
            field[1][0] = 'O';
            return;
        }
        if(field[1][2] == ' ')
        {
            field[1][2] = 'O';
            return;
        }
        if(field[2][1] == ' ')
        {
            field[2][1] = 'O';
            return;
        }
    }
    int x,y;
    do{
        x = rand() % 3;
        y = rand() % 3;
    }while(field[x][y] != ' ');
    field[x][y] = 'O';
}

int main()
{
    srand(time(0));
    do{
        system("cls");
        int answer;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                field[i][j] = ' ';
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                fieldWinner[i][j] = false;
        do{
            SetConsoleTextAttribute(hConsole, 11); // Türkis
            cout << "-----Tic-Tac-Toe-----" << endl << endl;
            SetConsoleTextAttribute(hConsole, 15); // helles weiß
            cout << "(1) Einzelspieler" << endl << endl;
            cout << "(2) Mehrspieler" << endl << endl;
            cin >> answer;
        } while (answer < 1 || answer > 2);

        system("cls");
        moves = 0;

        if(answer == 1) //Einzelspieler
        {
            do{
                cout << "(1) Einfach" << endl << endl;
                cout << "(2) Schwer" << endl << endl;
                cin >> answer;
            } while (answer < 1 || answer > 2);
            bool gameOver = false;
            int x,y;

            while(!gameOver)
            {
                system("cls");
                bool correctInput;
                do{
                    ShowField();
                    correctInput = false;
                    cout << "Du bist an der Reihe!" << endl;
                    do{
                        cout << "In welcher Reihe soll ein Feld belegt werden? ";
                        cin >> y;
                    } while (y < 1 || y > 3);
                    do{
                        cout << "In welcher Spalte soll ein Feld belegt werden? ";
                        cin >> x;
                    } while (x < 1 || x > 3);

                    if(field[x-1][y-1] != ' ')
                    {
                        system("cls");
                        cout << "Falsche Eingabe!" << endl;
                    }
                    else
                        correctInput = true;
                }while(!correctInput);

                field[x-1][y-1] = 'X';
                moves++;

                int winner = WinnerFinder();
                if(winner > 0)
                {
                    system("cls");
                    ShowField();
                    gameOver = true;
                    cout << "X hat gewonnen!" << endl;
                }
                else if(moves == 9)
                {
                    system("cls");
                    ShowField();
                    gameOver = true;
                    cout << "Unentschieden!" << endl;
                }
                else{
                    if(answer == 1)
                        Easy();
                    else
                        Hard();

                    moves++;
                    winner = WinnerFinder();
                    if(winner > 0)
                    {
                        system("cls");
                        ShowField();
                        gameOver = true;
                        cout << "O hat gewonnen!" << endl;
                    }
                }
            }
        }
        else // Mehrspieler
        {
            bool gameOver = false;
            bool xPlays = true;
            int x,y;

            while(!gameOver)
            {
                system("cls");
                bool correctInput;
                do{
                    ShowField();
                    correctInput = false;
                    if(xPlays)
                        cout << "X ";
                    else
                        cout << "O ";
                    cout << "ist an der Reihe!" << endl;
                    do{
                        cout << "In welcher Reihe soll ein Feld belegt werden? ";
                        cin >> y;
                    } while (y < 1 || y > 3);
                    do{
                        cout << "In welcher Spalte soll ein Feld belegt werden? ";
                        cin >> x;
                    } while (x < 1 || x > 3);

                    if(field[x-1][y-1] != ' ')
                    {
                        system("cls");
                        cout << "Falsche Eingabe!" << endl;
                    }
                    else
                        correctInput = true;
                }while(!correctInput);

                if(xPlays)
                    field[x-1][y-1] = 'X';
                else
                    field[x-1][y-1] = 'O';

                moves++;

                int winner = WinnerFinder();
                if(winner > 0)
                {
                    system("cls");
                    ShowField();
                    gameOver = true;
                    if(winner == 1)
                        cout << "X hat gewonnen!" << endl;
                    else
                        cout << "O hat gewonnen!" << endl;
                }
                else if(moves == 9)
                {
                    system("cls");
                    ShowField();
                    gameOver = true;
                     cout << "Unentschieden!" << endl;
                }
                xPlays = !xPlays;
            }
        }
        char input;
        cout << "Beliebigen Knopf tippen...";
        cin >> input;
    }while(true);
}
