# CRPG changelog

## Version 0.4.0

All menus and outputs as text are now more handsome. Game control as number input are all protected against misinput.

There is one new menu added to the game, a Game Over menu, which propose to load, start a new partie or quit.

Player class is rearanged to have an inventory, in wich we can add Items, to help this the is an operator overload wich prevent from crash.

The system that calculate statistics has been modified to be balanced, but its still in test for now.

DArr, the dynamic template array has been fixed and so a inventory and fight groups too.

A new class to handle an inventory has been created and is working for items, and weapons.

Item has a new son, Weapon class wich will be equiped to deal more damage. Weapons have two more attributes :

- Damage minimum,
- Damage maximum.

Random class has two new features :

- Looting exp by level,
- Looting gold by level.
  These are in tests too for now.

## Version 0.3.0

- Game class has change :

  - Menus are now protected from error input and do not crash the program anymore
  - New Menu :
    - Combat menu, this menu can handle random fight from 1 to 3 enemies.
      - Choices :
        - Flee
        - Attack
          - Enemy choice
        - Protect : doubles resistance
        - The fight is turn by turn, you play and after all enemy play their turn

- Character class has new features :

  - Functions :
    - An is alive function
    - A function to take damages

- A new class that inherit from character, Enemy class:
  - Functions :
    - Constructor / Desturctor
    - Accessors / Modifiers

* Item has new features :

  - Functions :
    - Accessors

* A new class is created for future inheritance, Event class.

* A template class can handle dynamic array of generic type

* A new class Random is created to generater random number between boundaries.

## Version 0.2.0

- Makefile compile all new features

- Game class has now more features :

  - Attributes:
    - Save file name
  - Menus :
    - Initial menu, to choose creating or loading a player
    - Statistic menu, which allow to spen statistic points to increase primary statistics
  - Functions :
    - Creating player
    - Saving player
    - Loading player

- Character class has now new functions and propeties :

  - Attributes are now protected
  - New attribute :
    - Magic, to determines how many spells has been casted before resting
  - New functions are added
    - Constructor with statistics calculate automaticaly sub-statistics
    - Initialize function to create a new character level 1 with primary stats set to 10
    - More accessors and modifiers

- Player got his own class:

  - Inherited from character
  - New attributes :
    - Experience and exeprience to next level
    - Gold
    - Statistic points, to change statistics as you wish
  - Functions :
    - Constructors / Destructors :
      - Blank constructor
      - Stats constructor
      - File constructor (load player from file)
    - More accessors and modifiers
    - Save function, put major attributes into txt file
    - Updated initialize function
    - Level up function, this function make your exp go down when you've reached experience to next level and add 2 statistic points
    - Print function is now more complete and display exp, gold and different sub-statistics

- Primary statistics have been modified :

  - Functions
    - Constructor can now handle initializing process easily
    - A function that, depending from the primary statistics generate a sub-statistics instance

- Secondary statistics are 10:

  - Dodge
  - Limit : symbolise the number of magic spell before you fell unconscient

- Items are now implemented in a template class, which contains:

  - Attributes :
    - Unique and increasing id;
    - Name and description
    - Price
    - Rarity

- Rarity is now a type that goes like :
  - Common
  - Uncommon
  - Rare
  - Epic
  - Legendary

## Version 0.1.0

- Usable Makefile to compile easily the whole project

  - 'make' to compile executable
  - 'make clean' to remove all additionnal files

- The game has its own class, which include :

  - Menus :

    - mainMenu : A menu to decide what the player does when the game starts :
      - Quit
      - Display character sheet

  - Variables :
    - playing : A variable that determines if the game is still playing
    - choice : A variable which is use to store previous choice in menus

- Template class for characters in the game, all characters will inherit from this class.

  - Attributes :
    - name
    - level
    - statistic system
    - sub-statistic system
    - current health point
    - current stamina
  - Functions :
    - Constructor / Destructor
    - Accessors / Modifiers
    - Print function

* Statistic system, primary statistics are stored into a specific class. All characters will have a total of 6 primary statistics :

  - Strength
  - Sturdiness
  - Intelligence
  - Spirit
  - Agility
  - Luck

* Sub-statistic system, all secondary statistics are stored into a specific class. These sencondary statistics are calculated with the previous statistics :
  - Vitality
  - Energy
  - Tenacity
  - Will
  - Power
  - Resistance
  - Perception
  - Mastery
