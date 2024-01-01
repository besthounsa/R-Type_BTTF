# ListRoom Class Reference
class for listing room for client.
include "List_room.hpp"

### Public Member Functions
###### ListRoom ()
&nbsp; Construct a new List Room object.
###### ListRoom()
&nbsp; Class constructor. It initializes members and loads the font.
###### ~ListRoom()
&nbsp; Class destructor.
###### void handle_event(sf::Event event, std::shared_ptr< sf::RenderWindow> window)
&nbsp; This method handles events related to the user interface, such as closing the window and reacting to the hover and selection of the "Join" button.
###### std::string get_room_name()
&nbsp; This method returns the name of the selected room.
###### int get_run()
&nbsp; This method returns the current state of the class.
###### void set_room_name(std::string name)
&nbsp; This method sets the name of the room the user wishes to join.
###### void set_run(int state)
&nbsp; This method modifies the current state of the class.
###### void draw_lpage(std::shared_ptr< sf::RenderWindow > *window) &nbsp; This method handles the rendering of the user interface, including the display of the "Join" button and the selected game room.
###### void set_room_list(Room *room)
&nbsp; This method sets the game room to be joined.
###### void start_lobby( Window &window, registry &r, ISystem sys, int *run, std::string room, Client &client)
&nbsp; This method is used to start the game room user interface. It handles events, rendering and creation of the game room.