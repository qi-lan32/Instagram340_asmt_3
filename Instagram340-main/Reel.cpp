#include "Reel.h"


//CONSTRUCTORS
Reel::Reel(){}
Reel::Reel(const std::string& title, const std::string& url, const int& videoLength):
    Post(title, videoLength, url){
}

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

void Reel::printPost() const {
    cout << "Reel \"" << title << "\" || " <<  videoLength << " seconds || " << likes << " likes || " << url << endl;
}

