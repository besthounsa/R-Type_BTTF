# l_queue< T > Class
This Class represents a queue 

### Public Member Functions
###### void push(T value)
&nbsp; This method adds an element of type T to the end of the queue. It is protected by a lock to ensure security when adding elements.
###### T pop()
&nbsp; This method retrieves and deletes the element at the head of the queue, then returns it. It is also protected by a lock to ensure secure data access.
###### bool empty()
&nbsp; This method returns true if the queue is empty, otherwise false. It is also protected by a lock to ensure data consistency.
