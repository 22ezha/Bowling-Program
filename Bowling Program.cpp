/******************************************************************************
Eric Zhang
Comp Sci 6
4/20/2020
Bowling Program
*******************************************************************************/
#include "stdafx.h"
#include <iostream>
using namespace std;
int score = 0;
int counter;
double games[5][3];
int playercount;
double highest = -1;
double lowest = 301;
int high = 0;
int low = 0;
int best = 0;
int bestest;
int main()
{
        for (playercount = 1; playercount <= 4; playercount++)
        { 
                /* This is how many games the player played*/
                cout << "Enter how many games player " << playercount << " played: ";
                cin >> games[playercount][1];
        }
        for (playercount = 1; playercount <= 4; playercount++)
        {
                for (counter = 1; counter <= games[playercount][1]; counter++)
                {
                        cout << endl << "Enter Player " << playercount << "’s score for game " << counter << ": ";
                        cin >> score;
                        while ((score<0) || (score>300))
                        {
                                cout << "Invalid score please enter a score from 0-300: ";
                                cin >> score;
                        }
                        if (score > best)
                        {
                                best = score;
                                bestest = playercount;
                        }


                        games[playercount][2] += score;
                }
                games[playercount][0] = games[playercount][2] / games[playercount][1];
                /*calculates average*/
                if (highest < games[playercount][0])
                {
                        highest = games[playercount][0];
                        high = playercount;
                }
                if (lowest > games[playercount][0])
                {
                        lowest = games[playercount][0];
                        low = playercount;
                }


        }
        games[0][0] = (games[1][0] + games[2][0] + games[3][0] + games[4][0]) / 4;
        for (counter = 1; counter <= 4; counter++)
        {
                cout << endl << endl << "Player " << counter << "’s average for the day was a " << games[counter][0] << ".";
        }
        cout << endl << endl << "The team’s average for the day was a " << games[0][0] << ".";
        cout << endl << endl << "The best bowler of the day was Player " << high << ".";
        cout << endl << endl << "The worst bowler of the day was Player " << low << ".";
        cout << endl << endl << "The person with the best game of the day was Player " << bestest << " with a score of " << best << ".";
        system("pause");
        return 0;
}