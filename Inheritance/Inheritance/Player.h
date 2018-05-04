#pragma once
#include "Creature.h"
namespace Quiz
{
	namespace Three 
	{
		class Player : public Creature
		{
		private:
			int m_level = 1;
		public:
			Player(std::string name) : Creature(name, '@', 10, 1, 0)
			{

			}
			int getLevel() const { return m_level; }
			void levelUp() 
			{
				++m_level;
				++m_damagePerAttack;
			}
			bool hasWon() const
			{
				return m_level >= 20;
			}
		};
	}
}