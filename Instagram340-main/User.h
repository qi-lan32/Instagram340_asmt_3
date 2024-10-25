#ifndef USER_H
#define USER_H
// TO DO: #include all the standard libraries and your own libraries here
    #include <iostream>
    #include <string>
    #include <memory>
    #include "LinkedBagDS/LinkedBag.h"
    #include "Post.h"

    // To DO: define the class User with the necessary functions and data fields
    class User{
        private:
            std::string username, email, password, bio, profilePicture;
            LinkedBag<std::unique_ptr<Post>> posts; // todo this stores ptrs to new post objs created
                    // suppose to create new reel/story objs in heap -- using new;

        public:
            //constructor
            User();
            User(std::string username, std::string password, std::string email);
            User(std::string username, std::string email, std::string password, std::string bio, std::string profilePicture);

            //print out profile of user
            void displayProfile() const;
            //print out all the posts by the user
            void displayAllPosts() const;
            //find and print specific post at k
            void displayKthPost(const int& k) const;
            // Operator == overloading function prototype:
            bool operator==(const User& otherUser) const;
            void removePost(const int& index);
            void modifyPost(const int& index, const std::string& newTitle);

            //getter
            const std::string &getUsername() const;

            LinkedBag<std::unique_ptr<Post>> &getPosts();


        //setter
            void setPassword(const std::string &password);

    };

#endif


