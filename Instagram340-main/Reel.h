#ifndef ASSIGNMENT2_CODE_REEL_H
#define ASSIGNMENT2_CODE_REEL_H

#include "Post.h"

class Reel : public Post{
public:
    Reel();
    Reel(const std::string& title, const std::string& url, const int& videoLength);
    //print out edit message
    void editMsg() const;
    //comparing length of reel created
    static bool compareDurationLimit(const int& reelLength);
    //display reel
    void printPost() const override;

private:
    const static int durationLimit = 90;  //limit of up to 90 seconds
};


#endif //ASSIGNMENT2_CODE_REEL_H
