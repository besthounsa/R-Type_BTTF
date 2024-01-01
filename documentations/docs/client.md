# Client Class reference
Class for handle button<br>
include "Client.hpp"<br>
The Client class uses Boost.Asio to manage network communication, in particular with the UDP protocol.

## Public Member Functions
###### Client(boost::asio::io_context& io_context, const std::string& host, const std::string& port);
Construct a new client object.It takes a reference to an io_context object, as well as strings to specify the host and port to connect to. It initializes the client's configuration for network communication.
##### Paramaters
- io_context
- host
- port
###### Client()
&nbsp; Construct a new client object.
###### ~Client()
&nbsp; Destroy the client object
###### void init(const std::string &host, const std::string &port)
&nbsp; init setting for the client. It is used to initialize the parameters of the Client object with the host and port values.
##### Parameters
- host
- port
