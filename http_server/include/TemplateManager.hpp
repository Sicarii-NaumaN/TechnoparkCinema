#pragma once

#include <queue>
#include <string>
#include <fstream>
#include <streambuf>
#include <vector>
#include <map>
#include <set>

// работа с TemplateManager, создаем экземпляр, запрашиваем parameters/templates
// запрашиваем их у БД, после ответа передаем в GetHtml
typedef enum {
    FREE,
    TEMPLATE_FOUND,
    CYCLE_STARTED,
    END
} state_t;

class TemplateManager {
 public:
    explicit TemplateManager(const std::string &url);
    ~TemplateManager() = default;
    std::set<std::string> GetParameterNames();
    std::vector<char> GetHtmlFinal(const std::map<std::string, std::string> &parameters);
private:
    std::string HTML;
    std::string ID;
    std::set<std::string> html_parameters;

    void ExtractParameters();
    void InsertTemplates();

    void EvaluateCycles(const std::map<std::string, std::string> &parameters);
    void EvaluateParameters(const std::map<std::string, std::string> &parameters);
};
