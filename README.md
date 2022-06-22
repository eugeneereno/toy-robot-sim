# Toy Robot Simulator

## Description
 - This application is a simulation of a toy robot moving on a square table top, of dimensions 5 units x 5 units.
 - There are no obstructions to the table surface.
 - The robot is free to roam around the surface of the table, and is prevented from falling to destruction.
 - Any movement or placement that would result in the robot falling is prohibited, however further valid movement commands are still allowed.

## Commands
The following commands can be inputted as standard input

```
PLACE X,Y,F
MOVE
LEFT
RIGHT
REPORT
```
 - PLACE will put the toy robot on the table in position X,Y and facing NORTH, EAST, WEST or SOUTH. The origin (0,0) can be considered to be the SOUTH WEST most corner. It is required that the first command to the robot is a PLACE command, after that, any sequence of commands may be issued, in any order, including another PLACE command. This application will discard all commands in the sequence until a valid PLACE command has been executed.
 - MOVE will move the toy robot one unit forward in the direction it is currently facing.
 - LEFT and RIGHT will rotate the robot 90 degrees in the specified direction without changing the position of the robot.
 - REPORT will announce the X,Y and F of the robot.
 - Commands are case-insensitive.
 - An empty command will terminate the application.

 ## Run the Application

 ### Clone
 Clone the repository from ssh: `git@github.com:eugeneereno/toy-robot-sim.git`

 ### Dependencies
  - Visual Studio C++ Desktop Development
    - `MSVC v142`
    - `Test Adapter for Google Test`

 ### Build
  - It is recommended to open and build the project with `Visual Studio 2019`.
  - Press `F5` to build and run the application. Alternatively, you can just build the solution with the shortcut `Ctrl+Shift+B` then run the application as it is depending on your build configuration.
  ```
  .\Debug\toy-robot-sim.exe

  OR

  .\Release\toy-robot-sim.exe
  ```
  - Input the simulator commands to the console.

## Examples

Input
```
PLACE 0,0,NORTH
MOVE
REPORT
```

Expected Output
```
0,1,NORTH
```
---
Input
```
PLACE 0,0,NORTH
LEFT
REPORT
```

Expected Output
```
0,0,WEST
```
---
Input
```
PLACE 1,2,EAST
MOVE
MOVE
LEFT
MOVE
REPORT
```

Expected Output
```
3,3,NORTH
```
