Sokoban
=======

![Sokoban Game](https://i.imgur.com/9HtXYzH.png)

The primary objective of this project is to refactor and enhance a simple [Sokoban](https://en.wikipedia.org/wiki/Sokoban) clone, originally written in a procedural programming style in C++, into an object-oriented design utilizing C++. This transformation should focus on encapsulating game functionalities into classes and objects, specifically targeting game levels and the player character code. Additionally, the project involves altering the level loading mechanism to dynamically parse level designs from `.sl` files, which utilize a specific run-length encoding format for level representation. A detailed description of the `.sl` file format can be found [here](http://www.sokobano.de/wiki/index.php?title=Level_format).

![Level 1 of the Sokoban Game](https://i.imgur.com/m36ioBe.png)
![Nearly finished Level 1 of the Sokoban Game](https://i.imgur.com/GKzoLfF.png)

This project aims to strengthen understanding of object-oriented programming (OOP) concepts such as encapsulation and data abstraction. It also introduces practical applications of exception handling for robust error management dealing with file input and output.

To get started, clone the repository to get the starter code. You are encouraged to modify and refactor it as needed to meet the project requirements.

![Level 2 of the Sokoban Game](https://i.imgur.com/zn9oNlA.png)

Be inventive in applying OOP principles to redesign the game, ensuring to implement the following critical modifications:

## Project Requirements

### Refactoring to Object-Oriented Design:

- **Level Class**: Convert the game level variables and related functions into an `level` class. This class should manage all aspects related to game levels, including storing level layout, and managing level state.

- **Player Class**: Transform player-related variables and functions into a `player` class. This class should encapsulate all player-related functionalities, such as movement, interaction with the game world, and player state management.

### Dynamic Level Loading:

- Implement functionality to parse and load levels from the `levels.sl` file located in the `data` directory. These file contain level designs encoded using a specific run-length encoding scheme. Your implementation must accurately parse these files, correctly interpret the run-length encoding, and construct playable levels from the data.

- Integrate robust error handling using exceptions to manage potential parsing and file-reading errors gracefully. This approach should ensure the game remains stable and provides informative feedback in the event of encountered errors.

## Additional Requirements:

- **Code Organization**: Maintain a clean and organized codebase. Structure your project into appropriate directories and files, ensuring a logical separation of classes, game assets, and other resources.

- **Readme.md**: Create a `Readme.md` file detailing your implementation, including a description of how you approached the refactoring process, any challenges faced, and how you overcame them. Also, document the steps required to set up and run your version of the game.

- **Commit History**: Develop your project with a detailed commit history in a version control system. Regular commits with descriptive messages are essential to demonstrate the progression and milestones of your project work.

![Victory Screen](https://i.imgur.com/aXJpy4P.png)

## Deliverables

* Develop the game within the `sokoban` directory. This directory should include a `data` subdirectory containing all game assets (images, fonts, sounds, etc.). Additionally, ensure the `sokoban` directory contains a `Readme.md` file detailing your game and listing the newly implemented features.

* Please, add forward declarations for each function, struct, or class in the `globals.h` file to prevent circular dependencies.

* Place your main game loop in the `sokoban.cpp` file, which should include `globals.h` and all other necessary header files.

Upon completion, your `sokoban` directory should have an organized structure similar to the following:

```
└── sokoban
    ├── . (.idea, .gitignore, CMakeLists.txt)
    ├── data
    │   ├── fonts
    │   │   └── ...
    │   ├── images
    │   │   └── ...
    │   ├── sounds
    │   │   └── ...
    │   └── levels.sl
    ├── src
    │   ├── sokoban.cpp
    │   ├── level.h
    │   ├── level.cpp
    │   ├── player.h
    │   ├── player.cpp
    │   └── <additional .cpp and .h files>
    └── Readme.md
```

## Deadline

Refer to the specific course or assignment page on Moodle for detailed information about deadlines.

## Resources

### Links

#### raylib

* [Wiki](https://github.com/raysan5/raylib/wiki)
* [Cheatsheet](https://www.raylib.com/cheatsheet/cheatsheet.html)
* [Examples](https://www.raylib.com/examples.html)

#### Tools

- [Piskel](https://www.piskelapp.com) for creating or editing game sprites.
- [bfxr](https://www.bfxr.net) for generating sound effects.

### Books

* Introduction to Programming with C++, 3rd Edition by Daniel Liang
