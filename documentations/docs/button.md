# Button Class reference

class for handle button<br>
include "Button.hpp"

### Public Member Functions
##### Button()
&nbsp; Default constructor for construct a new button.

Button(std::string t, sf::Vector2f size, sf::Color bgColor, sf::Color textColor, sf::Font &font)<br>
&nbsp; Construct a new Button object.
###### Parameters
    t
    size
    bgColor
    textColor
    font
###### ~Button()
&nbsp; Destroy the button object.
###### void setBackColor(sf::Color color)
&nbsp; Set the Back Color object.
###### void setTextColor(sf::Color color)
&nbsp; Set the Text Color object.
###### void setFont(sf::Font &font)
&nbsp; Set the Font object.
###### void setPosition(sf::Vector2f pos)
&nbsp; Set the Position object.
###### void draw_button (std::shared_ptr< sf::RenderWindow >(window))
&nbsp; Draw a button.
###### void set_size (sf::Vector2f size)
&nbsp; Set the size object.
###### void set_name (std::string name)
&nbsp;Set the name object.
###### bool isMouseOver (std::shared_ptr< sf::RenderWindow > window)<
&nbsp;check is mouse over the button