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
            LinkedBag<std::shared_ptr<Post>> posts;

        public:
            //constructor
            User();
            User(std::string username, std::string password, std::string email);
            User(std::string username, std::string email, std::string password, std::string bio, std::string profilePicture);
            //copy constructure
            User(const User& user);
            //destructor
            ~User();

            //print out profile of user
            void displayProfile() const;
            //print out all the posts by the user
            void displayAllPosts() const;
            //find and print specific post at k
            void displayKthPost(const int& k) const;
            // Operator = overloading function prototype:
            User& operator=(const User& otherUser);
            //remove a post at a certain index
            void removePost(const int& index);
            //modify a post at a certain index and change its title
            void modifyPost(const int& index, const std::string& newTitle);
            //operator << overloading
            friend std::ostream& operator<<(std::ostream &os, const User& user);
            //operator >> overloading
            friend std::istream& operator>>(std::istream &is, User& user);

            //getter
            const std::string &getUsername() const;
            LinkedBag<std::shared_ptr<Post>> &getPosts();

            //setter
            void setPassword(const std::string &password);

    };

#endif


