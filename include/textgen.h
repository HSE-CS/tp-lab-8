#pragma once
#include <string>
#include <unordered_map>

using WordMap =
    std::unordered_map<std::string, std::unordered_map<std::string, size_t>>;

struct MarkovMap {
  WordMap map;
  size_t prefixSize;
};

MarkovMap generateWordMap(const std::string& source, size_t prefixSize);
std::string markov(MarkovMap& map, size_t maxWords);
