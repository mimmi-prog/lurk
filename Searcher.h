#include <string>
#include <iostream>
#include <filesystem>
#include <vector>

// ----------------- Klasser ----------------- //

class Searcher {
    public:
        Searcher();
        virtual void search(std::string& query) = 0;
        virtual ~Searcher();
    protected:
        std::string path = "./";
};

class fileNameSearch : public Searcher {
    public:
        fileNameSearch() : Searcher() {};
        void search(std::string& query) override;
};

class testSearch : public Searcher {
    public:
        testSearch() : Searcher() {};
        void search(std::string& query) override;
};

