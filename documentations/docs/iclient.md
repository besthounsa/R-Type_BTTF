#IClient Class Reference
client interface<br>
include "IClient.hpp"

## Public Member Functions
###### IClient()
&nbsp; Construct a new IClient object.
###### ~IClient ()
&nbsp; Destroy the IClient object.
###### void startGame()
&nbsp; This function is used to start the game.
###### void handle_event(sf::Event event, std::shared_ptr< sf::RenderWindow >(wwindow), int *sf)
&nbsp; The function that handles events related to the game window.
###### Client &get_client()
&nbsp; A function that returns a reference to the Client object, allowing access to connection management functionalities.