#include <iostream>
#include <vector>

#include "../utilities.h"
#include "../Exception.h"
#include "../Mtmchkin.h"
#include "../Players/Player.h"
#include "../Players/Fighter.h"
#include "../Players/Rogue.h"
#include "../Players/Wizard.h"
#include "../Cards/Card.h"
#include "../Cards/Battle.h"
#include "../Cards/Gang.h"
#include "../Cards/Barfight.h"
#include "../Cards/Dragon.h"
#include "../Cards/Fairy.h"
#include "../Cards/Goblin.h"
#include "../Cards/Merchant.h"
#include "../Cards/Pitfall.h"
#include "../Cards/Treasure.h"
#include "../Cards/Vampire.h"

using std::cout;
using std::endl;
using std::vector;

int main ()
{
    Rogue lidor = Rogue("Lidor");
    cout << lidor << endl;
    
    Pitfall lidorPitfall = Pitfall();
    lidorPitfall.applyEncounter(lidor);
    cout << lidor << endl;

    Merchant lidorMerchant = Merchant();
    lidorMerchant.applyEncounter(lidor);
    cout << lidor << endl;

    vector<Battle> lidorMonsters = {
        Goblin(),
        Goblin(),
        Goblin()
    };
    Gang lidorGang = Gang(lidorMonsters);
    lidorGang.applyEncounter(lidor);
    cout << lidor << endl;

    Merchant lidorMerchant2 = Merchant();
    lidorMerchant2.applyEncounter(lidor);
    cout << lidor << endl;

    vector<Battle> lidorMonsters2 = {
        Goblin(),
        Goblin(),
        Goblin(),
        Goblin(),
        Goblin(),
        Goblin(),
        Goblin(),
        Goblin(),
        Goblin(),
        Goblin(),
        Goblin(),
        Goblin(),
        Goblin(),
        Goblin(),
        Goblin(),
        Goblin(),
        Goblin(),
        Goblin(),
        Goblin()
    };
    Gang lidorGang2 = Gang(lidorMonsters2);
    lidorGang2.applyEncounter(lidor);
    cout << lidor << endl;

    Merchant lidorMerchant3 = Merchant();
    lidorMerchant3.applyEncounter(lidor);
    cout << lidor << endl;

    Merchant lidorMerchant4 = Merchant();
    lidorMerchant4.applyEncounter(lidor);
    cout << lidor << endl;

    Merchant lidorMerchant5 = Merchant();
    lidorMerchant5.applyEncounter(lidor);
    cout << lidor << endl;

    vector<Battle> lidorMonsters3 = {
        Goblin(),
        Vampire(),
        Goblin(),
        Vampire()
    };
    Gang lidorGang3 = Gang(lidorMonsters3);
    lidorGang3.applyEncounter(lidor);
    cout << lidor << endl;

    vector<Battle> lidorMonsters4 = {
        Goblin(),
        Vampire(),
        Dragon(),
        Goblin(),
        Vampire(),
        Dragon()
    };
    Gang lidorGang4 = Gang(lidorMonsters4);
    lidorGang4.applyEncounter(lidor);
    cout << lidor << endl;
    
    return 0;
}
