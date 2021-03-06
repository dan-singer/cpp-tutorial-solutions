// Classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <assert.h>
#include <string>
#include <cstdint>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <array>

#include "Point3d.h"
#include "Vector3d.h"



namespace ClassesAndClassMembers {

	class IntPair {
	public:
		int m_1;
		int m_2;

		void set(int v1, int v2) {
			m_1 = v1;
			m_2 = v2;
		}

		void print() {
			std::cout << "Pair(" << m_1 << ", " << m_2 << ")\n";
		}
	};

	void main()
	{
		IntPair p1;
		p1.set(1, 1); // set p1 values to (1, 1)

		IntPair p2{ 2, 2 }; // initialize p2 values to (2, 2)

		p1.print();
		p2.print();
	}
}


namespace AccessSpecifiers {
	namespace Two {
		class Point3d {
		//Classes are private by default!
			double m_x;
			double m_y;
			double m_z;
		public:
			void setValues(double x, double y, double z) {
				m_x = x;
				m_y = y;
				m_z = z;
			}
			void print() {
				std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">\n";
			}
			bool isEqual(const Point3d &other) {
				return m_x == other.m_x && m_y == other.m_y && m_z == other.m_z;
			}
		};

		void main()
		{
			Point3d point;
			point.setValues(1.0, 2.0, 3.0);
			point.print();

			Point3d point1;
			point1.setValues(1.0, 2.0, 3.0);

			Point3d point2;
			point2.setValues(1.0, 2.0, 3.0);

			if (point1.isEqual(point2))
				std::cout << "point1 and point2 are equal\n";
			else
				std::cout << "point1 and point2 are not equal\n";

			Point3d point3;
			point3.setValues(3.0, 4.0, 5.0);

			if (point1.isEqual(point3))
				std::cout << "point1 and point3 are equal\n";
			else
				std::cout << "point1 and point3 are not equal\n";
		}
	}
	namespace Three {
		class Stack {
			int m_data[10];
			int m_next;
		public:
			void reset() {
				m_next = 0;
				for (int i = 0; i < 10; ++i)
					m_data[i] = 0;
			}
			bool push(int val) {
				if (m_next >= 10)
					return false;
				m_data[m_next++] = val;
				return true;
			}
			int pop() {
				assert(m_next > 0 && "There are no elements left on the stack");
				return m_data[--m_next];
			}
			void print() {
				std::cout << "( ";
				for (int i = 0; i < m_next; ++i)
					std::cout << m_data[i] << " ";
				std::cout << ")\n";
			}
		};
		void main()
		{
			Stack stack;
			stack.reset();

			stack.print();

			stack.push(5);
			stack.push(3);
			stack.push(8);
			stack.print();

			stack.pop();
			stack.print();

			stack.pop();
			stack.pop();

			stack.print();
		}
	}
}

namespace Constructors {
	class Ball {
		std::string m_color{ "black" };
		double m_radius{ 10.0 };
	public:
		Ball(const std::string &color="black", double radius=10.0) : m_color{ color }, m_radius{ radius }
		{
		}
		Ball(double radius) : m_radius{ radius }
		{
		}
		void print() {
			std::cout << "color: " << m_color << ", radius: " << m_radius << "\n";
		}

	};

	void main() {
		Ball def;
		def.print();

		Ball blue("blue");
		blue.print();

		Ball twenty(20.0);
		twenty.print();

		Ball blueTwenty("blue", 20.0);
		blueTwenty.print();
	}

	namespace MemberInitializationLists {
		class RGBA {
			std::uint8_t m_red;
			std::uint8_t m_green;
			std::uint8_t m_blue;
			std::uint8_t m_alpha;
		public:
			RGBA(std::uint8_t red = 0, std::uint8_t green = 0, std::uint8_t blue = 0, std::uint8_t alpha = 255) :
				m_red{ red }, m_green{ green }, m_blue{ blue }, m_alpha{ alpha } 
			{

			}
			void print() {
				std::cout << "r=" << static_cast<int>(m_red) << " g=" << static_cast<int>(m_green) << " b=" << 
					static_cast<int>(m_blue) << " a=" << static_cast<int>(m_alpha) << "\n";
			}

		};
		void main() {
			RGBA teal(0, 127, 127);
			teal.print();
		}
	}
}



namespace Friends {


	void main()
	{
		Point3d p(1.0, 2.0, 3.0);
		Vector3d v(2.0, 2.0, -3.0);

		p.print();
		p.moveByVector(v);
		p.print();
	}
}

namespace Quiz {
	namespace One {
		class Point2d {
		private:
			double m_x;
			double m_y;
		public:
			Point2d(double x = 0.0, double y = 0.0) : m_x{ x }, m_y{ y }
			{

			}
			void print() {
				std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
			}
			double distanceTo(const Point2d &other) const {
				return sqrt(pow(other.m_x - m_x, 2) + pow(other.m_y - m_y, 2));
			}
			friend double distanceFrom(const Point2d &a, const Point2d &b);
		};

		//Friend function - I can access a and b's private members
		double distanceFrom(const Point2d &a, const Point2d &b) {
			return sqrt(pow(a.m_x - b.m_x, 2) + pow(a.m_y - b.m_y, 2));
		}


		void main()
		{
			Point2d first;
			Point2d second(3.0, 4.0);
			first.print();
			second.print();
			std::cout << "Distance between two points: " << first.distanceTo(second) << '\n'; \
				std::cout << "Distance between two points (friendly): " << distanceFrom(first, second) << '\n';
		}
	}
	namespace Two {
		class HelloWorld
		{
		private:
			char *m_data;

		public:
			HelloWorld()
			{
				m_data = new char[14];
				const char *init = "Hello, World!";
				for (int i = 0; i < 14; ++i)
					m_data[i] = init[i];
			}

			~HelloWorld()
			{
				delete[] m_data;
			}

			void print() const
			{
				std::cout << m_data;
			}

		};

		void main()
		{
			HelloWorld hello;
			hello.print();
		}
	}

	namespace Three {
		class Monster {
		public:
			enum MonsterType {
				Dragon,
				Goblin,
				Ogre,
				Orc,
				Skeleton,
				Troll,
				Vampire,
				Zombie,
				MAX_MONSTERS_TYPES
			};
		private:
			MonsterType m_type;
			std::string m_name;
			std::string m_roar;
			int m_hitPoints;
		public:
			Monster(MonsterType type, std::string name, std::string roar, int hitPoints) :
				m_type{ type }, m_name{ name }, m_roar{ roar }, m_hitPoints{ hitPoints }
			{
			}

			std::string getTypeString() const {
				switch (m_type)
				{
					case Dragon:
						return "dragon";
					case Goblin:
						return "goblin";
					case Ogre:
						return "ogre";
					case Orc:
						return "orc";
					case Skeleton:
						return "skeleton";
					case Troll:
						return "troll";
					case Vampire:
						return "vampire";
					case Zombie:
						return "zombie";
					case MAX_MONSTERS_TYPES:
						return "<DON'T USE THIS ENUMERATOR HERE>";
					default:
						return "???";
				}
			}

			void print() const {
				std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << "\n";
			}

		};

		class MonsterGenerator {
		public:
			static int getRandomNumber(int min, int max)
			{
				static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
				return static_cast<int>(rand() * fraction * (max - min + 1) + min);
			}
			static Monster generateMonster() {
				Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTERS_TYPES - 1));
				int hitPoints = getRandomNumber(1, 100);
				static std::string s_names[6] = { "George", "Nic Cage", "John Wallace", "FDR", "Selo", "Haaha" };
				static std::string s_roars[6] = { "Agh", "Ugh", "Screech", "Scoop", "Poloop", "Kerplunk" };
				return Monster(type, s_names[getRandomNumber(0, 5)], s_roars[getRandomNumber(0, 5)], hitPoints);
			}
		};

		void main()
		{
			srand(static_cast<unsigned int>(time(0)));
			rand();
			
			Monster m = MonsterGenerator::generateMonster();
			m.print();
		}
	}
	namespace Four {
		class Card
		{
		public:
			enum CardSuit
			{
				SUIT_CLUB,
				SUIT_DIAMOND,
				SUIT_HEART,
				SUIT_SPADE,
				MAX_SUITS
			};

			enum CardRank
			{
				RANK_2,
				RANK_3,
				RANK_4,
				RANK_5,
				RANK_6,
				RANK_7,
				RANK_8,
				RANK_9,
				RANK_10,
				RANK_JACK,
				RANK_QUEEN,
				RANK_KING,
				RANK_ACE,
				MAX_RANKS
			};
		private:
			CardRank m_rank;
			CardSuit m_suit;
		public:
			Card(CardRank rank = RANK_ACE, CardSuit suit = SUIT_CLUB) : m_rank{ rank }, m_suit{ suit }
			{
			}
			void printCard() const
			{
				switch (m_rank)
				{
				case RANK_2:		std::cout << '2'; break;
				case RANK_3:		std::cout << '3'; break;
				case RANK_4:		std::cout << '4'; break;
				case RANK_5:		std::cout << '5'; break;
				case RANK_6:		std::cout << '6'; break;
				case RANK_7:		std::cout << '7'; break;
				case RANK_8:		std::cout << '8'; break;
				case RANK_9:		std::cout << '9'; break;
				case RANK_10:		std::cout << 'T'; break;
				case RANK_JACK:		std::cout << 'J'; break;
				case RANK_QUEEN:	std::cout << 'Q'; break;
				case RANK_KING:		std::cout << 'K'; break;
				case RANK_ACE:		std::cout << 'A'; break;
				}

				switch (m_suit)
				{
				case SUIT_CLUB:		std::cout << 'C'; break;
				case SUIT_DIAMOND:	std::cout << 'D'; break;
				case SUIT_HEART:	std::cout << 'H'; break;
				case SUIT_SPADE:	std::cout << 'S'; break;
				}
			}
			int getCardValue() const
			{
				switch (m_rank)
				{
				case RANK_2:		return 2;
				case RANK_3:		return 3;
				case RANK_4:		return 4;
				case RANK_5:		return 5;
				case RANK_6:		return 6;
				case RANK_7:		return 7;
				case RANK_8:		return 8;
				case RANK_9:		return 9;
				case RANK_10:		return 10;
				case RANK_JACK:		return 10;
				case RANK_QUEEN:	return 10;
				case RANK_KING:		return 10;
				case RANK_ACE:		return 11;
				}

				return 0;
			}
		};
		class Deck {
		private:
			std::array<Card, 52> m_deck;
			int m_cardIndex = 0;

			static void swapCard(Card &a, Card &b)
			{
				Card temp = a;
				a = b;
				b = temp;
			}

			// Generate a random number between min and max (inclusive)
			// Assumes srand() has already been called
			static int getRandomNumber(int min, int max)
			{
				static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
																							 // evenly distribute the random number across our range
				return static_cast<int>(rand() * fraction * (max - min + 1) + min);
			}

		public:
			Deck() 
			{
				srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
				rand(); // If using Visual Studio, discard first random value

				// We could initialize each card individually, but that would be a pain.  Let's use a loop.
				int card = 0;
				for (int suit = 0; suit < Card::MAX_SUITS; ++suit)
					for (int rank = 0; rank < Card::MAX_RANKS; ++rank)
					{
						m_deck[card] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
						++card;
					}
			}
			void printDeck() const
			{
				static int columns = 13;
				int counter = 0;
				for (const auto &card : m_deck)
				{
					if (counter % columns == 0 && counter > 0)
						std::cout << '\n';
					card.printCard();
					std::cout << ' ';
					++counter;
				}
				std::cout << "\n\n";
			}
			void shuffleDeck()
			{
				// Step through each card in the deck
				for (int index = 0; index < 52; ++index)
				{
					// Pick a random card, any card
					int swapIndex = getRandomNumber(0, 51);
					// Swap it with the current card
					swapCard(m_deck[index], m_deck[swapIndex]);
				}
				m_cardIndex = 0;
			}
			const Card& dealCard() {
				return m_deck[m_cardIndex++];
			}
		};
		char getPlayerChoice()
		{
			std::cout << "(h) to hit, or (s) to stand: ";
			char choice;
			do
			{
				std::cin >> choice;
			} while (choice != 'h' && choice != 's');

			return choice;
		}

		bool playBlackjack(Deck deck)
		{
			deck.shuffleDeck();
			int playerTotal = 0;
			int dealerTotal = 0;

			// Deal the dealer one card
			dealerTotal += deck.dealCard().getCardValue();
			std::cout << "The dealer is showing: " << dealerTotal << '\n';

			// Deal the player two cards
			playerTotal += deck.dealCard().getCardValue();
			playerTotal += deck.dealCard().getCardValue();

			// Player goes first
			while (1)
			{
				std::cout << "You have: " << playerTotal << '\n';
				char choice = getPlayerChoice();
				if (choice == 's')
					break;

				playerTotal += deck.dealCard().getCardValue();

				// See if the player busted
				if (playerTotal > 21)
					return false;
			}

			// If player hasn't busted, dealer goes until he has at least 17 points
			while (dealerTotal < 17)
			{
				dealerTotal += deck.dealCard().getCardValue();
				std::cout << "The dealer now has: " << dealerTotal << '\n';
			}

			// If dealer busted, player wins
			if (dealerTotal > 21)
				return true;

			return (playerTotal > dealerTotal);
		}

		
		void main() 
		{
			Deck deck;
			if (playBlackjack(deck))
				std::cout << "You win!\n";
			else
				std::cout << "You lose!\n";
		}
	}

}

int main()
{
	//ClassesAndClassMembers::main();
	//AccessSpecifiers::Two::main();
	//AccessSpecifiers::Three::main();
	//Constructors::main();
	//Constructors::MemberInitializationLists::main();
	//Friends::main();

	//Quiz::One::main();
	//Quiz::Two::main();
	//Quiz::Three::main();
	Quiz::Four::main();

}

