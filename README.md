# Minesweeper

A very simplistic version of Minesweeper which can be run via a terminal.

## Installing Minesweeper

1) Download ZIP of repository and extract file
2) Open terminal and reach directory of extracted file (via `cd <directory>`)
3) Write `cd src` 
4) Write `g++ Main.cpp Cell.cpp -o minesweeper`
5) Write `./minesweeper` to run program

## Setting Up Minesweeper

After writing `./minesweeper`, you will be prompted two times:

1) `Enter board dimensions (rows x cols)> ` where the user must write the number of wanted rows and columns in the grid, each followed by a space (e.g. `4 4`).
2) `Enter mine number> ` where the user must write the number of mines to occupy the grid (e.g. `5`).

## Playing Minesweeper

When prompted with `>` write the **action name**, **action row**, and **action col** with a space between each element.

**Action Name**: The action name (case-insensitive) will either be `R` for revealing a tile or `F` for flagging a tile. 

**Coordinates**: The **action row** and **action col** start at index 0, where `0 0` represents the leftmost cell in the grid.
