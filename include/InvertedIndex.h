#ifndef INVERTEDINDEX_H
#define INVERTEDINDEX_H

#include <string>
#include <vector>
#include <unordered_map>
#include <mutex>

struct Entry {
    int doc_id;
    int count;

    bool operator==(const Entry& other) const {
        return (doc_id == other.doc_id) && (count == other.count);
    }
};

class InvertedIndex {
public:
    InvertedIndex();
    void updateDocumentBase(const std::vector<std::string>& input_docs);
    std::vector<Entry> getWordCount(const std::string& word);
    void updateDocument(const std::string& word, size_t doc_id);

private:
    std::unordered_map<std::string, std::vector<Entry>> freq_dictionary;
    std::mutex dictionary_mtx;
};

#endif // INVERTEDINDEX_H
