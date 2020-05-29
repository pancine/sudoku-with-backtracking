import numpy as np

def creategame(FILE):
    f = open(FILE, "r")
    game = np.mat(f.read())
    f.close()
    return game

def checkrow(game, row, num):
    for x in range(9):
        if game[row, x] == num:
            return False
    return True

def checkcolumn(game, column, num):
    for x in range(9):
        if game[x, column] == num:
            return False
    return True

def checksquare(game, square, num):
    if square < 3:
        if square == 0:
            if num in game[0:3, 0:3]:
                return False
            return True
        elif square == 1:
            if num in game[0:3, 3:6]:
                return False
            return True
        elif square == 2:
            if num in game[0:3, 6:9]:
                return False
            return True
    elif square < 6:
        if square == 3:
            if num in game[3:6, 0:3]:
                return False
            return True
        elif square == 4:
            if num in game[3:6, 3:6]:
                return False
            return True
        elif square == 5:
            if num in game[3:6, 6:9]:
                return False
            return True
    else:
        if square == 6:
            if num in game[6:9, 0:3]:
                return False
            return True
        if square == 7:
            if num in game[6:9, 3:6]:
                return False
            return True
        if square == 8:
            if num in game[6:9, 6:9]:
                return False
            return True

def whichsquare(row, column):
    if row < 3:
        if column < 3:
            return 0
        elif column < 6:
            return 1
        else:
            return 2
    elif row < 6:
        if column < 3:
            return 3
        elif column < 6:
            return 4
        else:
            return 5
    else:
        if column < 3:
            return 6
        elif column < 6:
            return 7
        else:
            return 8

def check(game, row, column, square, num):
    x = checkrow(game, row, num)
    y = checkcolumn(game, column, num)
    z = checksquare(game, square, num)
    if x and y and z:
        return True
    return False

def next(row, column):
    if (column + 1) > 8:
        return (row + 1, 0)
    return (row, column + 1)

def find0(game, coord=(0, 0)):
    row, column = coord
    if game[row, column] != 0:
        return find0(game, next(row, column))
    return coord

def complete(game):
    if 0 in game:
        return False
    return True

def solving(game, row=0, column=0):

    if complete(game):
        return True
    for x in range(1, 10):
        row, column = find0(game, (row, column))
        if check(game, row, column, whichsquare(row, column), x):
            game[row, column] = x
            if solving(game):
                return True
            game[row, column] = 0
    return False

def main():
    sudoku = creategame('Sudoku.txt')
    solving(sudoku)
    print(sudoku)
