#ifndef ASSIGNMENT2_CODE_STORY_H
#define ASSIGNMENT2_CODE_STORY_H

#include "Post.h"
#include <chrono>

class Story : public Post{
public:
    Story();
    Story(const std::string& title, const int& videoLength, const std::string url);
    Story(const Story& other);
    ~Story();
    //print out edit message
    void editMsg() const;
    //check story for appropriate length
    static bool compareDurationLimit(const int& storyLength);
    //display story
    std::ostream& printPost(std::ostream& os) const override;
    //operator overloading <<
    friend std::ostream& operator<<(std::ostream& os, const Story& story);
    //operator overloading >>
    friend std::istream& operator>>(std::istream& is, Story& story);
    //operator overloading =
    Story& operator=(const Story& other);

private:
    // This is a helper function -- it should be private.
    int computeTimeToExpiration() const;
    const static int durationLimit = 60;  // 60 second limit
};


#endif //ASSIGNMENT2_CODE_STORY_H
