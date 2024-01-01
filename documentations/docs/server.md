# Server Class Reference
### Public Member Functions
###### Server(io_context &, int port)
&nbsp; The server constructor that takes an io_context object and a port number as parameters.
###### Server(Server &)
&nbsp; A copy constructor.
###### ~Server()
&nbsp; The destructor of the class that releases the resources associated with the server.
###### void send_to_client(std::string message, unsigned int client_id)
&nbsp; This method is used to send a message to a specific client identified by its client_id.
###### void send_to_all_client(std::string message)
&nbsp; This method sends a message to all connected clients.
###### void display_all_client()
&nbsp; A method that could be used to display the list of connected clients.
###### void start_receive(), void handle_receive(...), void handle_send(...), void run_service()
&nbsp; These private methods are probably used to manage the sending and receiving of messages between the server and clients via the UDP protocol.
###### unsigned int get_client_id(udp::endpoint endpoint)
&nbsp; A method that appears to assign a unique identifier to a client based on its endpoint.
###### void send(std::string message, udp::endpoint target_endpoint)&nbsp; A method for sending a message to a specific endpoint.
###### unsigned int create_client_id(udp::endpoint endpoint)
&nbsp; This method creates a client identifier based on the client endpoint.
###### void client_disconnected(int id)
&nbsp; This method manages the disconnection of a client based on its id.