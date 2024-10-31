// TO DO: Implementation of Instagram340 functions
#include <iostream>
#include <memory>
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
//copy constructor
Instagram340::Instagram340(const Instagram340& other)
    :users(other.users){

}
//destructor
Instagram340::~Instagram340(){
	Instagram340::users.clear();
}

//FUNCTIONS
//Create user and append to list of users
void Instagram340::createUser(User& user){
    users.append(make_shared<User> (user));
}

//find and return user at indexk
const shared_ptr<User> Instagram340::getSpecificUser(const int& indexK) const{
    Node<shared_ptr<User>> *curr = users.getHeadPtr();
	// iterate through users until we reach the node at indexK
    for(int i = 0; i < indexK; i++){
        curr = curr->getNext();
    }
    return curr->getItem();  //return the node at index k
}

//overload operator cout <<
ostream& operator<<(ostream &os, const Instagram340 &insta340) {
    os << "Welcome to Instagram 340!" << endl;
    return os;
}
//overload operator =
Instagram340& Instagram340::operator=(const Instagram340 &other) {
    users = other.users;
    return *this;
}


