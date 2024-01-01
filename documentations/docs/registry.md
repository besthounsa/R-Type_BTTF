# registry Class Reference
class for handle registry.
include "registry.hpp"
### Public Member Functions
###### template <class Component> sparse_array<Component> &register_component()
&nbsp; This method registers a component type (Component) in the registry. It returns a reference to the array (sparse_array) associated with this component type. Each component type has a dedicated array to store specific data.
###### template <class Component> sparse_array<Component> &get_components()
&nbsp; This method returns a reference to the array (sparse_array) associated with the specified component type. It is used to access data for a given component type.
###### entity_t spawn_entity()
&nbsp; This method creates a new entity and returns an entity_t object representing that entity. Entities are abstract objects used to link components together.
###### entity_t entity_from_index(std::size_t idx)
&nbsp; This method returns an entity according to the specified index. It can be used to obtain an existing entity from its index.
###### void kill_entity(entity_t const &e)
&nbsp; This method has no implementation in the code you've provided, but is probably intended to "kill" (or delete) a specified entity.
###### template <typename Component> typename sparse_array<Component>::reference_type add_component(entity_t const &to, Component &&c)
&nbsp; This method adds a component (Component instance) to a specified entity. The use of && indicates that the component is added as an rvalue, which can be useful for memory management.
###### template < typename Component> typename sparse_array< Component>::reference_type add_component(entity_t const &to, Component &c)
&nbsp; This method adds a component (Component instance) to a specified entity, but this time as a lvalue (reference).
###### template < typename Component, typename... Params> typename sparse_array< Component>::reference_type emplace_component(entity_t const &to, Params &&...p)
&nbsp; This method could be used to add a component (Component instance) to an entity using the emplace construct. Params variadic parameters can be used to provide construction arguments.
###### template <typename Component> void remove_component(entity_t const &from)
&nbsp; This method could be used to remove a component from a specified entity. However, this method is not implemented in the code you've provided.