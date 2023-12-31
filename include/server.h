#ifndef SEARCH_ENGINE_SERVER_H
#define SEARCH_ENGINE_SERVER_H

#include <cstdio>
#include <vector>
#include <map>
#include <mutex>

#include "InvertedIndex.h"

struct RelativeIndex {
    RelativeIndex(size_t doc_id, float rank) : _doc_id(doc_id), _rank(rank) {
    }

    size_t _doc_id;
    float _rank;

    bool operator == (const RelativeIndex& other) const {
        return (_doc_id == other._doc_id && _rank == other._rank);
    }
};

class SearchServer {
public:
    //
    SearchServer(InvertedIndex& idx) : _index(&idx) {};
    //
    std::vector<std::vector<RelativeIndex>> search(const std::vector<std::string>& queries_input, size_t max_responses = 5);
    std::map<std::string, size_t> get_indexes_for_request_words(std::vector<std::string>& vec);
    void handleRequest(const std::string& request, std::vector<RelativeIndex>&, size_t max_responses);
private:
    InvertedIndex* _index;
};

#endif //SEARCH_ENGINE_SERVER_H
