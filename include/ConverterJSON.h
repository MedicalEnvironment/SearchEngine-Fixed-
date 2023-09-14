#ifndef SEARCH_ENGINE_CONVERTERJSON_H
#define SEARCH_ENGINE_CONVERTERJSON_H

#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include "server.h"

class ConverterJSON {
    std::string _config_path;
    std::string _request_path;
    std::string _answers_path;

    std::string _name;
    std::string _version;
    int _max_responses;
    std::vector<std::string> _file_names;
public:
    ConverterJSON(const std::string& config_path = "config.json",
                  std::string request_path = "request.json",
                  std::string answers_path = "answers.json"
                          );

    //////////////
    std::vector<std::string> getTextDocuments();

    //////////////
    int getResponsesLimit();

    //////////////
    std::vector<std::string> getRequests();

    //////////////
    void putAnswers(const std::vector<std::vector<RelativeIndex>>& answers);

    const std::string &getName() const;

    const std::string &getVersion() const;
};

#endif //SEARCH_ENGINE_CONVERTERJSON_H
