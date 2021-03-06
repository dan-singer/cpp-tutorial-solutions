// Inheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Monster.h"

namespace Constructors
{
	class Fruit 
	{
	private:
		std::string m_name;
		std::string m_color;
	public:
		Fruit(std::string name, std::string color) : m_name(name), m_color(color)
		{

		}
		std::string getName() const { return m_name; }
		std::string getColor() const { return m_color; }
	};

	class Apple : public Fruit
	{
	private:
		double m_fiber;
	public:
		Apple(std::string name, std::string color, double fiber) : Fruit(name, color), m_fiber(fiber)
		{

		}
		double getFiber() const { return m_fiber; }
		friend std::ostream& operator<<(std::ostream &out, const Apple &a);
	};
	class Banana : public Fruit
	{
	public:
		Banana(std::string name, std::string color) : Fruit(name, color)
		{

		}
		friend std::ostream& operator<<(std::ostream &out, const Banana &b);
	};

	std::ostream& operator<<(std::ostream &out, const Apple &a)
	{
		out << "Apple(" << a.getName() << ", " << a.getColor() << ", " << a.m_fiber << ")\n";
		return out;
	}
	std::ostream& operator<<(std::ostream &out, const Banana &b)
	{
		out << "Banana(" << b.getName() << ", " << b.getColor() << ")\n";
		return out;
	}


	void main()
	{
		const Apple a("Red delicious", "red", 4.2);
		std::cout << a;

		const Banana b("Cavendish", "yellow");
		std::cout << b;
	}
}
namespace Quiz
{
	/*
	1)
		a) 
		Base()
		Derived()
		~Derived()
		~Base()

		b)
		Base()
		Derived()
		Base()
		~Base()
		~Derived()
		~Base()

		c) Does not compile

		d)
		Base()
		Derived()
		Derived: 5
		~Derived()
		~Base()

		e)
		Base()
		Derived()
		D2()
		Derived: 5
		~D2()
		~Derived()
		~Base()
		
	*/

	namespace Two
	{
		class Fruit {
		private:
			std::string m_name;
			std::string m_color;
		public:
			Fruit(std::string color, std::string name) : m_name(name), m_color(color)
			{

			}
			std::string getName() { return m_name; }
			std::string getColor() { return m_color; }
		};

		class Apple : public Fruit
		{
		protected:
			Apple(std::string color, std::string name) : Fruit(color, name)
			{

			}
		public:
			Apple(std::string color = "red") : Fruit(color, "apple")
			{

			}
		};
		class Banana : public Fruit
		{
		public:
			Banana(std::string color = "yellow") : Fruit(color, "banana")
			{

			}
		};

		class GrannySmith : public Apple
		{
		public:
			GrannySmith(std::string color = "green") : Apple(color, "granny smith apple")
			{

			}
		};

		void main()
		{
			Apple a("red");
			Banana b;
			GrannySmith c;
			std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
			std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
			std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

		}
	}
	namespace Three
	{

		void attackPlayer(Player &player, const Monster &monster)
		{
			player.reduceHealth(monster.getDamagePerAttack());
			std::cout << "\t" << monster.getName() << " hit the you for " << monster.getDamagePerAttack() << " damage.\n";
		}
		void attackMonster(const Player &player, Monster &monster)
		{
			monster.reduceHealth(player.getDamagePerAttack());
			std::cout << "\tYou hit the " << monster.getName() << " for " << player.getDamagePerAttack() << " damage.\n";
		}

		void encounterMonster(Player &player)
		{
			Monster monster = Monster::getRandomMonster();
			std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ").\n";

			while (1)
			{
				std::cout << "[R]un or [F]ight: ";
				char action;
				std::cin >> action;
				if (action == 'R' || action == 'r')
				{
					bool escaped = rand() <= RAND_MAX / 2;
					if (escaped)
					{
						std::cout << "\tYou fled the " << monster.getName() << ".\n";
						return;
					}
					else
					{
						std::cout << "\tYou failed to flee!\n";
						attackPlayer(player, monster);
						if (player.isDead())
							return;
					}
				}
				else if (action == 'F' || action == 'f')
				{
					attackMonster(player, monster);
					if (monster.isDead())
					{
						player.addGold(monster.getGold());
						player.levelUp();
						std::cout << "You killed the " << monster.getName() << "!\n";
						return;
					}
					else
					{
						attackPlayer(player, monster);
						if (player.isDead())
							return;
					}
				}
			}
		}

		void main()
		{
			/*
			Creature o("orc", 'o', 4, 2, 10);
			o.addGold(5);
			o.reduceHealth(1);
			std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold.\n";

			Monster m(Monster::ORC);
			std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";

			srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
			rand(); // get rid of first result

			for (int i = 0; i < 10; ++i)
			{
				Monster m = Monster::getRandomMonster();
				std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
			}
			*/


			srand(static_cast<unsigned int>(time(0)));
			rand();

			std::cout << "Enter your name: ";
			std::string pname;
			std::cin >> pname; 

			Player player(pname);
			std::cout << "Welcome " << player.getName() << ".\n";

			while (!player.isDead() && !player.hasWon())
			{
				std::cout << "\n[" << player.getName() << " -- " << player.getHealth() << "HP -- LVL" << player.getLevel() << " -- " << player.getGold() << "GOLD]\n-------------------------------------\n";
				encounterMonster(player);
			}
			std::cout << "\n";
			if (player.hasWon())
				std::cout << "You won!\nYou ended up with " << player.getGold() << " gold. Don't spend it all in one place!\n";
			else
				std::cout << "You lost!\nYou were level " << player.getLevel() << " and had " << player.getGold() << " gold...\n";
		}
	}
}

int main()
{
	//Constructors::main();
	//Quiz::Two::main();
	Quiz::Three::main();
    return 0;
}

