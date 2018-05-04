#include "stdafx.h"
#include "Monster.h"
#include <cstdlib>
#include <ctime>

#include <iostream>
namespace Quiz
{
	namespace Three
	{
		Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
		{
			{"dragon",'D',20,4,100},
			{"orc",	'o',4,2,25},
			{"slime",'s',1,1,10}
		};
		int Monster::getRandomNumber(int min, int max)
		{
			static const double fraction = 1.0 / (RAND_MAX + 1);
			return min + static_cast<int>((rand() * fraction) * (max - min + 1));
		}
		Monster Monster::getRandomMonster()
		{
			int index = getRandomNumber(0, MAX_TYPES - 1);
			return Monster(static_cast<Type>(index));
		}
	}
}