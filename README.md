# The Snake
## Created with C++14 and QT 5.13.2

### Description 
Set the starting speed and snake length before playing. 
Controll the snake with arrow keys. Enjoy the game.


## Game class
Once initialized, the menu window appears and asks for input. No input means using hardcoded values. Game starts when *Start Game* button is hit.

#### Fields
 Variable | Description                    
 ------------- | ------------------------------ 
 `Board* board`      | The Board class       
 `Menu* menu`   | The Menu class
 
#### Methods
 Method signature | Description                    
 ------------- | ------------------------------- 
 `startGame()`      | Close the menu, initialize the Board.       
 `quitGame()`   | Close the application.    
 
 
## Menu class
Prompts the player for input. Passes the input for the Board class.

#### Fields
 Variable | Description                    
 ------------- | ------------------------------ 
 `Ui::Menu ui`      | Menu window which appears when staring the app      
 `int time`   | Containts the game time from input    
 `int snakeLength`   | Containts the snake length from input    
 
#### Methods
 Method signature | Description                    
 ------------- | ------------------------------ 
`void setLength(int)`      | `snakeLength` setter       
 `int getLength() const`   |`snakeLength` getter    
 `void setTime(int)`   | `time` setter    
 `int getTime() const`   | `time` getter    
 
 #### Slots
 Slot signature | Description                    
 ------------- | ------------------------------ 
 `void on_startGameButton_clicked()` | Gathers input from text windows and emits `startGame()` signal
 `void on_quitGameButton_clicked()` | Emits `quitGame()` signal
 
 #### Signals
 `void startGame() const` | Received by Game's `startGame()` slot
 `void quitGame() const` | Received by Game `quitGame()` slot
 
 
## Controller class
Controlls the timers which make the snake move and fruit appear.
- Variable *gameTimer*  contains game elapsed time.
- When needed, the Controller object stops or restarts the game. 
- When the game ends the object gives the player total score and prompts to play again or quit.

#### Fields
 Variable | Description                    
 ------------- | ------------------------------ 
 `QGraphicsScene* gameScene` | Scene displaying game objects
 `Snake* snake` | Snake pointer
 `QTimer* snakeTimer` | Moves the snake with `Data::snakeLatencySpeed`  `QTimer* fruitTimer` | Spawns fruits with `Data::snakeLatencySpeed`
 `QElapsedTimer* gameTimer` | Counts elapsed time.
 `int gameTime` | Used when starting a new game
 `int snakeLength |  Used in Snake constructor and when starting a new game
 `static int score` | Player's score
 `static int fruitsNumber` | Containts the current number of fruits in the `gameScene`

#### Methods
 Method signature | Description                    
 ------------- | ------------------------------ 
 `Controller(QGraphicsScene*, QObject*, int, int) | Initializes the timers and the snake
 `void startTimers() const` | Starts the timers
 `void stopTimers() const` | Stops the timer
 `void restartGame()` | Start timers and reinitialize `snake`, set `score` and `fruitsNumber` to 0
 `void stopGame()` | Calls `stopTimers()` and ask the player to play again or quit.
 `void quitGame() const` | Closes the app
 `QString gameEndMessage() const` | Shows the total score multiplied by 10
 `void keyPressEvent(QKeyEvent*)` | Reads key input from the player
 `bool eventFilter(QObject*, QEvent* event) override` | Calls `keyPressEvent(event)`
 `bool checkFruitsNumber() const` | Returns true if `fruitsNumber` is greater or equal than `Data::maxFruitNumber`
 `void CheckCollisions()` | Call all the checking methods below
 `bool checkWallCollision() const` | Returns true whenever `snake` hits a wall(window border)
 `bool checkSnakeCollision() const` | Returns true if `snake` eats itself
 `void checkItemCollision() const` | Checks if snake`snake`'s eaten a fruit
 
 #### Slots
  Slot signature | Description                    
 ------------- | ------------------------------ 
 `void spawnFruit()` | Spawns a fruit if `checkFruitsNumber()` return false
 `void moveSnake()` | If elapsed time is less than `gameTime`, `snake` is moved
 
 







