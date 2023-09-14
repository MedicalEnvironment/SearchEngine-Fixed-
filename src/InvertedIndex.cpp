#include "../include/InvertedIndex.h"
#include <sstream>

void InvertedIndex::updateDocumentBase(const std::vector<std::string>& input_docs) {
    // Iterate through the input documents
    for (size_t doc_id = 0; doc_id < input_docs.size(); ++doc_id) {
        const std::string& doc = input_docs[doc_id];

        // Tokenize the document (split it into words)
        std::istringstream iss(doc);
        std::string word;

        while (iss >> word) {
            // Update the word count in the frequency dictionary
            {
                std::lock_guard<std::mutex> lock(_dictionary_mtx);
                freq_dictionary[word][doc_id]++;
            }
        }
    }
}

std::vector<Entry> InvertedIndex::getWordCount(const std::string& word) {
    std::vector<Entry> result;

    // Search for the word in the frequency dictionary
    {
        std::lock_guard<std::mutex> lock(_dictionary_mtx);
        auto it = freq_dictionary.find(word);

        if (it != freq_dictionary.end()) {
            for (const auto& entry : it->second) {
                result.emplace_back(entry.first, entry.second);
            }
        }
    }

    return result;
}

void InvertedIndex::updateDocument(const std::string& word, size_t doc_id) {
    // Update the word count in the frequency dictionary
    {
        std::lock_guard<std::mutex> lock(_dictionary_mtx);
        freq_dictionary[word][doc_id]++;
    }
}
