
#include "Story.h"
#include "Post.h"

using namespace std;

//VARIABLES
int durationLimit = 60; //in seconds

//CONSTRUCTORS
Story::Story(){};
Story::Story(const std::string& title, const int& videoLength, const std::string url)
    :Post(title, videoLength, url){}
//copy constructor
Story::Story(const Story &other)
    :Post(other){}
//destructor
Story::~Story(){}

//METHODS
// When displaying a story, use this to compute expected expiration time: timeToExpiration
int Story::computeTimeToExpiration() const{
    const int secondsInHour = 3600;
    // 24 hours in seconds
    const int expiresAfter = 24 * secondsInHour;

    // Get current time
    auto time_now = std::chrono::steady_clock::now();
    // Compute elapsed time since post creation
    std::chrono::duration<double> elapsed_seconds = time_now - time_stamp;
    // time to expiration in hours
    int timeToExpiration = (expiresAfter - elapsed_seconds.count()) / secondsInHour;

    return timeToExpiration;
}

//print out edit message
void Story::editMsg() const {
    cout << "A filter, music, stickers and effects have been added to the Story \"" << Story::title <<"\""
    << endl;
}

//check if story is appropriate length
bool Story::compareDurationLimit(const int& reelLength) {
    return reelLength <= durationLimit;
}

ostream& Story::printPost(ostream& os) const {
    os << "Story \"" << title << "\" || " <<  videoLength << " seconds || " << likes << " likes || " << computeTimeToExpiration() << " hours till expiration || " << url << endl;
    return os;
}

//operator overloading <<
std::ostream &operator<<(ostream& os, const Story& story) {
    return story.printPost(os);
}
//operator overloading >>
std::istream &operator>>(istream &is, Story &story) {
    cout << "Enter the title of your story: " << endl;
    cin >> story.title;
    cout << "Provide the URL of your story: " << endl;
    cin >> story.url;
    cout << "Provide the length of your story in seconds: " << endl;
    cin >> story.videoLength;
    return is;
}

//operator overloading =
Story& Story::operator=(const Story& other){
    //call base class assignment
    Post::operator=(other);
    //assign inherited members
    title = other.title;
    url = other.title;
    videoLength = other.videoLength;
    return *this;
}


