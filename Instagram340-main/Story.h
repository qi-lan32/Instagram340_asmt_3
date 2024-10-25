#ifndef ASSIGNMENT2_CODE_STORY_H
#define ASSIGNMENT2_CODE_STORY_H

#include "Post.h"
#include <chrono>

class Story : public Post{
public:
    Story();
    Story(const std::string& title, const int& videoLength, const std::string url);
    //print out edit message
    void editMsg() const;
    //check story for appropriate length
    static bool compareDurationLimit(const int& storyLength);
    //display story
    void printPost() const override;

private:
    // This is a helper function -- it should be private.
    int computeTimeToExpiration() const;
    const static int durationLimit = 60;  // 60 second limit
    int timeTillExpiration;
};


#endif //ASSIGNMENT2_CODE_STORY_H
