#include <iostream>
#include <string>
#include <vector>
using namespace std;

// text based advenutre game, user makes choices based on informtion provided, story changes direction based on these choices

string name; // variables for starting choices
string weapon;
string weapons[3] = {"Sword", "Axe", "Bow"}; // stores weapon types
string fightchoice; // variables for middle choices
string water;
string city;
string cities[3] = {"Lundenburg", "Winchester", "Yorwhich"}; // stores the cities
string keepgo; // variables for end choices
string god;
string cs;
int fchoice; // ints for chocies
int wchoice;
int wachoice;
int karma; // end result ints
int viking;
int saxon;
int x = rand() % 2; // random number for city choice

int main() {
  cout << "Welcome to game of Vikings. Please type your name down below." << endl; // starting choice for name
  cin >> name; // stores name
  cout << "You are known as " << name << " Ragnarson. Decendent of Ragnar the fearless. You journey to the lands of the English as a Dane viking" << endl;
  cout << "You must choose a weapon from the following choices" << endl;
  for (int i=0; i<3; i++){ // prints out all weapon choices
    cout << weapons[i] << endl;
  }
  cin >> weapon;
  if (weapon == "Sword" || weapon == "sword"){ // checks which weapon is chosen
    cout << "You have chosen to be a swordsman" << endl;
    wchoice += 1; // new variable for easier acess to this choice
  } else if (weapon == "Axe" || weapon == "axe"){
    cout << "You have chosen to be an axeman" << endl;
    wchoice += 2; 
  } else if (weapon == "Bow" || weapon == "bow"){
    cout << "You have chosen to be an archer" << endl;
    wchoice += 3;
  } else {
    cout << "Inavlid choice. Game will Restart" << endl;
    return 0; // catch for false input
  }
  cout << "You have arrived on the shores of East Anglia in the Kingdom of England" << endl;
  cout << "King Aethelred of the English arrived with his army to fight off your Viking crew" << endl;
  cout << "Do you charge with the army to go fight?" << endl;
  cin >> fightchoice; // choice to fight 
  if (fightchoice == "Yes" || fightchoice == "yes"){ // checks for choice to fight
    cout << "You fight with bravery against the English army. The Danes defeat the English and capture the King. They march on to the nearest town of Dunwich" << endl;
    karma +=1; // adds end game stats
    fchoice += 1; // variable for ease of acess
  } else if (fightchoice == "No" || fightchoice == "no"){
    cout << "You cower in the corner with the seer. He tells you that you will never make it to Valhalla as you betrayed your brethern in this fight. The Danes manage to defeat the English without you and capture the King. They march on to the nearest town of Dunwich" << endl;
    karma-=1;
    fchoice += 2;
  } else {
    cout << "Inavlid choice. Game will Restart" << endl;
    return 0; // catch for false input
  }
  cout << "The Danes set up a camp in Dunwich. They pillage the lands, kill the men and capture the women and children as slaves. You see the king hung up on a cross. He is begging someone to bring him water" << endl;
  cout << "Do you bring him water?" << endl; // choice for water
  cin >> water;
  if (water == "yes" || water == "Yes") {
    cout << "The English King thanks you for your help. The Danes shun you for helping the King." << endl;
    karma +=1;
    saxon +=1; // loyality to english/saxon
    wachoice +=1;
  } else if (water == "no" || water == "no"){
    cout << "The King continues to ask for water" << endl;
    karma -=1;
    viking +=1; // loaylity to vikings/danes
    wachoice +=2;
  } else {
    cout << "Inavlid choice. Game will Restart" << endl;
    return 0;
  }
  cout << "The viking leaders are discussing which city to attack next. The three most import cities to the english are Lundenburg, Winchester and Yorwhich" << endl;
  if (fchoice == 1) { // uses fight choice int to check
    cout << "Given your bravery in the battle of East Anglia, the Vikings ask your opinion of which city to take" << endl;
    cout << "Which city do you select? (please put the full name)" << endl;
    cin >> city; // user inputs choice of city
    cout << "The vikings march onto " << city << ". They put you in charge of 20 men to charge first into the city" << endl;
  } else if (fchoice == 2) { // choices carry over
    cout << "Since you were a coward during the battle of East Anglia, the Vikings don't ask your opinion";
    cout << "The vikings march onto " << cities[x] << ". They force you to fight alongside the warriors." << endl;
    city = cities[x]; // chooses random city from random int created before
  }
  cout << "You march with the army to the city. You stop at a small village to rest for the night. You find a few saxon families still there." << endl;
  cout << "Do you keep them as slaves or let them go? (type 'keep' or 'go')" << endl; // choice for freeing them
  cin >> keepgo;
  if (keepgo == "keep"){ // checks for choice
    cout << "The saxons stare at you in disgust" << endl;
    cout << "One of the saxons is a priest and says 'the heathens choice hath been violence. If you bastards would've taken the lord's hand we could built a great kingdom, yet you worship your false profits. I see that hammmer on your neck is that supposed to be a symbol of your god? Will Thor come and protect you with his mighty hammer and lightning. Such foolishness is exepected from your kind" << endl;
    viking += 1;
    saxon -=1;
    karma -=1; // end game stat for how good or bad you are
  } else if (keepgo == "go"){
    cout << "A saxon priest comes up to you and thanks you for your kindness. He asks you to join them and take the hand of god." << endl; 
    viking -=1;
    saxon +=1;
    karma +=1;
    cout << "Do you join the priest?" << endl;
    cin >> god;
    if (god == "yes" || god =="Yes"){ // first ending
      cout << "You join the priest and find peace with the lord. You become abbot of a small abbey in northumberland. The End" << endl;
      viking -=1;
      saxon +=1;
      cout << "-----FINAL STATS-----" << endl; // prints your final stats 
      cout << "Viking Rating: " << viking << endl;
      cout << "Saxon Rating: " << saxon << endl;
      cout << "Karma: " << karma << endl;
      return 0;
    } else if (god == "no" || god == "No"){ // continues game
      cout << "You stay back with the vikings. They shun you for saving the saxons." << endl;
    }
  }
  cout << "The camp marches on towards the city. You arrive at the walls of " << city << endl;
  if (fchoice == 1){ // path if you chose to fight
    cout << "Do you charge into the city or wait till night and sneak in (charge/sneak)" << endl;
    cin >> cs;
    if (cs == "charge" || cs == "Charge"){ // charge path
      cout << "Many men are slautred trying to enter the gates. The gate is finally breached but to no avail. The city is garded by hundreds of Englishman. The battle is a decisive victory for the English army. They free Aethelred and declare war on all Danes" << endl;
      cout << "You lie half dead wounded from a arrow shot. You see your weapon to the left of you. You can almost reach it but it is too far to grab. Another Dane walks past and sees you struggling for the weapon. Given your bravery for the Danes he hands you the sword. You die with your weapon by your side and meet your ancestors in Valhalla." << endl;
      karma -= 1;
      cout << "-----FINAL STATS-----" << endl; // Valhalla ending
      cout << "Viking Rating: " << viking << endl;
      cout << "Saxon Rating: " << saxon << endl;
      cout << "Karma: " << karma << endl;
      return 0;
    } else if (cs == "sneak" || cs == "Sneak"){ // sneak path
      cout << "You sneak in at night and kill many Englishman. The English have no clue about the attack and try to defend as best they can. The battle results in a Danish victory." << endl;
      if (viking > 0) {
        cout << "Given your help in all the battles you are crowned Earl " << name << " of " << city << endl;
        cout << "You run a great earldome and are remebered for generations by your bravery." << endl;
      cout << "-----FINAL STATS-----" << endl; // Earl ending
      cout << "Viking Rating: " << viking << endl;
      cout << "Saxon Rating: " << saxon << endl;
      cout << "Karma: " << karma << endl;
      return 0;
      } else if (viking <= 0) {
        cout << "You have now become a warrior under the Earl of the city. You will now live a lively life as a Viking Warrior, fighting in many more battles to come" << endl;
      cout << "-----FINAL STATS-----" << endl; // Viking ending
      cout << "Viking Rating: " << viking << endl;
      cout << "Saxon Rating: " << saxon << endl;
      cout << "Karma: " << karma << endl;
      return 0;
      }
    }
  } else if (fchoice == 2) {
    cout << "The vikings decide to charge into the city" << endl;
    cout << "Many men are slautred trying to enter the gates. The gate is finally breached but to no avail. The city is garded by hundreds of Englishman. The battle is a decisive victory for the English army. They free Aethelred and declare war on all Danes" << endl;
    cout << "You lie half dead wounded from a arrow shot. You see your weapon to the left of you. You can almost reach it but it is too far to grab. Another Dane walks past and sees you struggling for the weapon. Since you are a coward he kicks the weapon away from you. You are now destined to walk niffelheim. Never to meet your ancestors in Valhalla." << endl;
    cout << "-----FINAL STATS-----" << endl; //  Niffelheim ending
    cout << "Viking Rating: " << viking << endl;
    cout << "Saxon Rating: " << saxon << endl;
    cout << "Karma: " << karma << endl;
    return 0; 
  }
  return 0; // ends game
  }