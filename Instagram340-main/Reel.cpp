#include "Reel.h"


//CONSTRUCTORS
Reel::Reel(){}
Reel::Reel(const std::string& title, const std::string& url, const int& videoLength):
    Post(title, videoLength, url){
}
//copy constructor
Reel::Reel(const Reel &other)
    :Post(other){
}
//destructor
Reel::~Reel() {}

//METHODS
//print out edit message
void Reel::editMsg() const{
    cout << "You have added added a filter, AR effects, and music to the reel \"" << Reel::title << "\""
    << endl;
}

//determine if reel have appropriate time length
bool Reel::compareDurationLimit(const int& reelLength) {
    return reelLength <= durationLimit;
}

ostream& Reel::printPost(ostream& os) const {
    os << "Reel \"" << title << "\" || " <<  videoLength << " seconds || " << likes << " likes || " << url << endl;
    return os;
}

//operator overloading <<
std::ostream &operator<<(ostream &os, const Reel &reel) {
    return reel.printPost(os);
}

//operator overloading >>
std::istream &operator>>(istream &is, Reel &reel) {
    cout << "Enter the title of your reel: " << endl;
    cin >> reel.title;
    cout << "Provide the URL of your reel: " << endl;
    cin >> reel.url;
    cout << "Provide the length of your reel in seconds: " << endl;
    cin >> reel.videoLength;
    return is;
}

//operator overloading =
Reel& Reel::operator=(const Reel &other) {
    //call base class assignment
    Post::operator=(other);
    //assign inherited members
    title = other.title;
    url = other.url;
    videoLength = other.videoLength;
    return *this;
}



