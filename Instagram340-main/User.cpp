
// TO DO: #include needed standard libraries and your own libraries here
#include "User.h"
#include <string>
#include "LinkedBagDS/LinkedBag.h"
#include "Post.h"

using namespace std;

// TO DO: function implementations
//constructor
User::User(){}
User::User(std::string username, std::string password, std::string email)
    :username(username), password(password), email(email){
}
User::User(std::string username, std::string email, std::string password, std::string bio, std::string profilePicture):
        username(username), email(email), password(password), bio(bio), profilePicture(profilePicture), posts(){
}
//copy constructor
User::User(const User& user)
    :username(user.username), password(user.password), email(user.email), bio(user.bio), profilePicture(user.profilePicture){

}
//destructor
User::~User() {
    User::posts.clear();
}

//displays user profile info
void User::displayProfile() const{
    cout << "\n" << User::username << "\nEmail: " << User::email << "\nPassword: " << User::password << "\nBio: " << User::bio
    << "\nProfile Picture: " << User::profilePicture << endl;
}

//display all the posts of user
void User::displayAllPosts() const {
    int numOfPosts = posts.getCurrentSize();
    vector<shared_ptr<Post>> postVector = posts.toVector();

    if(numOfPosts == 0){
        cout << "You do not have any posts." << endl;
    }else{
        cout << "\nYou have a total of " << numOfPosts << " posts" << endl;
        cout << User::username << "'s Posts\n" << "--------------------------------------" << endl;
        for(int i = 0; i < numOfPosts; i++){
            cout << *postVector[i];
        }
    }
}
// display the post at kth index; else, return message to tell user the post they requested does not exist
void User::displayKthPost(const int& k) const{
    if(posts.getCurrentSize() > k){
        cout << *posts.findKthItem(k)->getItem();
    } else{
        cout << "Your requested post does not exist." << endl;
    }
}

//remove post at the given index
void User::removePost(const int& index) {
// Find the post, then remove it from the list.
    shared_ptr<Post> post = posts.findKthItem(index)->getItem();
    posts.remove(posts.findKthItem(index)->getItem());
    cout << "Your post has been removed." << endl;
}

//modify post at given index -- title only
void User::modifyPost(const int& index, const string& newTitle){
    // Find the post, then update the title. Print out edit message
    shared_ptr<Post> item =  posts.findKthItem(index)->getItem();
    item->setTitle(newTitle);
}

// Operator = overloading implementation
User& User::operator=(const User& otherUser) {
    username = otherUser.username;
    email = otherUser.email;
    password = otherUser.password;
    bio = otherUser.bio;
    profilePicture = otherUser.profilePicture;
    return *this;
}
//operator << overloading
ostream& operator<<(ostream &os, const User& user){
    os << "\n" << user.username;
    os << "\nEmail: " << user.email;
    os << "\nPassword: " << user.password;
    os << "\nBio: " << user.bio;
    os << "\nProfile Picture: " << user.profilePicture << "\n" << endl;
    return os;
}
//operator >> overloading
istream &operator>>(istream &is, User &user) {
    cout << "Please enter your username: " << endl;
    is >> user.username;
    cout << "Please enter your email: " << endl;
    is >> user.email;
    cout << "Please enter your password: " << endl;
    is >> user.password;
    cout << "Please enter your bio: " << endl;
    is >> user.bio;
    cout << "Please enter your profile picture: " << endl;
    is >> user.profilePicture;
    return is;
}

//getters
const string &User::getUsername() const {
    return username;
}

LinkedBag<std::shared_ptr<Post>> &User::getPosts(){
    return posts;
}

//setter
void User::setPassword(const string &password) {
    this->password = password;
}



















