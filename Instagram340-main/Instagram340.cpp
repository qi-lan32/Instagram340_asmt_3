// TO DO: Implementation of Instagram340 functions
#include <iostream>
#include <string>
#include <memory>
#include "Instagram340.h"
#include "LinkedBagDS/LinkedBag.h"
#include "User.h"

using namespace std;

//constructor
Instagram340::Instagram340()
    :users(){
}
//destructor
Instagram340::~Instagram340(){
	Instagram340::users.clear();
}

//FUNCTIONS
//Create user and append to list of users
void Instagram340::createUser(const std::string& username, const std::string& email, const std::string& password,
				const std::string& bio, const std::string& profilePicture){
    users.append(make_unique<User>(username, email, password, bio, profilePicture));
}

//find and return user at indexk
unique_ptr<User> Instagram340::getUser(const int& indexK){
    Node<unique_ptr<User>>* curr = users.getHeadPtr();
	// iterate through users until we reach the node at indexK
    for(int i = 0; i < indexK; i++){
        curr = curr->getNext();
    }
    return curr->getItem();  //return the node at index k
}