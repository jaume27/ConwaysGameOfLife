> [!WARNING]
> README IS NOT FINISHED
# ConwaysGameOfLife
Conway's game of Life in C++.

## 1. How to execute the code

First, you have to compile the code in the terminal (I use g++). Then you have to execute the file *.x giving them a *.txt with the examples of living cells

```Shell
g++ Conways_GameOfLife.cc -o Conways_GameOfLife.x
./Conways_GameOfLife.x < Examples/1.txt
```
## 2. How to create coordinates files (*.txt)

- The first two characters will be the background character and then the living cell character [^footnote].
- Then you have to introduce a list of coordinates (i,j) that will specify the place where the living cells will be placed.
  
| Column 1        | Column 2      |
| :-------------  | :-------------|
| Background char | Cell char     |
| i<sub>1</sub>   | j<sub>1</sub> |
| .<br/>.<br/>.   | .<br/>.<br/>. |
| i<sub>k</sub>   | j<sub>K</sub> |


> You can also copy the values ​​directly to the terminal. Although it's easier to create a file as called and then redirect the input file as explained in the first point [Go to 1.](#1-How-to-execute-the-code)

### 2.1 Examples

+ _Example 1_

File [1.txt](Examples/1.txt)

The first example it is shown the desintegration of a pattern. It's named _The R-pentomino_

| Visualization  |
| :------------- |
|![image](https://github.com/jaume27/ConwaysGameOfLife/assets/149974083/dd618320-c0a6-42a3-8343-e6077b8ec723)<br/> *The R-pentomino*|                                            

```
.  @
40 30
41 30
41 31
41 32
42 31
```
+ _Example 2_                                                                                                             

File [2.txt](Examples/2.txt)

The second example is a type of pattern that is part of the constructor family. That pattern specifically in n iterations it create a new patternd called _Glider_ that is in the family of spaceships.

| Visualization  |
| :------------- |
|![image](https://upload.wikimedia.org/wikipedia/commons/e/e0/Game_of_life_glider_gun.svg)<br/> *Gosper glider gun*|

```
. #
2 6
3 6
2 7
3 7

14 4
15 4
13 5
12 6
12 7
12 8
13 9
14 10
15 10
16 7
17 5
17 9
18 6
18 7
18 8
19 7

22 6
22 5
22 4
23 6
23 5
23 4
24 3
24 7
26 2
26 3
26 7
26 8

36 4
36 5
37 4
37 5
```

                                                                                            
                                                                                                                
                                                                                                          

## 3. General information

### 3.1. Delay

The refresh rate of the program is 50 ms. To change it:
```C++
std::this_thread::sleep_for("50ms"); //OLD Delay
std::this_thread::sleep_for(INTEGRER + "ms"); //NEW Delay
```

### 3.2. Width
 > _The dimensions of the board are W x 2*W, to make the ilusion of a square_

To modify the width of the screen it has to be changes the constant value ```W```:

```C++
const int W = 50; \\OLD Width
const int W = INTEGRER; \\NEW Width
```
> If the width is bigger enought to not fit the terminal the program will not work correctly.
> <br/>Also if i<sub>1...k</sub> > ```W``` or j<sub>1...k</sub> > ```2*W```, an IndexError will show up.




[^footnote]: The characters that are selected have to be from the basic ascii table. [ASCII Table](https://ca.wikipedia.org/wiki/ASCII)
