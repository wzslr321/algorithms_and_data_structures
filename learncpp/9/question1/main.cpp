#include <cstdlib>
#include <iostream>

enum class MonsterType { ogre, dragon, orc, giant_spider, slime };

struct monster {
    std::string name;
    MonsterType type;
    int health;
};

void printMonsterDescription(MonsterType monster_t)
{
    std::string monster_type_s {};

    switch(monster_t) {
        case MonsterType::ogre:
            monster_type_s = "Ogre";
            break; 
        case MonsterType::dragon:
            monster_type_s = "Dragon";
            break;  
        case MonsterType::orc:
            monster_type_s = "Orc";
            break;
        case MonsterType::giant_spider:
            monster_type_s = "Giant_spider";
            break;
        case MonsterType::slime:
            monster_type_s = "Slime";
            break;
    }

    std::cout << "This " << monster_type_s << " is named ";
}

int main() {
    MonsterType slime_t = MonsterType::slime;
    printMonsterDescription(slime_t);

    return EXIT_SUCCESS;
}
