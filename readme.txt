------------------------
HOW TO COMPILE AND RUN
------------------------
Compile: g++ gameDriver.cpp Player.cpp Weapon.cpp Food.cpp Armor.cpp Merchant.cpp vectorSplit.cpp Map.cpp candy.cpp candyCrush.cpp Room.cpp Monster.cpp
Run: ./a.out
------------------------
DEPENDENCIES
------------------------
Player.h, Weapon.h, Food.h, Armor.h, Merchant.h, vectorSplit.h, Map.h, candy.h, candyCrush.h, Room.h, Monster.h, and all .txt files must be in the same directory as the cpp
files in order to compile.
------------------------
SUBMISSION INFORMATION
------------------------
CSCI1300 Fall 2022 Project 3
Author: Christian Green and Ivan Gorodinski
Recitation: 202 - Lin Shi
Date: April 30, 2023
------------------------
ABOUT THIS PROJECT
------------------------
This project is a modification of the base dungeon game with the addition of candy crush.
The player trades armor, weapons, and food with the merchant and then enters a level map where they can 
enter a candycrush level. If the player successfully completes the level they have to fight a monster. If 
the player successfully kills the monster they will have the opportunity to buy better gear and more food from 
the merchant. Then they will move on to the second and third levels along with the second and third monsters.
Upon killing the third monster, the player will have beaten the game and have their score added to the leaderboard.
The UI has been developed very carefully and should make for a very enjoyable experience.
