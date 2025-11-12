#include "../includes/graph.hpp"

int main(int argc, char* argv[]) {
    std::string filename(argv[1]);
    if(argc != 1) {
        std::cerr << "wrong number of arguments" << std::endl;
        return 1;
    }
    Graph g(filename);
    std::string promt;
    do {
        std::cout << "Input promt(help for commands)\n";
        std::cin >> promt;
        if(promt == "help") g.help();
        else if(promt == "list") g.list();
        else if(promt == "build order") g.buildorder();
        else if(promt == "check cycle") g.checkcycle();
        else if(promt == "build") {
            std::string arg;
            std::cin >> arg;
            g.build(arg);
        }
        else if(promt == "rebuild") {
            std::string arg;
            std::cin >> arg;
            g.rebuild(arg);
        }
    } while(promt != "exit");
    return 0;
}