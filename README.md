# ConwaysGameOfLife
Conway's game of Life in C++.

## How to execute the code

First you have to compile the code in the terminal (I use g++). Then you have to execute the file *.x giving them a *.txt with the examples of living cells

```
g++ Conways_GameOfLife.cc -o Conways_GameOfLife.x
./Conways_GameOfLife.x < Examples/1.txt
```
## How to create coordinates files (*.txt)

- The first two characters will be the background character and then the living cell character[¹].
- Then you have to introduce a list of coorfinates (i,j) that will specify the place where the living cells will be placed.
  
|Column 1| Column 2|
| :-------------  | :-------------|
| Background char | Cell char     |
| i<sub>1</sub>   | j<sub>1</sub> |
| ...             | ...           |
| i<sub>k</sub>   | j<sub>1</sub> |


> [!NOTE]
> README IS NOT FINISHED

[¹]: Prova the foot
