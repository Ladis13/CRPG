# CRPG changelog

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
