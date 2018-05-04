#pragma once
#include "Creature.h"
namespace Quiz 
{
	namespace Three 
	{
		class Monster : public Creature
		{
		public:
			enum Type {
				DRAGON,
				ORC,
				SLIME,
				MAX_TYPES
			};
		private:
			struct MonsterData 
			{
				std::string name;
				char symbol;
				int health;
				int damage;
				int gold;
			};
			static MonsterData monsterData[MAX_TYPES];
		public:
			Monster(Type type) : 
				Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health,monsterData[type].damage,monsterData[type].gold)
			{

			}
			static int getRandomNumber(int min, int max);
			static Monster getRandomMonster();
		};
	}
}