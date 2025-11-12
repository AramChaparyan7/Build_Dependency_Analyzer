#ifndef GRAPHCPP
#define GRAPHCPP
#include "../includes/graph.hpp"

Graph::Graph(const std::string& filename) {
    std::ifstream inp(filename);
    if(!inp.is_open()) {
        std::cerr << "No such file" << std::endl;
        return;
    }
    std::string line;
    int count = 0;
    while(getline(inp, line)) {
        std::stringstream ss(line);
        std::string str;
        getline(ss, str, ':');
        if(!nameToId.contains(str)) {
            nameToId.insert({str, count});
            idToName.push_back(str);
            adj.push_back({});
        }
        std::string connect;
        while(ss >> connect) {
            if(!nameToId.contains(connect)) {
                nameToId[connect] = ++count;
                idToName.push_back(connect);
                adj.push_back({});
            }
            adj[nameToId[str]].push_back(nameToId[connect]);
        }
    }
    size = count;

    std::vector<int> indg(nameToId.size());
    std::queue<int> q;
    for(const auto& it : adj) {
        for(const auto& i : it) {
            ++indg[i];
        }
    }
    for(int i = 0; i < indg.size(); ++i) {
        if(indg[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        sort.push_back(v);
        for(int u = 0; u < adj[v].size(); ++u) {
            --indg[adj[v][u]];
            if(indg[adj[v][u]] == 0) q.push(adj[v][u]);
        }
    }
    if(sort.size() != indg.size()) {
        hasCycle = true;
        std::cout << "Cycle detected\n";
    }
    else hasCycle = false;
}

void Graph::list() {
    for(const auto& it : nameToId) {
        std::cout << it.first << std::endl;
    }
}

void Graph::help() {
    std::cout << "Commands\n" << "help\n" << "list\n" << "build(modul)\n" << "rebuild(modul)\n" << "build order\n" << "check cycle\n" << "exit"; 
}

void Graph::buildorder() {
    for(int i : sort) {
        std::cout << idToName[i] << std::endl;
    }
}

void Graph::checkcycle() {
    if(hasCycle) std::cout << "Cycle detected\n";
    else std::cout << "Cycles not detected\n";
}

void Graph::build(const std::string& modul) {
    if(!nameToId.contains(modul)) {
        std::cout << "No such modul\n";
        return;
    } 
    for(int i : sort) {
        std::cout << idToName[i] << std::endl;
        if(idToName[i] == modul) break; 
    }
}

void Graph::rebuild(const std::string& modul) {
    if(!nameToId.contains(modul)) {
        std::cout << "No such modul\n";
        return;
    } 
    if(find(sort.begin(), sort.end(), nameToId[modul]) == sort.end()) {
        std::cout << "Cycle detected\n";
        return;
    }
    for(int i : sort) {
        std::cout << idToName[i] << std::endl;
        if(idToName[i] == modul) break; 
    }
}


#endif