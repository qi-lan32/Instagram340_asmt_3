#ifndef INSTAGRAM340_H
#define INSTAGRAM340_H
#include "LinkedBagDS/LinkedBag.h"
// TO DO include necessary libraries
#include "User.h"
#include <memory>
 

// This class only contains a list of users
// It should allow clients to add users and retrieve a user from the list
class Instagram340 {
	private:
		LinkedBag<std::shared_ptr<User>> users;

	public:
		Instagram340();
        Instagram340(const Instagram340& other);
		~Instagram340();

        //create a new user
		void createUser(User& user);
        //operator << overloading function
        friend std::ostream& operator<<(std::ostream &os, const Instagram340 &insta340);
        //operator = overloading function
        Instagram340& operator=(const Instagram340& other);

        //getter
        const std::shared_ptr<User> getSpecificUser(const int& indexK) const;
};

#endif