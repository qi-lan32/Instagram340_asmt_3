! asmt 2 portion functional 
  - implement all necessary classes and header files: Post, Reel, Story, User, Instagram340
  - implement 2 methods in LinkedBag: append and findKthItem

  * at least one instance of inheritance
  * at least one use of polymorphism

---

... onto asmt 3 upgrade and implementation 
  -  change linked bag to using smart ptrs, choose the right type
  -  *friend func* - a) initialize User profile b) initialize Posts (Reel and Story)
       * display user profile info and posts
       * overload both << and >> operator in all classes
       *   ! in Instagram340, only need to overload << to display msg: "Welcome to Instagram 340!"
  - BIG 3 - implement the destructor, the copy constructor, and overload assignment operator
       *   ! include an implementation in all program classes

---
### Issues:
- had problem with re-implementing the program with smart ptrs (first used unique_ptr but cannot figure out, switched to shared_ptr)
> with unique_ptr, I touched the template classes of LinkedBag and Node, which was not suppose to matter because template classes should function with any data type or obj. After I decided to switch to shared_ptr, and rewinded the template classes back to their original state, made some corrections to my Instagram340, User and Main classes, it all worked out.

- overloaded operator << in all classes (instagram340, post, reel, story, and user); at first, the << would only print the message from post but not reel and story.
> I found the problem was that because the << overloading is not virtual, therefore the derived overloading << can not be accessed. The solution to this is to make the printPost() to return an 'ostream& os' and make the << overload function call the printPost() in the class of the object that called it. This way, when we use << to print out the reel/story object, it will call the corresponding printPost() method in its class through the << operator. 
