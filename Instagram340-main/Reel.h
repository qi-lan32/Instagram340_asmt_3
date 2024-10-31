#ifndef ASSIGNMENT2_CODE_REEL_H
#define ASSIGNMENT2_CODE_REEL_H

#include "Post.h"

class Reel : public Post{
public:
    Reel();
    Reel(const std::string& title, const std::string& url, const int& videoLength);
    Reel(const Reel& other);
    ~Reel();
    //print out edit message
    void editMsg() const override;
    //comparing length of reel created
    static bool compareDurationLimit(const int& reelLength);
    //display reel
    std::ostream& printPost(std::ostream& os) const override;
    //operator << overloading function
    friend std::ostream& operator<<(std::ostream& os, const Reel& reel);
    //operator overloading >>
    friend std::istream& operator>>(std::istream& is, Reel& reel);
    //operator overloading =
    Reel& operator=(const Reel& other);

private:
    const static int durationLimit = 90;  //limit of up to 90 seconds
};


#endif //ASSIGNMENT2_CODE_REEL_H
