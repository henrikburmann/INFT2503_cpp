#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string words_to_sentence(string words[]);
string length_of_table_contents_and_table_lenght(string words[]);
void change_index_9_to_11_with_x(string &sentence_);
bool check_if_string_contains_phrase(string sentence_, string phrase_);
int count_number_of_phrase_occurences(string sentence);

int main() {
  string word1;
  string word2;
  string word3;

  cin >> word1;
  cin >> word2;
  cin >> word3;

  string words[3] = {word1, word2, word3};

  const string sentence = words_to_sentence(words);
  cout << sentence << endl;

  string lengths = length_of_table_contents_and_table_lenght(words);
  cout << lengths << endl;

  //d
  string sentence2 = sentence;
  cout << sentence2 << endl;

  //Bytter ut bokstav 10, 11 og 12 med x.
  change_index_9_to_11_with_x(sentence2);
  cout << sentence << endl;
  cout << sentence2 << endl;

  //f
  string sentence_start;
  if (sentence.length() > 4) {
    sentence_start = sentence.substr(0, 5);
  }
  cout << sentence << endl;
  cout << sentence_start << endl;

  if (check_if_string_contains_phrase(sentence, "hallo")) {
    cout << "Setningen inneholder hallo!" << endl;
  } else {
    cout << "Setningen inneholder ikke hallo..." << endl;
  }

  cout << "Antall forekomster er: " << count_number_of_phrase_occurences(sentence) << endl;
};

//b
string words_to_sentence(string words[]) {
  string sentence = words[0] + " " + words[1] + " " + words[2] + ".";
  return sentence;
}

//c - litt vel kronglete muligens
string length_of_table_contents_and_table_lenght(string words[]) {
  string lengths;
  lengths.append("Lengde av ord 1: ");
  lengths.append(to_string(words[0].length()));
  lengths.append("\n");

  lengths.append("Lengde av ord 2: ");
  lengths.append(to_string(words[1].length()));
  lengths.append("\n");

  lengths.append("Lengde av ord 3: ");
  lengths.append(to_string(words[2].length()));
  lengths.append("\n");
  lengths.append("Total lengde: ");
  int total_length = words_to_sentence(words).length();
  lengths.append(to_string(total_length));
  return lengths;
}

//e
void change_index_9_to_11_with_x(string &sentence_) {
  if (sentence_.length() > 12) {
    sentence_[9] = 'x';
    sentence_[10] = 'x';
    sentence_[11] = 'x';
  }
}

//g
bool check_if_string_contains_phrase(string sentence_, string phrase_) {
  if (sentence_.find(phrase_) != string::npos) {
    return true;
  } else {
    return false;
  }
}

//h
int count_number_of_phrase_occurences(string sentence) {
  int count = 0;
  for (size_t i = 0; i < sentence.length(); i++) {
    if (sentence[i] == 'e') {
      if (sentence[i + 1] == 'r') {
        count++;
      }
    }
  }
  return count;
}
