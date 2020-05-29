# Resolving sudoku with backtracking
Works in this way:
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/1e/Backtracking-no-backjumping.svg/1024px-Backtracking-no-backjumping.svg.png" alt="drawing" width="100x100"/>

![alt text](https://gifdownload.net/wp-content/uploads/2019/01/backtracking-gif-.gif)

## Functions
```python
creategame(FILE) #create game from FILE
checkrow(game, row, num) #check if num is in row
checkcolumn(game, column, num) #check if num in is column
checksquare(game, square, num) #check if num is in 3x3 square
whichsquare(row, column) #return which square based on (row,column)
check(game, row, column, square, num) #check if num can be used
next(row, column) #next position
find0(game, coord=(0, 0)) #find next position with a 0
complete(game) #return True if completed all the grid
solving(game, row=0, column=0) #backtracking solution
main() #run the solve
```
## Game in row
[00][01][02][03][04][05][06][07][08]\
[09][10][11][12][13][14][15][16][17]\
[18][19][20][21][22][23][24][25][26]\
[27][28][29][30][31][32][33][34][35]\
[36][37][38][39][40][41][42][43][44]\
[45][46][47][48][49][50][51][52][53]\
[54][55][56][57][58][59][60][61][62]\
[63][64][65][66][67][68][69][70][71]\
[72][73][74][75][76][77][78][79][80]\

## FILE
Your game must be on this format:
- 0 for no number
- space between numbers
- endline with ;

##### source
image: https://pt.wikipedia.org/wiki/Backtracking \
gif: https://gifdownload.net/backtracking-gif/
