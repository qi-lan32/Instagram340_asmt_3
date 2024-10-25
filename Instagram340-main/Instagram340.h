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
		LinkedBag<std::unique_ptr<User>> users;

	public:
		Instagram340();
		~Instagram340();

		void createUser(const std::string& username, const std::string& email, const std::string& password,
						const std::string& bio, const std::string& profilePicture);

        std::unique_ptr<User> getUser(const int& indexK);
};

#endif