
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

//displays user profile info
void User::displayProfile() const{
    cout << "\n" << User::username << "\nEmail: " << User::email << "\nPassword: " << User::password << "\nBio: " << User::bio
    << "\nProfile Picture: " << User::profilePicture << endl;
}

//display all the posts of user
void User::displayAllPosts() const {
    int numOfPosts = posts.getCurrentSize();
    Node<unique_ptr<Post>> *temp = posts.getHeadPtr();

    if(numOfPosts == 0){
        cout << "You do not have any posts." << endl;
    }else{
        cout << "\nYou have a total of " << numOfPosts << " posts" << endl;
        cout << User::username << "'s Posts\n" << "--------------------------------------" << endl;
        while(temp != nullptr){
            temp->getItem()->printPost();
            temp = temp->getNext();
        }
    }
}
// display the post at kth index; else, return message to tell user the post they requested does not exist
void User::displayKthPost(const int& k) const{
    if(posts.getCurrentSize() > k){
        posts.findKthItem(k)->getItem()->printPost();
    } else{
        cout << "Your requested post does not exist." << endl;
    }
}

//remove post at the given index
void User::removePost(const int& index) {
// Find the post, then remove it from the list.
    unique_ptr<Post> post = posts.findKthItem(index)->getItem();
    posts.remove(post);
    cout << "Your post has been removed." << endl;
}

//modify post at given index -- title only
void User::modifyPost(const int& index, const string& newTitle){
    // Find the post, then update the title. Print out edit message
    unique_ptr<Post> item =  posts.findKthItem(index)->getItem();
    item->setTitle(newTitle);
}

// Operator == overloading implementation
bool User::operator==(const User& otherUser) const {
    return (User::username == otherUser.username) && (User::email == otherUser.email);
}

//getters
const string &User::getUsername() const {
    return username;
}

LinkedBag<unique_ptr<Post>> &User::getPosts() {
    return posts;
}

//setter
void User::setPassword(const string &password) {
    this->password = password;
}
















