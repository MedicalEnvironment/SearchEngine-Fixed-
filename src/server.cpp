#include "../include/server.h"

std::vector<std::vector<RelativeIndex>> SearchServer::search(const std::vector<std::string>& queries_input, size_t max_responses) {
    std::vector<std::vector<RelativeIndex>> results;

    // Iterate over the queries
    for (const std::string& query : queries_input) {
        // Get relative indices for the query
        std::vector<RelativeIndex> relative_indices;
        handleRequest(query, relative_indices, max_responses);

        // Add relative indices to results
        results.push_back(relative_indices);
    }

    return results;
}

std::map<std::string, size_t> SearchServer::get_indexes_for_request_words(std::vector<std::string>& vec) {
    std::map<std::string, size_t> word_indexes;

    // Populate word_indexes with indices of words in vec
    for (size_t i = 0; i < vec.size(); ++i) {
        word_indexes[vec[i]] = i;
    }

    return word_indexes;
}

void SearchServer::handleRequest(const std::string& request, std::vector<RelativeIndex>& relative_indices, size_t max_responses) {
    // Assuming you have a logic to calculate doc_id and rank
    size_t doc_id = request.length();
    float rank = 1.0;

    // Create a RelativeIndex instance and add it to the vector
    RelativeIndex relative_index(doc_id, rank);
    relative_indices.push_back(relative_index);

    // You can add more RelativeIndex instances as needed
}
