# Room Class Reference
class for playerRoom.
include "room_client.hpp"

### Public Member Functions
###### void set_nb_players(int nb_players)
&nbsp; This method sets the current number of players in the room. However, there seems to be a check to ensure that nb_players is less than 2 before updating the nb_players attribute.
###### void draw(std::shared_ptr<sf::RenderWindow> *window)
&nbsp; This method is used to draw the room, in particular the button associated with the room, on a rendering window.
###### Button get_button()
&nbsp; This method returns the Button object associated with the room, presumably to allow other parts of the program to access and manipulate this button.
###### void set_status()
&nbsp; This method appears to set the status of the room according to the number of players. If the number of players reaches 2, the button color is set to red.
###### void set_nb_player(int nb_players)
&nbsp; This method sets the number of players in the room.
###### std::string get_room_name()
&nbsp; This method returns the room name.