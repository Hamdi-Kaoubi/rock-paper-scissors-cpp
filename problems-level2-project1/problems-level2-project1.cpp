#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//Project 1 : Paper-Rock-Scissor

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

int ReadRoundsNumber()
{
    int rounds;
    cout << "\nHow many rounds do you want to play ?\n";
    cin >> rounds;
    return rounds;
}

int PlayerTurn()
{
    int PlayerChoice;
    do
    {
        cout << "Your choice : ";
        cout << "[1], Rock, [2]: Paper, [3]: Scissor ? ";
        cin >> PlayerChoice;
    } while (PlayerChoice < 1 or PlayerChoice > 3);
    return PlayerChoice;
}

int ComputerTurn()
{
    return RandomNumber(1, 3);
}

void PrintChoices(int player, int computer)
{
    switch (player)
    {
    case 1:
        cout << "\nPlayer Choice : Rock" << "\n";
        break;
    case 2:
        cout << "\nPlayer Choice : Paper" << "\n";
        break;
    case 3:
        cout << "\nPlayer Choice : Scissor" << "\n";
        break;
    default:
        break;
    }
    switch (computer)
    {
    case 1:
        cout << "\nComputer Choice : Rock" << "\n";
        break;
    case 2:
        cout << "\nComputer Choice : Paper" << "\n";
        break;
    case 3:
        cout << "\nComputer Choice : Scissor" << "\n";
        break;
    default:
        break;
    }
}

char  Round(int player, int computer)
{
    char ResultOfRound = 'D';
    switch (player)
    {
    case 1:
        if (computer == 1)
        {
            system("color 60");
            cout << "\nDraw -_-'\n";
            ResultOfRound = 'D';
            return ResultOfRound;
        }
        else if (computer == 2)
        {
            cout << "\a";
            system("color 47");
            cout << "\nRound winner : [Computer]\n";
            ResultOfRound = 'L';
            return ResultOfRound;
        }
        else
        {
            system("color 27");
            cout << "\nRound winner : [You]\n";
            ResultOfRound = 'W';
            return ResultOfRound;
        }
        break;
    case 2:
        if (computer == 1)
        {
            system("color 27");
            cout << "\nRound winner : [You]\n";
            ResultOfRound = 'W';
            return ResultOfRound;
        }
        else if (computer == 2)
        {
            system("color 60");
            cout << "\nDraw -_-'\n";
            ResultOfRound = 'D';
            return ResultOfRound;

        }
        else
        {
            cout << "\a";
            system("color 47");
            cout << "\nRound winner : [Computer]\n";
            ResultOfRound = 'L';
            return ResultOfRound;
        }
        break;
    case 3:
        if (computer == 1)
        {
            cout << "\a";
            system("color 47");
            cout << "\nRound winner : [Computer]\n";
            ResultOfRound = 'L';
            return ResultOfRound;
        }
        else if (computer == 2)
        {
            system("color 27");
            cout << "\nRound winner : [You]\n";
            ResultOfRound = 'W';
            return ResultOfRound;
        }
        else
        {
            system("color 60");
            cout << "\nDraw -_-'\n";
            ResultOfRound = 'D';
            return ResultOfRound;
        }
        break;
    default:
        break;
    }
}

char RepeatGame()
{
    char repeat;
        cout << "\n Do You wanna Play again Y/N? ";
        cin >> repeat;
    return repeat;
}

void RepeatRounds(int roundsNumber)
{
    int win = 0, lose = 0, draw = 0;
    for (int i = 1; i <= roundsNumber; i++)
    {
        cout << "\n---------------------[Round " << i << "]-----------------------\n\n";
        int playerChoice = PlayerTurn();
        int computerChoice = ComputerTurn();
        PrintChoices(playerChoice, computerChoice);
        char RoundResult = Round(playerChoice, computerChoice);
        cout << "\n-----------------------------------------------------\n";
        if (RoundResult == 'W')
            win++;
        else if (RoundResult == 'L')
            lose++;
        else
            draw++;
    }
    cout << "\n                ";
    cout << "---------<**{GAME-OVER}**>----------\n";
    cout << "                Rounds :          (" << roundsNumber << ") Rounds.\n";
    cout << "                You win :         (" << win << ") Times.\n";
    cout << "                Computer wins :   (" << lose << ") Times.\n";
    cout << "                Draw :            (" << draw << ") Times.\n";
    cout << "\n                ";
    cout << "------------------------------------\n";
    
    cout << "                Final result : ";
    if (win > lose)
    {
        system("color 27");
        cout << "You win ^_^'\n";
    }
    else if (win < lose)
    {
        system("color 47");
        cout << "You lose x_x'\n";
    }
    else
    {
        system("color 60");
        cout << "Draw ! -_-'\n";
    }
}




int main()
{
    srand((unsigned)time(NULL));
    RepeatRounds(ReadRoundsNumber());
    char repeat = RepeatGame();
    while (repeat == 'y')
    {
        system("cls");
        system("color 07");
        RepeatRounds(ReadRoundsNumber());
        repeat = RepeatGame();
    } 
        
}
