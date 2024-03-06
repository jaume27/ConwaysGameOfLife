# ConwaysGameOfLife
Conway's game of Life in C++. 

> For more explanations of Conways Game of Life [Click here](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

## 1. Rules of Conway's Game of Life

- Rool 1: If a living cell has 2 or 3 cels around living keeps as a living cell.
- Rool 2: If a living cell has less than 2 cels living around it the cell dies due to underpopulation.
- Rool 3: If a living cell has more than 3 cels living around it the cell dies due to overpopulation.
- Rool 4: If a dead cell is sorrounded with exactly three living cells becomes a living cell, due to reproduction.

## 2. How to execute the code

First, you have to compile the code in the terminal (I use g++). Then you have to execute the file *.x giving them a *.txt with the examples of living cells

```Shell
g++ Conways_GameOfLife.cc -o Conways_GameOfLife.x
./Conways_GameOfLife.x < Examples/1.txt
```
## 3. How to create coordinates files (*.txt)

- The first two characters will be the background character and then the living cell character [^footnote].
- Then you have to introduce a list of coordinates (i,j) that will specify the place where the living cells will be placed.
  
| Column 1        | Column 2      |
| :-------------  | :-------------|
| Background char | Cell char     |
| i<sub>1</sub>   | j<sub>1</sub> |
| .<br/>.<br/>.   | .<br/>.<br/>. |
| i<sub>k</sub>   | j<sub>K</sub> |

> You can also copy the values ​​directly to the terminal. Although it's easier to create a file as called and then redirect the input file as explained in the first point [Go to 1.](#1-How-to-execute-the-code)

### 3.1 Examples

#### Example 1 </br>&nbsp;<sub>File [1.txt](Examples/1.txt)</sub>

The first example it is shown the desintegration of a pattern. It's named _The R-pentomino_

| Visualization  |
| :------------- |
|![image](https://github.com/jaume27/ConwaysGameOfLife/assets/149974083/dd618320-c0a6-42a3-8343-e6077b8ec723)<br/> *The R-pentomino*|                                            

#### Example 2 </br>&nbsp;<sub>File [2.txt](Examples/2.txt)</sub>

The second example is a type of pattern that is part of the constructor family. That pattern specifically in n iterations it create a new patternd called _Glider_ that is in the family of spaceships.

| Visualization  |
| :------------- |
|![image](https://upload.wikimedia.org/wikipedia/commons/e/e0/Game_of_life_glider_gun.svg)<br/> *Gosper glider gun*|                                                                          

#### More examples in the future
> You can also upload your own examples in the repository

## 4. General information

### 4.1. Delay

The refresh rate of the program is 50 ms. To change it:
```C++
std::this_thread::sleep_for("50ms"); //OLD Delay
std::this_thread::sleep_for(INTEGRER + "ms"); //NEW Delay
```

### 4.2. Width
 > _The dimensions of the board are W x 2*W, to make the ilusion of a square_

To modify the width of the screen it has to be changes the constant value ```W```:

```C++
const int W = 50; \\OLD Width
const int W = INTEGRER; \\NEW Width
```
> If the width is bigger enought to not fit the terminal the program will not work correctly.
> <br/>Also if i<sub>1...k</sub> > ```W``` or j<sub>1...k</sub> > ```2*W```, an IndexError will show up.

### 4.3 Terminal visualization

To show every iteration correctly in the terminal, without any deformations and in the same position too, I have used [ANSI Escape Codes](https://en.wikipedia.org/wiki/ANSI_escape_code). </br>
And I used this usefull [repository](https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797#file-ansi-md) to understand all the diferent arguments of this type of codes.

```C++
cout<<"\x1b[2J"; // Erase all the terminal (When the program starts)
cout<<"\x1b[H"; // Erase the board (Every iteration)
```


[^footnote]: The characters that are selected have to be from the basic ascii table. [ASCII Table](https://ca.wikipedia.org/wiki/ASCII)
