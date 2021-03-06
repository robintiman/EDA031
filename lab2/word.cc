#include "word.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Word::Word(const string &w, const vector<string> &t) {
  word = w;
  trigrams = t;
}

string Word::get_word() const { return word; }

unsigned int Word::get_matches(const vector<string> &t) const {
  int matches = 0;
  size_t param_count = 0, local_count = 0;
  while (param_count != t.size() && local_count != trigrams.size()) {
    string local_t = trigrams.at(local_count);
    string param_t = t.at(param_count);
    if (local_t == param_t) {
      ++matches;
      ++local_count;
      ++param_count;
    } else if (local_t > param_t) {
      ++param_count;
    } else {
      ++local_count;
    }
  }
  return matches;
}
