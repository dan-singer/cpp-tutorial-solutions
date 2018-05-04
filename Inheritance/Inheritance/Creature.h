#pragma once
#include <string>

namespace Quiz 
{
	namespace Three
	{
		class Creature {
		protected:
			std::string m_name;
			char m_symbol;
			int m_health;
			int m_damagePerAttack;
			int m_gold;
		public:

			Creature(std::string name, char symbol, int health, int damagePerAttack, int gold)
				: m_name(name), m_symbol(symbol), m_health(health), m_damagePerAttack(damagePerAttack), m_gold(gold)
			{

			}

			const std::string& getName() const { return m_name; }
			char getSymbol() const { return m_symbol; }
			int getHealth() const { return m_health; }
			int getDamagePerAttack() const { return m_damagePerAttack; }
			int getGold() const { return m_gold; }

			void reduceHealth(int amt)
			{
				m_health -= amt;
			}
			bool isDead() const
			{
				return m_health <= 0;
			}
			void addGold(int amt)
			{
				m_gold += amt;
			}
		};
	}
}