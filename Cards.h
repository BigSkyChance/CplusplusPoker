#ifndef CARDS_H
#define CARDS_H

const int NumCards(5);
const int NumHands(4);

enum Suits		{Hearts, Diamonds, Clubs, Spades};
enum Values		{Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};

struct Card
	{
	Values	Value;
	Suits	Suit;
	};

void	Display		(const Card &);
void	Display		(Card []);
void	Initialize	(Card []);
void	Shuffle		(Card []);
void	ShowHandOne	(Card[]);
void	Deal		(Card[][NumCards], Card[]);
void	BubbleSort(Card[][NumCards]);
bool	HighestCard(Card[]);
bool	OnePair(Card[]);
bool	ThreeOfAKind(Card[]);
bool	TwoPair(Card[]);
bool	Straight(Card[]);
bool	Flush(Card[]);
bool	FullHouse(Card[]);
bool	FourKind(Card[]);
bool	StraightFlush(Card[]);
int		KickerScore(Card[]);

#endif

