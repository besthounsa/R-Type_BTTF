#player Class Reference
Player class.
include "player.hpp"

### Public Member Functions
###### Player(Sprite sprite, std::string name)
&nbsp; The Player class constructor takes two parameters:<br>
sprite sprite The sprite associated with the player.<br>
std::string name : The player's name.
###### ~Player()
&nbsp; The destructor of the Player class.
###### void move_player(Input input)
&nbsp; This method moves the player according to the input supplied as a parameter. Input can be used to determine the player's direction of movement, for example in response to keyboard commands.
###### Sprite get_sprite()
&nbsp; This method returns the sprite associated with the player. The sprite represents the player's visual appearance in the game.
###### std::string get_name()
&nbsp; This method returns the player's name. The name can be used to identify the player in the game.