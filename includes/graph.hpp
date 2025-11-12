#ifndef GRAPHHPP
#define GRAPHHPP
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <unordered_map>

class Graph{
private:
    std::unordered_map<std::string, int> nameToId;
    std::vector<std::string> idToName;
    std::vector<std::vector<int>> adj;
    std::vector<int> sort;
    size_t size;
    bool hasCycle;
public:
    Graph(const std::string& filename);
    void list();
    void help();
    void buildorder();
    void checkcycle();
    void build(const std::string& modul);
    void rebuild(const std::string& modul);
};

#endif