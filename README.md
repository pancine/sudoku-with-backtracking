# Resolving sudoku with backtracking
Works in this way: \
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/1e/Backtracking-no-backjumping.svg/1024px-Backtracking-no-backjumping.svg.png" alt="image" width="150x150"/> <img src="https://gifdownload.net/wp-content/uploads/2019/01/backtracking-gif-.gif" alt="gif" width="150x150"/>

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
## Game in matrix
(0,0)(0,1)(0,2)(0,3)(0,4)(0,5)(0,6)(0,7)(0,8)\
(1,0)(1,1)(1,2)(1,3)(1,4)(1,5)(1,6)(1,7)(1,8)\
(2,0)(2,1)(2,2)(2,3)(2,4)(2,5)(2,6)(2,7)(2,8)\
(3,0)(3,1)(3,2)(3,3)(3,4)(3,5)(3,6)(3,7)(3,8)\
(4,0)(4,1)(4,2)(4,3)(4,4)(4,5)(4,6)(4,7)(4,8)\
(5,0)(5,1)(5,2)(5,3)(5,4)(5,5)(5,6)(5,7)(5,8)\
(6,0)(6,1)(6,2)(6,3)(6,4)(6,5)(6,6)(6,7)(6,8)\
(7,0)(7,1)(7,2)(7,3)(7,4)(7,5)(7,6)(7,7)(7,8)\
(8,0)(8,1)(8,2)(8,3)(8,4)(8,5)(8,6)(8,7)(8,8)

## FILE
Your game must be on this format:
- 0 for no number
- space between numbers
- endline with ;

##### source
image: https://pt.wikipedia.org/wiki/Backtracking \
gif: https://gifdownload.net/backtracking-gif/
