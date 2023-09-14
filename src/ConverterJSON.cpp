#include "../include/ConverterJSON.h"

ConverterJSON::ConverterJSON(const std::string& config_path, std::string request_path, std::string answers_path)
        : _config_path(config_path), _request_path(request_path), _answers_path(answers_path) {
    // Implement the constructor
}

std::vector<std::string> ConverterJSON::getTextDocuments() {
    // Implement getTextDocuments
}

int ConverterJSON::getResponsesLimit() {
    // Implement getResponsesLimit
}

std::vector<std::string> ConverterJSON::getRequests() {
    // Implement getRequests
}

void ConverterJSON::putAnswers(const std::vector<std::vector<RelativeIndex>>& answers) {
    // Implement putAnswers
}

const std::string& ConverterJSON::getName() const {
    // Implement getName
}

const std::string& ConverterJSON::getVersion() const {
    // Implement getVersion
}
