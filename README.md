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
 `Board* board` | The Board class       
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
  Signal signature | Description                    
 ------------- | ------------------------------ 
 `void startGame() const` | Received by Game's `startGame()` slot
 `void quitGame() const` | Received by Game `quitGame()` slot
 
 
## Controller class
Controlls the timers which make the snake move and fruit appear.
- Variable *gameTimer* contains game elapsed time.
- When needed, the Controller object stops or restarts the game. 
- When the game ends the object gives the player total score and prompts to play again or quit.

#### Fields
 Variable | Description                    
 ------------- | ------------------------------ 
 `QGraphicsScene* gameScene` | Scene displaying game objects
 `Snake* snake` | Snake pointer
 `QTimer* snakeTimer` | Moves the snake with `Data::snakeLatencySpeed`  `QTimer* fruitTimer` | Spawns fruits with  `Data::snakeLatencySpeed`
 `QElapsedTimer* gameTimer` | Counts elapsed time.
 `int gameTime` | Used when starting a new game
 `int snakeLength` |  Used in Snake constructor and when starting a new game
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
 
 ## Snake class
Snake is a moving set of points. Its shape is a set of circles painted on the points coordinates. The biggest circle is the head. The snake grows when a fruit is eaten. Is controlled with arrow keys, can move in any direction except diagonal. Inherits from  `QGraphicsItem`. 

### Fields
 Variable | Description                    
 ------------- | ------------------------------
 `QPointF head` | Point containing coordinates of snake's head
 `QVector<QPointF> tail` | Vector containing the coordinates of the tail points
 `QGraphicsScene* scene` | Pointer to `Board`'s `scene`. Used to remove eaten fruits from `scene`
 `Data::Direction direction` | Enum containing info about the direction snake's heading to. Initial `direction` is set to `Data::Direction::Right`
 `int velocity` | Current snake's speed
 `int xDirection` | How far can snake go in left or right, set by `velocity`. Initialized with `Data::velocity`
 `int yDirection` | How far can snake go in up or down, set by `velocity`. Initialized with 0
 `int snakeLength` | Snake's length
 `int toGrow` | How many `QPointF` coordinates to add to `tail`
 
  ### Methods
Method signature | Description                    
 ------------- | ------------------------------ 
 `Snake(QGraphicsScene* gameScene, int snakeLength)` | Set  `head` coordinates to the middle of the `gameScene`
 `QPainterPath shape() const` | Sets snake's shape to a set of circles based on `head` and `tail` points
 `QRectF boundingRect() const` | Sets a rectangular shape to the body.
 `void paint()` | Paints the shape
 `void move()` | Updates `head` and `tail` positions
 `bool wallHit()` | Returns true if `head` coordinates met a frame of `scene`
 `void goThroughWall()` | Checks which wall was hit by `head` and makes it appear on the opposite side of the `scene`
 `void eatFruit()` | Removes the eaten fruit, increases `Controller::score`, makes the snake grow
 `void checkCollision()` | Eats a fruit if any was hit by `head`
 `void moveLeft()` | Sets `xDirection` to `-velocity` and `yDirection` to `0`. Thus `direciton` is set to `Data::Direction::Left` 
 `void moveRight()` | Sets `xDirection` to `velocity` and `yDirection` to `0`. Thus `direciton` is set to `Data::Direction::Right` 
 `void moveUp()` | Sets `xDirection` to `0` and `yDirection` to `-velocity`. Thus `direciton` is set to `Data::Direction::Up` 
 `void moveDown()` | Sets `xDirection` to `0` and `yDirection` to `velocity`. Thus `direciton` is set to `Data::Direction::Down` 
 `bool intersects() const` |  When `tail` contains `head` it means that snake's eaten itself. Returns true so
 `void updateHead()` | Sets `head.x()` to `head.x() + xDirection` and `head.y()` to `head.y() + yDirection`
 `void updateTail()` | Adds a new `QPointF` to `tail`.
 
 
 
## Board class
Board is responsible for displaying snake, its movement, and furit. Inherits from `QGraphicsView`.

### Fields
 Variable | Description                    
 ------------- | ------------------------------ 
 `QGraphicsScene* scene` | Surface to manage 2D objects
 `Controller* controller` | Initialized at the same time as the Board
 
 ### Methods
Method signature | Description                    
 ------------- | ------------------------------ 
 `Board(int, int)` | Initializes `controller` and `scene`, sets the background
 
 
## Fruit class
A 2D object inheriting from `QGraphicsItem`. When eaten, enlengthens the snake.

 ### Methods
Method signature | Description                    
 ------------- | ------------------------------ 
`Fruit(qreal, qreal)` | Sets the coordinates to given `qreal` variables
`QPainterPath shape() const` | Sets shape to circle
`QRectF boundingRect() const` | Sets `Fruit`'s boundary to a rectangle
`void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*)` | Paints the shape

## Contants.h
##### Contains all the game's constans used in the code.
 
 
