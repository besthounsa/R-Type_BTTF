# JoinRoom Class Reference
join room after login.
include "join_room.hpp"

## Public Member Functions
###### JoinRoom()
&nbsp;Construct a new Join Room object.
###### ~JoinRoom ()
&nbsp; Destroy the Join Room object.
###### Void handle_event (sf::Event event, std::shared_ptr< sf::RenderWindow > window, Client &client)
This fonction manages events linked to the game window, such as closing the window, detecting when the "Start" button is hovered over and clicking on it. It also sends a message to the server to indicate that the user wishes to join the room.
###### std::string 	get_room_name()
&nbsp; Get the room name object
###### int get_run ()
&nbsp; Returns the execution status of the JoinRoom class.
###### void set_room_name (std::string name)
&nbsp; Set the room name object.
###### void set_run (int state)
&nbsp; Defines the execution state of the JoinRoom class.
###### void draw_lpage (std::shared_ptr< sf::RenderWindow > *window)
&nbsp; A public method that draws the "Start" button and the game room on the specified window.
###### voidcstart_lobby (Window &window, registry &r, ISystem sys, int *run, Client &client)
&nbsp; The public method that manages the game waiting room process. It sends a message to the server to indicate that the user wishes to join the room, then handles window events, renders the game system and the waiting room.