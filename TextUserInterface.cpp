//
// Created by alice on 11/07/20.
//

#include "TextUserInterface.h"
#include "functions.h"

void TextUserInterface::beginProgram() {
    std::string choice;
    std::cout << "\t\t\t\t\t WELCOME TO HAPPYCHAT!" << std::endl << std::endl;
    std::cout << "Press A to continue as '" << program->getCurrentUser()->getRealName() << "'." << std::endl
              << "Not you? Press B to change account." << std::endl << std::endl;
    std::cin >> choice;
    bool whatChoice = program->loginChoice(choice);
    if (whatChoice) {
        std::cout << "You chose to continue as " << program->getCurrentUser()->getRealName() << "." << std::endl;
        mainMenu();
    } else  {
        std::cout << "You chose to change account." << std::endl;
       login();
    }
}

void TextUserInterface::mainMenu() {
    std::cout << std::endl << "\t\t\t\t\t Hello, " << program->getCurrentUser()->getRealName() << "." << std::endl;
    std::cout << std::endl << "It's currently ";
    std::string currentTime = timeToString(program->getCurrentTime());
    std::cout << currentTime << "." << std::endl << std::endl;
    choices();
}

void TextUserInterface::choices() {
    int choice;
    std::cout << "What would you like to do next?" << std::endl;
    std::cout << "(1) See all chats." << std::endl << "(2) Open a chat." << std::endl << "(3) Log out." << std::endl
              << "(4) Change username." << std::endl;
    std::cout << "(5) Get unread chats." << std::endl << std::endl << "Insert choice below: " << std::endl;
    std::cin >> choice;
    cinFail();
    switch (choice) {
        case 1: {
            std::cout << "Your account contains the following chats: " << std::endl;
            //TODO high level function to print chats
            printChats(program->getCurrentUser());
            std::cout << "\t\t\t\t\t-----------------------------" << std::endl;
            choices();
        }
            break;
        case 2: {
            int chatNum;
           // program->getCurrentUser()->printAllChats();
            if (program->getCurrentUser()->noChats()) {
                std::cout << "Taking user back to main menu." << std::endl;
                choices();
                break;
            }
            std::cout << "Which chat would you like to open? Insert below:" << std::endl;
            std::cin >> chatNum;
            cinFail();
            program->getCurrentUser()->openchat(chatNum); //TODO function
            choices();
        }
            break;
        case 3: {
            std::cout << "Logging out..." << std::endl;
            std::cout << "See you next time." << std::endl;
        }
            break;
        case 4: {
            program->getCurrentUser()->changeUsername(); //TODO function to change username
            choices();
        }
            break;
        case 5: {
            std::cout << "Here are your chats with unread messages:" << std::endl;
           // program->getCurrentUser()->getUnreadChats();
            choices();
        }
            break;
        default: {
            std::cout << "No correct choice was made." << std::endl;
            choices();
        }
            break;

    }
}

void TextUserInterface::login() {
    std::string username;
    std::cout << "Enter your username: ";
    std::cin >> username;
    bool isUsername = program->isUsernameInList(username);
    if(isUsername) {
        std::cout << "Username found. Accessing main menu." << std::endl;
        mainMenu();
    } else {
        std::cout << "Username not found. Creating a new user." << std::endl;
        std::cout << "New user added. Accessing main menu." << std::endl;
        std::cout << "\t\t\t\t\t-----------------------------" << std::endl;
        mainMenu();
    }

}