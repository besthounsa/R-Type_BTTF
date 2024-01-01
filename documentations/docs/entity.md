# Client Entity_t reference
include "IEntity.hpp"<br>
The entity_t class is designed to represent an entity in an unspecified context. It is used to store an id associated with the entity.
### Public Member Functions
###### Entity(std::size_t id)
&nbsp; Construct a new entity_t.
###### Entity_t()
&nbsp; A default constructor that creates an entity_t object without specifying an identifier.
###### ~Entity_t()
&nbsp; Destroy the entity_t object.
###### operator std::size_t() const
&nbsp; This operator allows an entity_t object to be used in an expression as if it were a std::size_t. It simply returns the entity id.

##Example
/--------------------------------------------------------------------------------------------------<br>
|entity_t entity1(42); // Creates an entity with identifier 42\\<br>|
std::size_t id = entity1; // Use the conversion operator to obtain the identifier\\<br>|
entity_t entity2; // Creates an entity without specifying an identifier\\<br>|
std::size_t id2 = entity2; // The identifier will be uninitialized (undefined behavior) \\<br>|---------------------------------------------------------------------------------------------------

