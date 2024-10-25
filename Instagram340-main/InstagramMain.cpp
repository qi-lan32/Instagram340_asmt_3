/*
 * TODO: Everything should work now
 */

#include <iostream>
#include <string>
#include <memory>

// TO DO: #include any other libraries you need
#include "Instagram340.h"
#include "Instagram340.cpp"
#include "User.h"
#include "User.cpp"
#include "Post.h"
#include "Post.cpp"
#include "Reel.h"
#include "Reel.cpp"
#include "Story.h"
#include "Story.cpp"

using namespace std;

/** 
 * 
 * Displays the application's main menu
 * pre create a new object of type User
 * @param user object to interact with
 * 
 * */
void displayUserManu(User& user){
	int userChoice = 0;
	do {
		cout << "\n Hi, "<< user.getUsername() <<", what would you like to do:\n"
		<< "1. Display Profile\n"
		<< "2. Modify Password\n"
		<< "3. Create Post\n"
		<< "4. Display All Posts\n"
		<< "5. Display Kth Post\n"
		<< "6. Modify Post\n"
		<< "7. Delete Post\n"
        << "8. Edit Post\n"
		<< "0. Logout\n"
		<< "Choice: ";
		cin >> userChoice;

		switch (userChoice) {
			case 1:{
				// TO DO: display user's profile information
				user.displayProfile();
				break;
			}
			case 2: {
				// TO DO: ask for new password and update user's password
                string newPassword;
                cout << "Enter the new password: " << endl;
                cin >> newPassword;
                user.setPassword(newPassword);
				break;
			}
			case 3: {
				// TO DO: ask user to choose between Reel and Story, ask them to input post details:
				//        (title, media URL, video length in seconds)
				//        Your program should set the time stamp to current time (code provided in Post.cpp) 
				// then create the post and add it to the user's posts
                int choice = 0;
                string title, url;
                int videoLength;

                cout << "Would you like to make a reel or story? (Enter 1 for reel, 2 for story)" << endl;
                cin >> choice;

                //make a reel (1) or story (2) according to user's choice
                if(choice == 1){
                    cout << "Enter the title of your reel: " << endl;
                    cin >> title;
                    cout << "Provide the URL of your reel: " << endl;
                    cin >> url;
                    cout << "Provide the length of your reel in seconds: " << endl;
                    cin >> videoLength;

                    //if the length of reel is longer than its duration limit, continue to ask for an appropriate length
                    while(!Reel::compareDurationLimit(videoLength)){
                        cout << "Your reel is over 90 seconds! Please keep your reel under the limit." << endl;
                        cout << "Provide the length of your reel in seconds: " << endl;
                        cin >> videoLength;
                    } //check reel length

//                    Reel* newReel = new Reel(title, url, videoLength); //create new reel using given info
                    user.getPosts().append(make_unique<Reel>(title, url, videoLength));

                }else if(choice == 2){
                    cout << "Enter the title of your story: " << endl;
                    cin >> title;
                    cout << "Provide the URL of your story: " << endl;
                    cin >> url;
                    cout << "Provide the length of your story in seconds: " << endl;
                    cin >> videoLength;

                    //check whether the length of story is under limit, if not, keep prompting user for appropriate time
                    while(!Story::compareDurationLimit(videoLength)){
                        cout << "Your story is over 60 seconds! Please keep your story under the limit." << endl;
                        cout << "Provide the length of your story in seconds: " << endl;
                        cin >> videoLength;
                    } //check story length

//                    Story* newStory = new Story(title, videoLength, url);    //create new story object
                    user.getPosts().append(make_unique<Story>(title, videoLength, url));

                }else{
                    cout << "Invalid choice!" << endl;
                }

				break;
			}
			case 4:{
				// TO DO: display all user's posts
				//        You may re-use code from class demo
                user.displayAllPosts();
				break;
			}
			case 5: {
                int k;
                //ask the user for a value k
                cout << "Enter a value for the 'k': " << endl;
                cin >> k;
                // Find the Kth post, if k > Linked Bag size,
                //    return an error message that includes the size of the Linked Bag
                user.displayKthPost(k);

				break;
			}
			case 6: {
                //TO DO: ask user for index of post they want to modify and the new title
                int index;
                string newTitle;
                LinkedBag<unique_ptr<Post>>& posts = user.getPosts();
				//ask user for input on index and title
                cout << "What is the index of the post you would like to modify? Enter: " << endl;
                cin >> index;

                // If index > Linked Bag size, print out error message
                if(index > posts.getCurrentSize()){
                    cout << "Your index is out of range! The number of total posts you have is " << posts.getCurrentSize() << endl;
                }else{
                    cout << "Enter the new title you would like to change to: " << endl;
                    cin >> newTitle;

                    user.modifyPost(index, newTitle);
                }

				break;
			}
			case 7: {
				// TO DO: ask the user for the index of the post they want to delete and delete it
                int index;
                LinkedBag<unique_ptr<Post>>& posts = user.getPosts();
                //ask user for input on index
                cout << "What is the index of the post you would like to delete? Enter: " << endl;
                cin >> index;

                // If index > LinkedBag size, return error message
                if(index > posts.getCurrentSize()){
                    cout << "Your index is out of range! The number of total posts you have is " << posts.getCurrentSize() << endl;
                }else{
                    user.removePost(index);
                }
				break;
			}
            case 8: {
                //TO DO: ask the user for the index of the post they want to edit, depending on the type of post they edited, print an edit message
                int index;
                cout << "What is the index of the post you would like to edit? Enter: " << endl;
                cin >> index;

                if(index > user.getPosts().getCurrentSize()){
                    cout << "This post does not exist.\n" << endl;
                }else{
                    //find the post and print out corresponding edit message
                    user.getPosts().findKthItem(index)->getItem()->editMsg();
                }
                break;
            }
			case 0: {
				cout << "Logging you out." << endl;
				break;
			}
			default:
				cout << "Invalid choice. Please try again." << endl;
		}

	} while (userChoice != 0);
}


int main(){
	// Instantiating the program using the default constructor
	// With this implementation, the application will only have one user
	Instagram340 instagram;
    string username, email, password, bio, profilePic;

	cout << "\n Welcome to Instagram340:" << endl;
	// TO DO: Ask the user to enter their information to instantiate a new user object

    cout << "Please enter your username: " << endl;
    cin >> username;
    cout << "Please enter your email: " << endl;
    cin >> email;
    cout << "Please enter your password: " << endl;
    cin >> password;
    cout << "Please enter your bio: " << endl;
    cin >> bio;
    cout << "Please enter your profile picture: " << endl;
    cin >> profilePic;

	// call instagram createUser function
	// replace /*...*/ with the right parameters
	instagram.createUser(username,email, password, bio, profilePic);

//	 Retrieve the user
	unique_ptr<User> currentUser = instagram.getUser(0);

    currentUser->displayProfile();
	displayUserManu(*currentUser);
				
	return 0;
}