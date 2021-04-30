#include "textgen.h"

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <sstream>
#include <string>
#include <unordered_map>

static size_t RAND_SEED = std::time(nullptr);

MarkovMap generateWordMap(const std::string& source, size_t prefixSize) {
  std::deque<std::string> prefixes;
  WordMap map;
  // copy because working with strings in c++ is a nightmare
  std::istringstream tokens(source);

  // Mapping
  for (std::string word; tokens >> word;) {
    if (prefixes.size() < prefixSize) {
      prefixes.push_back(word);
    } else {
      std::string prefix;
      for (const std::string& p : prefixes) {
        prefix.append(p);
        prefix.append(" ");
      }
      prefix.pop_back();
      prefixes.pop_front();

      if (map.find(prefix) == map.end()) {
        map[prefix] = std::unordered_map<std::string, size_t>();
      }
      if (map[prefix].find(word) == map[prefix].end()) {
        map[prefix][word] = 0;
      }
      map[prefix][word] += 1;
      map[prefix][""] += 1;  // sum

      prefixes.push_back(word);
    }
  }

  return {map, prefixSize};
}

std::string markov(MarkovMap& map_, size_t maxWords) {
  WordMap map = map_.map;

  // Generating text
  srand(RAND_SEED);
  std::string out;
  std::string currentPrefix;
  // Selecting random first prefix
  size_t randWordN = rand() % map.size();
  for (const auto& kv : map) {
    if (randWordN == 0) {
      currentPrefix = kv.first;
      break;
    } else {
      randWordN -= 1;
    }
  }
  out.append(currentPrefix);
  for (size_t i = 0; i < maxWords - map_.prefixSize; ++i) {
    size_t sum = 0;

    // If specified prefix does not exists
    if (map.find(currentPrefix) == map.end()) {
      size_t newPrefixN = rand() % map.size();
      for (const auto& kv : map) {
        if (newPrefixN == 0) {
          currentPrefix = kv.first;
        } else {
          newPrefixN -= 1;
        }
      }
    }

    // Selecting suffix based on probability
    size_t cutoff = rand() % map[currentPrefix][""];
    for (const auto& kv : map[currentPrefix]) {
      if (kv.first == "") {
        continue;
      }
      if (sum <= cutoff && sum + kv.second >= cutoff) {
        std::istringstream stream(currentPrefix);
        std::string tmp;
        stream >> tmp;
        currentPrefix.clear();
        while (stream >> tmp) {
          currentPrefix.append(tmp);
          currentPrefix.append(" ");
        }
        currentPrefix.append(kv.first);
        out.append(" ");
        out.append(kv.first);
        break;
      } else {
        sum += kv.second;
      }
    }
  }

  return out;
}