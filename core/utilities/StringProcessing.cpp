#include "StringProcessing.h"

bool StringProcessing::isNumeric(const std::string &s)
{
    for (int i = 0; i < s.size(); i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

std::vector<string> StringProcessing::filter(const std::vector<string> &lines, const string &substring)
{
    std::vector<string> res;
    for (const auto &line : lines) {
        if (line.find(substring) != std::string::npos) {
            res.push_back(line);
        }
    }
    return res;
}

std::vector<std::string> StringProcessing::split(const std::string &s, const std::string &delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}