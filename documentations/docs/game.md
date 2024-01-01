### Game architecture

R-Type's game architecture is designed to deliver a compelling single-player or multiplayer experience. Here's an overview of the key classes and components that form the basis of our architecture.

## Class
Here are the classes, structs, unions and interfaces with brief descriptions:

[Button](button.md) Class for handle button <br><br>
[Client](client.md) Class for client service network<br><br>
[CreateRoom](room.md) Class for creation of a room for multiplayer game<br><br>
[Entity_t](entity.md) ECS<br><br>
[Game](game.md) Class for game logic<br><br>
[IClient](iclient.md) 	Client interface<br><br>
[JoinRoom](join.md)  Join room after login<br><br>
[I_queue](ique.md)<br><br>
[ListRoom](lobby.md)  Class for listing room for client<br><br>
[Lobby](list.md)<br><br>
[LoginPage](login.md) Class login page logic<br><br>
[Messasges](message.md)<br><br>
[Player](player.md) Player class<br><br>
[Registry](registry.md)	Class for handle registry<br><br>
[Room](room.md)	Class for playerRoom<br><br>
[Server](server.md)<br><br>
[Sound](sound.md) Class for Sound<br><br>
[sparse_array](spase.md)<br><br>
[Sprite](sprite.md)	Sprite class<br><br>
[Text](text.md)	Handle text<br><br>
[TextBox](textBox.md) Text input class<br><br>
[Window](window.md) Handle window

The diagram above illustrates the main game classes and their relationships. You can see how GameServer and GameClient interact to maintain game state and provide an immersive user experience.

## Data flow

Game data flows between the GameServer and GameClients. Players send their actions to the server, which processes the commands, updates the game state, then sends the data back to the clients. Interactions, such as shooting, are handled by the collision system.

## Event management

We use an event system to manage interactions between classes. For example, when a player shoots an enemy, an event is triggered to manage damage and effects.

## Good coding practices

We follow PEP 8 naming conventions to ensure code consistency.
All classes are documented with docstrings to explain their use and methods.
## External resources

We use the XYZ network library to manage communication between server and clients. You can find the documentation for this library here