# LoginPage Class Reference
Class login page logic<br>
include "loginpage.hpp"

### Public Member Functions
###### LoginPage ()
&nbsp; Construct a new Login Page object.
###### LoginPage()
&nbsp; Class constructor. Initializes members and loads font.
###### ~LoginPage()
&nbsp; Class destructor.
###### void handle_event(sf::Event *event, std::shared_ptr<sf::RenderWindow> *(wwindow), int *sf, Window *window)
&nbsp; This method handles events related to the user interface, such as window closing, text zone navigation and input management.
###### void handle_nav(sf::Event *event, int *sf)
&nbsp; This method handles text zone navigation by highlighting the selected text zone.
###### void handle_all_event(sf::Event event, std::shared_ptr<sf::RenderWindow> wwindow, int *sf, Window *window)
&nbsp; This method handles all user interface events, including input, window closing and navigation.
###### void start_loginpage(Window &window, registry &r, ISystem sys, int *run, sf::Event event, int *sf, std::shared_ptr<sf::RenderWindow> wwindow)
&nbsp; This method is used to start the login page user interface. It handles events, user input and transition to the game.
###### void draw_lpage(std::shared_ptr<sf::RenderWindow> *(wwindow)) 
&nbsp; This method handles the rendering of the user interface, including the display of text boxes and the "Enter game" button.
void set_playername(std::string plynm): This method sets the name of the player entered.
###### void set_serverport(std::string srvprt)
&nbsp; This method sets the entered server port.
###### void set_ipadress(std::string ipdrss)
&nbsp; This method sets the IP address of the server entered.
###### void set_run(int run)
&nbsp; This method modifies the current state of the class.
###### int get_run()
&nbsp; This method returns the current state of the class.
###### std::string get_playername()
&nbsp; This method returns the player name entered.
###### std::string get_serverport()
&nbsp; This method returns the server port entered.
###### std::string get_ipadress()
&nbsp; This method returns the server's IP address.