#include <iostream>

using namespace std;

#include <stdlib.h>
#include <time.h>

#include "Cards.h"

; char * ValueNames[] = {
						"Two",
						"Three",
						"Four",
						"Five",
						"Six",
						"Seven",
						"Eight",
						"Nine",
						"Ten",
						"Jack",
						"Queen",
						"King",
						"Ace"
						};

char * SuitNames [] =	{
						"Hearts",
						"Diamonds",
						"Clubs",
						"Spades"
						};

void Display (const Card & C)	// structures are automatically passed by value but passing by
								// reference is more efficient
	{
	cout << ValueNames [C.Value] << " of " << SuitNames [C.Suit] << endl;
	}

void Display (Card Deck[])
	{
	int		i;

	for (i = 0; i < 52; i++)
		Display (Deck [i]);
	}

void Initialize (Card Deck [])
	{
	int		i;
	Suits	S;
	Values	V;

	srand (time (0));
	i = 0;
	for (S = Hearts; S <= Spades; S = (Suits) (S + 1))
		for (V = Two; V <= Ace; V = (Values)(V + 1))
			{
			Deck [i].Suit	= S;
			Deck [i].Value	= V;
			i++;
			}
	}

void Shuffle(Card Deck[])
{
	int		i;
	int		j;
	Card	Temp;

	for (i = 0; i < 52; i++)
	{
		j = rand() % 52;
		Temp = Deck[i];
		Deck[i] = Deck[j];
		Deck[j] = Temp;
	}
}
void Deal(Card Hands[][NumCards], Card Deck[])
{
	int i;
	for (i = 0; i < NumCards; i++)
	{
		Hands[0][i] = Deck[i];
		Hands[1][i] = Deck[i + 5];
		Hands[2][i] = Deck[i + 10];
		Hands[3][i] = Deck[i + 15];
	}
}

void BubbleSort(Card Hands[][NumCards])
{


	for (int j = 0; j < 4; j++)
	{
		int		i;
		bool	Sorted;
		Card	Temp;
		int		Length;
		Length = NumCards - 1;
		do {
			Sorted = true;
			for (i = 0; i < NumCards - 1; i++)
				if (Hands[j][i].Value > Hands[j][i + 1].Value)
				{
					Temp = Hands[j][i];
					Hands[j][i] = Hands[j][i + 1];
					Hands[j][i + 1] = Temp;
					Sorted = false;
				}
				else;
				Length--;
		} while (!Sorted);

	}

	int i;

	cout << "\nPlayer 1" << endl;
	for (i = 0; i < NumCards; i++)
	{
		Display(Hands[0][i]);
	}
	cout << "Player one has a: ";
	if (StraightFlush(Hands[0]))
		cout << "Staight FLUSH" << endl;
	else
		if (FourKind(Hands[0]))
			cout << "Four of a Kind" << endl;
		else
			if (FullHouse(Hands[0]))
				cout << "Full House" << endl;
			else
				if (Flush(Hands[0]))
					cout << "Flush" << endl;
				else
					if (Straight(Hands[0]))
						cout << "Straight" << endl;
					else
						if (ThreeOfAKind(Hands[0]))
							cout << "Three of a Kind" << endl;
						else
							if (TwoPair(Hands[0]))
								cout << "Two Pair" << endl;
							else
								if (OnePair(Hands[0]))
									cout << "One Pair" << endl;
								else
									cout << "High Card" << endl;

	cout << "\nPlayer 2" << endl;
	for (i = 0; i < NumCards; i++)
	{
		Display(Hands[1][i]);
	}
	cout << "Player 2 has a: ";
	if (StraightFlush(Hands[1]))
		cout << "Staight FLUSH" << endl;
	else
		if (FourKind(Hands[1]))
			cout << "Four of a Kind" << endl;
		else
			if (FullHouse(Hands[1]))
				cout << "Full House" << endl;
			else
				if (Flush(Hands[1]))
					cout << "Flush" << endl;
				else
					if (Straight(Hands[1]))
						cout << "Straight" << endl;
					else
						if (ThreeOfAKind(Hands[1]))
							cout << "Three of a Kind" << endl;
						else
							if (TwoPair(Hands[1]))
								cout << "Two Pair" << endl;
							else
								if (OnePair(Hands[1]))
									cout << "One Pair" << endl;
								else
									cout << "High Card" << endl;

	cout << "\nPlayer 3" << endl;
	for (i = 0; i < NumCards; i++)
	{
		Display(Hands[2][i]);
	}
	cout << "Player 3 has a: ";
	if (StraightFlush(Hands[2]))
		cout << "Staight FLUSH" << endl;
	else
		if (FourKind(Hands[2]))
			cout << "Four of a Kind" << endl;
		else
			if (FullHouse(Hands[2]))
				cout << "Full House" << endl;
			else
				if (Flush(Hands[2]))
					cout << "Flush" << endl;
				else
					if (Straight(Hands[2]))
						cout << "Straight" << endl;
					else
						if (ThreeOfAKind(Hands[2]))
							cout << "Three of a Kind" << endl;
						else
							if (TwoPair(Hands[2]))
								cout << "Two Pair" << endl;
							else
								if (OnePair(Hands[2]))
									cout << "One Pair" << endl;
								else
									cout << "High Card" << endl;
	cout << "\nPlayer 4" << endl;
	for (i = 0; i < NumCards; i++)
	{
		Display(Hands[3][i]);
	}cout << "Player 4 has a: ";
	if (StraightFlush(Hands[3]))
		cout << "Staight FLUSH" << endl;
	else
		if (FourKind(Hands[3]))
			cout << "Four of a Kind" << endl;
		else
			if (FullHouse(Hands[3]))
				cout << "Full House" << endl;
			else
				if (Flush(Hands[3]))
					cout << "Flush" << endl;
				else
					if (Straight(Hands[3]))
						cout << "Straight" << endl;
					else
						if (ThreeOfAKind(Hands[3]))
							cout << "Three of a Kind" << endl;
						else
							if (TwoPair(Hands[3]))
								cout << "Two Pair" << endl;
							else
								if (OnePair(Hands[3]))
									cout << "One Pair" << endl;
								else
									cout << "High Card" << endl;

}

bool	HighestCard(Card Hand[])
{
	if (Hand[0].Value != Hand[1].Value && Hand[0].Value != Hand[2].Value && Hand[0].Value != Hand[3].Value
		&& Hand[0].Value != Hand[4].Value && Hand[1].Value != Hand[2].Value && Hand[1].Value != Hand[3].Value &&
		Hand[1].Value != Hand[4].Value && Hand[2].Value != Hand[3].Value && Hand[2].Value != Hand[4].Value && Hand[3].Value != Hand[4].Value)
	{
		return true;
	}
	else
		return false;
}

bool	OnePair(Card Hand[])
{
	if ((Hand[0].Value == Hand[1].Value && Hand[0].Value != Hand[2].Value) ||
		(Hand[1].Value == Hand[2].Value && Hand[1].Value != Hand[3].Value) ||
		(Hand[2].Value == Hand[3].Value && Hand[2].Value != Hand[4].Value) ||
		Hand[3].Value == Hand[4].Value)
	{
		return true;
	}
	else
		return false;
}

bool ThreeOfAKind(Card Hand[])
{
	if ((Hand[0].Value == Hand[2].Value) || (Hand[1].Value == Hand[3].Value) || (Hand[2].Value == Hand[4].Value))
	{
		return true;
	}
	else
		return false;
}

bool TwoPair(Card Hand[])
{
	if ((Hand[0].Value == Hand[1].Value) && (Hand[1].Value == Hand[2].Value) || (Hand[2].Value == Hand[3].Value) && (Hand[3].Value == Hand[4].Value))
		return true;
	else
		return false;
}

bool Straight(Card Hand[])
{
	if ((Hand[0].Value == Hand[1].Value - 1) && (Hand[1].Value == Hand[2].Value - 1) && (Hand[2].Value == Hand[3].Value - 1) && (Hand[3].Value == Hand[4].Value - 1))
		return true;
	else
		return false;
}

bool Flush(Card Hand[])
{
	if ((Hand[0].Suit == Hand[1].Suit) && (Hand[1].Suit == Hand[2].Suit) && (Hand[2].Suit == Hand[3].Suit) && (Hand[3].Suit == Hand[4].Suit))
		return true;
	else
		return false;
}

bool FullHouse(Card Hand[])
{
	if ((Hand[0].Value == Hand[1].Value) && (Hand[1].Value == Hand[2].Value) && (Hand[3].Value == Hand[4].Value))
		return true;
	else
		return false;
}

bool FourKind(Card Hand[])
{
	if ((Hand[0].Value == Hand[1].Value) && (Hand[1].Value == Hand[2].Value) && (Hand[2].Value == Hand[3].Value))
		return true;
	else
		return false;
}

bool StraightFlush(Card Hand[])
{
	if ((Hand[0].Value == Hand[1].Value - 1) && (Hand[1].Value == Hand[2].Value - 1) && (Hand[2].Value == Hand[3].Value - 1) && (Hand[3].Value == Hand[4].Value - 1)
		&& (Hand[0].Suit == Hand[1].Suit) && (Hand[1].Suit == Hand[2].Suit) && (Hand[2].Suit == Hand[3].Suit) && (Hand[3].Suit == Hand[4].Suit))
		return true;
	else
		return false;
}

int KickerScore(Card Hand[])
{
	int i;
	int temp;
	int	Score = 0;
	for (i = 0; i < 5, i++;)
	{
		temp = 0;
		temp = Hand[i].Value + Hand[i + 1].Value;
		Score = Score + temp;
	}

	return Score;

}
