#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

class Character {
  private:
  string name;
  int health;
  int level;
  int abilityPow[5] = {
    0, 0, 0, 0, 0
  };
  public:
  
  void invInp(){
   cout << "Invalid Input. \n";
  }
  Character(string newName, int newHealth, int newLevel){
    if(newHealth < 0 || newHealth > 100 || newLevel < 0 || newLevel > 100){
      invInp();
      return;
    }
    name = newName;
    health = newHealth;
    level = newLevel;
  }
  bool deadChar() const {
    return health == 0;
}
  string getName(){
    return name;
  }
  int getHealth(){
    return health;
  }
  int getLevel(){
    return level;
  }
  string abilityName[5] = {
    "Strength",
    "Defense",
    "Magic",
    "Speed",
    "Luck"
};
void changAbility(int changePlace, int ability){
 if(changePlace > 4 || changePlace < 0 || ability > 100 || ability < 0){
  invInp();
  return;
 }
int preAb = abilityPow[changePlace];
abilityPow[changePlace] = ability;
cout << name << " Now has " << ability << " " << abilityName[changePlace] 
<< " instead of " << preAb << " " << abilityName[changePlace] << "." << "\n";
}
  void setAbilities(int strength, int defense, int magic, int speed, int luck){
    if(strength < 0 || strength > 100 || 
        defense < 0 || defense > 100 || 
        magic < 0 || magic > 100 || 
        speed < 0 || speed > 100 || 
        luck < 0 || luck > 100){
      invInp();
      return;
    }
    abilityPow[0] = strength;
    abilityPow[1] = defense;
    abilityPow[2] = magic;
    abilityPow[3] = speed;
    abilityPow[4] = luck;
  }
  void heal(int healAmt){
    if(!deadChar()){
      if(healAmt > 0){
        cout << name << " attempted to heal " << healAmt << "\n";
        if((health + healAmt) > 100){
          health = 100;
          return;
        }
        else{
          health = health + healAmt;
          return;
        }
      }
      else {
        invInp();
        return;
      }
    }
  }
  void takeDamage(int damAmt){
    if(damAmt < 0){
      invInp();
      return;
    }
    if(deadChar()){
      return;
    }
    cout << name << " took " << damAmt << " damage." << "\n";
    if(damAmt >= health){
      health = 0;
      cout << name << " has died." << "\n";
      return;
    }
    else{
      health = health - damAmt;
    }
  }
  void attack(Character& target){
    if(deadChar()){
      return;
  }
    cout << getName() << " attacked " << target.getName() << "\n";
    int damage = 2 * getLevel();
    target.takeDamage(damage);
    }
  void levelUp(int newLevel){
    if(newLevel < 1 || newLevel > 100 || (newLevel + level) > 100){
      cout << "Invalid Input. \n";
      return;
    }
    if(!deadChar()){
    level = level + newLevel;
    }
  }
  void displayInfo(){
    cout << "Name: " << name << " \n";
    cout << "Health: " << health << " \n";
    cout << "Level: " << level << " \n";
  }
  void displayAbilities(){
    cout << name << "Abilities: \n";
    for(int i = 0; i < 5; i++){
      cout << abilityName[i] << ": " << abilityPow[i] << "\n";
    }
  }
};

int main() {
Character Test("Hobbit", 100, 1);
Test.setAbilities(12, 2, 11, 30, 50);
Test.displayAbilities();
Test.changAbility(2, 5);
Character Player("Wizard", 100, 1);
Player.setAbilities(12, 6, 11, 30, 70);
Player.changAbility(2, 10);
Player.takeDamage(20);
Player.displayInfo();
Player.displayAbilities();
Player.attack(Test);
Player.heal(5);
Player.heal(200);
Player.displayInfo();
cout << Player.getHealth() << "\n";
Character NPC("Knight", 100, 3);
NPC.levelUp(2);
NPC.displayInfo();
NPC.takeDamage(100);
NPC.levelUp(2);
NPC.heal(100);
NPC.displayInfo();
int levls = NPC.getLevel();
cout << levls << "\n";
return 0;
}
