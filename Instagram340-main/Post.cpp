// TO DO: #include all the standard libraries and your own libraries here
#include <chrono>
#include "Post.h"
#include "User.h"

using namespace std;
// TO DO: function implementations
//constructors
Post::Post(){};
Post::Post(const std::string& title, const int& videoLength, const std::string& url):
        title(title), url(url), videoLength(videoLength), likes(0), timeStamp(std::chrono::steady_clock::now()){
}
//destructor
Post::~Post() {};
//copy constructor
Post::Post(const Post &other)
    :title(other.title), url(other.url), videoLength(other.videoLength), likes(0), timeStamp(std::chrono::steady_clock::now()){

}

// When creating a post, you may use this code to set time stamp
auto time_stamp = std::chrono::steady_clock::now();

// ------------------------------------------------------------------------------
// Operator overloading implementation
bool Post::operator==(const Post& otherPost) const {
    return Post::title == otherPost.title && timeStamp == otherPost.timeStamp && likes == otherPost.likes && url == otherPost.url;
}
//operator overloading <<
ostream& operator<<(ostream& os, const Post& post){
    return post.printPost(os);
}
//operator overloading >>
istream& operator>>(istream& is, Post& post){
    cout << "Enter title of your post: ";
    is >> post.title;
    cout << "Enter the time duration of your post: ";
    is >> post.videoLength;
    cout << "Enter the url of your post: ";
    is >> post.url;
    return is;
}

//print out edit message when user edits
void Post::editMsg() const {
    cout << "You have edited your Post." << endl;
}
//print post
ostream& Post::printPost(ostream& os) const {
    os << "Post \"" << title << "\" || " <<  videoLength << " seconds || " << likes << " likes || " << url << endl;
    return os;
}

//GETTERS
//const string &Post::getTitle() const {
//    return title;
//}
//
//int Post::getLikes() const {
//    return likes;
//}
//
//const string &Post::getUrl() const {
//    return url;
//}

int Post::getVideoLength() const {
    return videoLength;
}
const chrono::time_point<std::chrono::steady_clock> &Post::getTimeStamp() const {
    return timeStamp;
}


//SETTERS
void Post::setTitle(const string &title) {
    Post::title = title;
    cout << "You have changed your post title to \"" << title << "\"." << endl;
}
void Post::setVideoLength(const int &videoLength) {
    Post::videoLength = videoLength;
}






