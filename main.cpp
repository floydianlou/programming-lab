#include <iostream>
#include "ProgramManager.h"
#include "functions.h"
#include "TextUserInterface.h"


#pragma clang diagnostic push
#pragma ide diagnostic ignored "InfiniteRecursion"

int main() {

    try {
        auto alice = new User("Alice");
        auto luca = new User("Luca");
        auto olivia = new User("Olivia");
        auto margherita = new User("Margherita");

        ProgramManager program(alice);
        program.addUser(luca);
        program.addUser(olivia);
        program.addUser(margherita);

        auto chat1 = new Chat(*alice, *luca, "luca <3");
        auto chat2 = new Chat(*alice, *olivia, "mamma <3");
        auto chat3 = new Chat(*margherita, *olivia, "Mamma");
        auto chat4 = new Chat(*margherita, *alice, "Sorella");


        auto text1 = new Message("Alice", "Luca", "Ciao amore, sono quasi arrivata!", 0);
        auto text2 = new Message("Luca", "Alice", "Amore, ti sto aspettando alla stazione", 1);
        auto text3 = new Message("Olivia", "Alice", "Stai studiando?", 2);
        auto text4 = new Message("Alice", "Olivia", "Sì, certo...", 3);
        auto text5 = new Message("Margherita", "Olivia", "Ho concluso il secondo capitolo.", 4);
        auto text6 = new Message("Olivia", "Margherita", "Quando cominci il terzo?", 5);
        auto text7 = new Message("Margherita", "Olivia", "Oggi mi riposo.", 6);
        auto text10 = new Message ("Alice", "Margherita", "Sto arrivando a Firenze.", 7);
        auto text8 = new Message("Margherita", "Alice", "Vengo a prenderti a Santa Maria Novella.", 8);
        auto text9 = new Message("Alice", "Margherita", "Okay, grazie.", 9);

        chat1->addMessage(*text1);
        chat1->addMessage(*text2);
        chat3->addMessage(*text5);
        chat3->addMessage(*text6);
        chat3->addMessage(*text7);
        chat4->addMessage(*text10);
        chat4->addMessage(*text8);
        chat4->addMessage(*text9);
        chat2->addMessage(*text3);
        chat2->addMessage(*text4);

        alice->addChat(*chat1);
        luca->addChat(*chat1);
        olivia->addChat(*chat2);
        alice->addChat(*chat2);
        alice->addChat(*chat4);
        olivia->addChat(*chat3);
        margherita->addChat(*chat3);
        margherita->addChat(*chat4);


        TextUserInterface interface(&program);
        interface.beginProgram();
    } catch (std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
        std::cout << "Rebooting..." << std::endl;
        main();
    }
    catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        std::cout << "Rebooting..." << std::endl;
        main();
    }

}

#pragma clang diagnostic pop
