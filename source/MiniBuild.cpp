#include "../includes/graph.hpp"

int main(int argc, char* argv[]) {
    std::string filename(argv[1]);
    Graph g(filename);
    std::string promt;
    do {
        std::cout << "\nInput promt(help for commands)\n";
        getline(std::cin, promt);
        if(promt == "help") g.help();
        else if(promt == "list") g.list();
        else if(promt == "build order") g.buildorder();
        else if(promt == "check cycle") g.checkcycle();
        else if(promt == "build") {
            std::cout << "Name a modul\n";
            std::string arg;
            std::cin >> arg;
            g.build(arg);
        }
        else if(promt == "rebuild") {
            std::cout << "Name a modul\n";
            std::string arg;
            std::cin >> arg;
            g.rebuild(arg);
        }
    } while(promt != "exit");
    return 0;
}