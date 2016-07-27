#include <iostream>

using namespace std;

#include "Cards.h"

; int main()
	{
	Card	Deck [52];
	Card	Hands[4][5];
	bool	KeepPlaying;
	int		NumPlayers = 4;
	int		PlayerScore[4] [9];
	char	Answer;
	int		i;
	
	cout << "WELCOME TO THE 5 CARD DRAW POKER TABLE\n" << endl;

	do {
		KeepPlaying = true;
		Initialize(Deck);
		Shuffle(Deck);

		Deal(Hands, Deck);
		BubbleSort(Hands);

		// To solve the problem of scoring, I used KickerScore, to return a value to the cards in the hand, so in the event of matching outcomes 

			for (i = 0; i < 4; i++)
			{
				if (StraightFlush(Hands[i]))
					PlayerScore[i][0] = (7000 + KickerScore(Hands[i]));
				else
				if (FourKind(Hands[i]))
					PlayerScore[i][0] = (6000 + KickerScore(Hands[i]));
				else
				if (FullHouse(Hands[i]))
					PlayerScore[i][0] = (5000 + KickerScore(Hands[i]));
				else
				if (Flush(Hands[i]))
					PlayerScore[i][0] = (4000 + KickerScore(Hands[i]));
				else
				if (Straight(Hands[i]))
					PlayerScore[i][0] = (3000 + KickerScore(Hands[i]));
				else
				if (ThreeOfAKind(Hands[i]))
					PlayerScore[i][0] = (2000 + KickerScore(Hands[i]));
				else
				if (TwoPair(Hands[i]))
					PlayerScore[i][0] = (1500 + KickerScore(Hands[i]));
				else
				if (OnePair(Hands[i]))
					PlayerScore[i][0] = (1000 + KickerScore(Hands[i]));
				else
					if (HighestCard(Hands[i]))
						PlayerScore[i][0] = (100 + KickerScore(Hands[i]));
				}
			if ((PlayerScore[0][0] > PlayerScore[1][0]) && (PlayerScore[0][0] > PlayerScore[2][0]) && (PlayerScore[0][0] > PlayerScore[3][0]))
				cout << "\nPLAYER ONE WINS!!!!" << endl;
			else
				if ((PlayerScore[1][0] > PlayerScore[0][0]) && (PlayerScore[1][0] > PlayerScore[2][0]) && (PlayerScore[1][0] > PlayerScore[3][0]))
					cout << "\nPLAYER TWO WINS!!!" << endl;
				else
					if ((PlayerScore[2][0] > PlayerScore[0][0]) && (PlayerScore[2][0] > PlayerScore[1][0]) && (PlayerScore[2][0] > PlayerScore[3][0]))
						cout << "\nPLAYER THREE WINS!!!" << endl;
					else
						if ((PlayerScore[3][0] > PlayerScore[1][0]) && (PlayerScore[3][0] > PlayerScore[2][0]) && (PlayerScore[3][0] > PlayerScore[0][0]))
							cout << "\nPLAYER FOUR WINS!!!" << endl;
						else
							cout << "\nTHERE IS A TIE" << endl;
			do {
				cout << "\nKeep Playing y/n?" << endl;
				cin >> Answer;
				switch (Answer)
				{
				case 'y':
					KeepPlaying = true;
					break;
				case 'n':
					KeepPlaying = false;
					break;
				}
			} while (Answer != 'y' && Answer != 'n');
		

		} while (KeepPlaying);


	return 0;
	}
