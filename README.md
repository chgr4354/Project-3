# Project-3

ColorCrush2DXtremeFreeVersion is a modification of the base dungeon dungeon crawler game for project3.

- The player will start at a difficulty selection menu with instructions on the game and cool graphics
- After choosing the difficulty, they can interact with a trader who will have ______, ______, ______, and ______.
- They will then be placed on a level map where they can maneuver their character and enter a level
- Only one level will be available at first, with more being opened as they complete more levels; they must take a set path of increasing difficulty through the game

- Upon entering a level, they will need to meet a threshold of points for that level or else they will lose the game
- Each level will be designed using .txt files, and they will always be able to meet the minimum threshold to pass
- If the player wishes to gain more points from that level, they must hope that the candies randomly generate in their favor
- What a level may look like: [testLevel.txt](https://github.com/chgr4354/Project-3/files/11216922/testLevel.txt) (formatted correctly in console)
- CandyCrush mechanics:
  - The player can choose to swap candies in any four directions
  - If the candy moves to a location where it matches with at least ____ other candies of the same color around it, the game will remove the matched candies and randomly generate new candies in their place (80% chance normal, 20% chance special)
  - For each candy that is removed, the player will earn ____ coins
  - The player will have a certain amount of tries (candy swaps) to complete the level which will depend on the difficulty they chose
  - Points will be determined by how many tries it took to complete the level (Fewer tries means MORE points)

- After completion of the level, they will have the option to buy items from trader using coins earned from level
- After buying items, they will encounter a monster they need to fight using their items (battle arena and fight options displayed)
- If the player defeats the monster, they will be returned to the main level selector map (lose game if defeated by monster)
- Upon returning to the main map, they can encounter misfortunes and will have depleted stats that they must recover before entering new level
- Process continues until third level and monster are defeated, where they must _________________, and then win the game.
*stats will be constantly displayed throughout game*
-After winning the game, the players score will be saved to leaderboard file, and a sorting algorithm will be implemented here to decide rankings

-Christian Green
