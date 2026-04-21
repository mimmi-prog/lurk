#include <iostream>
#include "Searcher.h"

using namespace std;

int main(int argc, char* argv[]) {

    std::string query = argv[1];
    fileNameSearch f;

    f.search(query);

    // testSearch t;

    // std::string flag = argv[1];

    // if (flag == "-f") {
    //     f.search(query);
    // }
    // else if (flag == "-t") {
    //     t.search(query);
    // }
    // else {
    //     cout << "no argument provided" << endl;
    // };
    
    // if (argc < 2) {
    //     cerr << "no argument provided" << endl;
    //     return 1;
    // }
    // cout << argv[1] << endl;
    return 0;
}
