#include "Searcher.h"
#include <iostream>
#include <filesystem>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

namespace fs = std::filesystem;


Searcher::Searcher() {};
Searcher::~Searcher() = default;


vector<string> generateTrigrams(const std::string& s) {
    vector<string> vec;
    vec.reserve(s.size() - 2);
    for (int i = 0; i < s.size() - 2; i++) {
        vec.push_back(s.substr(i, 3));
    }
    return vec;
}

void makeLowerCase(std::string& s) {
    for (auto& x : s) {
        x = tolower(x);
    }
}

void fileNameSearch::search(std::string& query) {
    if (query.size() < 3) return;

    makeLowerCase(query);

    vector<string> queryTrigrams = generateTrigrams(query);

    multimap<double, string, greater<double>> matchingFiles;

    for (const auto& entry : fs::recursive_directory_iterator(path)) {
        if (!entry.is_regular_file()) continue;
        string filename = entry.path().filename().string();
        makeLowerCase(filename);

        vector<string> filenameVec = generateTrigrams(filename);
        unordered_set<string> filenameTrigrams(filenameVec.begin(), filenameVec.end());

        int antallMatch = 0;
        for (const string& trigram : queryTrigrams) {
            if (filenameTrigrams.count(trigram)) {
                antallMatch++;
            }
        }

        double score = (double)antallMatch/queryTrigrams.size();


        if (score >= 0.6) {
            if (entry.path().parent_path() == ".") {
                score += 0.5;
            }
            matchingFiles.insert({score, entry.path().lexically_relative("./").string()});
        }
    }
    for (const auto& files : matchingFiles) {
        cout << files.second << endl;
    }
}

void testSearch::search(std::string& query) {
    cout << "testSearch" << endl;
}