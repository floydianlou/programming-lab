#include <iostream>
#include "Program.h"


#pragma clang diagnostic push
#pragma ide diagnostic ignored "InfiniteRecursion"

int main() {
    try {
        // users
    auto alice = new User("Alice");
    auto luca = new User ("Luca");
    auto olivia = new User("Olivia");
    auto margherita = new User("Margherita");

    Program program(alice);


    auto chat1 = new Chat (*alice, *luca, "luca <3");
    auto chat2 = new Chat(*alice, *olivia, "mamma <3");
    auto chat3 = new Chat(*margherita, *olivia, "Mamma");
    auto chat4 = new Chat (*margherita, *alice, "Sorella");

    auto text1 = new Message("Alice", "Luca", "Ciao amore, sono quasi arrivata!");
    auto text2 = new Message("Luca", "Alice", "Amore, ti sto aspettando alla stazione");
    auto text3 = new Message("Olivia", "Alice", "Stai studiando?");
    auto text4 = new Message("Alice", "Olivia", "Sì, certo...");
    auto text5 = new Message ("Margherita", "Olivia", "Ho concluso il secondo capitolo.");
    auto text6 = new Message ("Olivia", "Margherita", "Quando cominci il terzo?");
    auto text7 = new Message ("Margherita", "Olivia", "Oggi mi riposo.");
    auto text8 = new Message ("Margherita", "Alice", "Vengo a prenderti a Santa Maria Novella.");
    auto text9 = new Message ("Alice", "Margherita", "Okay, grazie.");

    chat2->addMessage(*text3);
    chat2->addMessage(*text4);

    chat1->addMessage(*text1);
    chat1->addMessage(*text2);
    chat3->addMessage(*text5);
    chat3->addMessage(*text6);
    chat3->addMessage(*text7);
    chat4->addMessage(*text8);
    chat4->addMessage(*text9);

    alice->addChat(*chat1);
    luca->addChat(*chat1);
    olivia->addChat(*chat2);
    alice->addChat(*chat2);
    alice->addChat(*chat4);
    olivia->addChat(*chat3);
    margherita->addChat(*chat3);
    margherita->addChat(*chat4);

    program.addUser(luca);
    program.addUser(olivia);
    program.addUser(margherita);

    program.init(); }

    catch (std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
        std::cout << "Rebooting..." << std::endl;
        main();
    }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        std::cout << "Rebooting..." << std::endl;
        main();
    }

}
#pragma clang diagnostic pop
