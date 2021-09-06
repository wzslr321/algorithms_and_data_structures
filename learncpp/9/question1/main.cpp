#include <cstdlib>
#include <iostream>

enum class MonsterType { ogre, dragon, orc, giant_spider, slime };

struct Monster {
    std::string name;
    MonsterType type;
    int health;
};

void printMonsterDescription(Monster monster) {
    std::string monster_type_s{};

    switch (monster.type) {
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

    std::cout << "This " << monster_type_s << " is named " << monster.name
              << " and has " << monster.health << " health\n";
}

int main() {
    Monster monster_1 = Monster{"Torg", MonsterType::ogre, 145};
    Monster monster_2 = Monster{"Blurp", MonsterType::slime, 24};

    printMonsterDescription(monster_1);
    printMonsterDescription(monster_2);

    return EXIT_SUCCESS;
}
