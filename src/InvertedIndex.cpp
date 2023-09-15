#include "../include/InvertedIndex.h"
#include <sstream>

InvertedIndex::InvertedIndex() {
    // Initialize freq_dictionary or perform any necessary setup here.
}

void InvertedIndex::updateDocumentBase(const std::vector<std::string>& input_docs) {
    std::lock_guard<std::mutex> lock(dictionary_mtx);

    // Implement the logic to update freq_dictionary based on input_docs.
    for (size_t doc_id = 0; doc_id < input_docs.size(); ++doc_id) {
        const std::string& doc = input_docs[doc_id];
        std::istringstream iss(doc);
        std::string word;

        while (iss >> word) {
            updateDocument(word, doc_id);
        }
    }
}

std::vector<Entry> InvertedIndex::getWordCount(const std::string& word) {
    std::lock_guard<std::mutex> lock(dictionary_mtx);
    if (freq_dictionary.find(word) != freq_dictionary.end()) {
        return freq_dictionary[word];
    }

    return {}; // Return an empty vector if the word is not found.
}

void InvertedIndex::updateDocument(const std::string& word, size_t doc_id) {
    std::lock_guard<std::mutex> lock(dictionary_mtx);

    // Implement the logic to update the word count for a specific document in freq_dictionary.
    if (freq_dictionary.find(word) == freq_dictionary.end()) {
        freq_dictionary[word] = {{static_cast<int>(doc_id), 1}};
    } else {
        bool updated = false;
        for (auto& entry : freq_dictionary[word]) {
            if (entry.doc_id == doc_id) {
                entry.count++;
                updated = true;
                break;
            }
        }
        if (!updated) {
            freq_dictionary[word].push_back({static_cast<int>(doc_id), 1});
        }
    }
}
