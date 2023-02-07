/**
 * Ceasar cipher takes a given letter and changes the letter by moving the
 * letter a key value amount.
 */
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>

using std::cin;
using std::cout;
using std::endl;

// axilliary function for creating key value
int randomize() {
  srand(time(0));
  return rand() % 26; // range of 0 to 25, 26 non-inclusive
}

// c: user inputted letter
char cipher(char c) {
  int temp = randomize();
  // cout << "whats in randomize: " << temp <<endl;
  char alpha[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                  'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                  'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; // 26 LETTERS
  if (c != alpha[temp])
    return alpha[(c + temp) % 26];
  else
    return cipher(c);
}

int main(int argc, char *argv[]) {

  char ch1;
  cout << "please only insert ONE capital letter" << endl;
  cin >> ch1;
  char code = cipher(ch1);
  cout << "given: " << ch1 << ", encrypted: " << code << " key: " << code - ch1;
}
