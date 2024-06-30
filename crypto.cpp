#include <iostream>
#include <cstring>
#include <string>

#define KEY 3

char *getPhrase()
{
    std::string phrase;
    std::cout << "Type any phrase to encrypt: ";
    std::getline(std::cin, phrase);
    char *phraseArr = new char[phrase.length() + 1];
    std::strcpy(phraseArr, phrase.c_str());
    return phraseArr;
}

void makeCrypto(char *phrase)
{
    size_t length = std::strlen(phrase);
    char *oldPhrase = new char[length + 1];
    std::strcpy(oldPhrase, phrase);

    for (size_t i = 0; i < length; ++i)
    {
        if(islower(phrase[i])){
            if(phrase[i] + KEY > 122) {
                int value = phrase[i] + KEY;
                int diff = value - 122;
                phrase[i] = 96 + diff;
            } else {
                phrase[i] = (phrase[i] % 122) + KEY;   
            }
        } else {
            if(phrase[i] + KEY > 90) {
                int value = phrase[i] + KEY;
                int diff = value - 90;
                phrase[i] = 64 + diff;
            } else {
                phrase[i] = (phrase[i] % 90) + KEY;   
            }
        }

    }
    std::cout << "Encrypted phrase: " << phrase << std::endl;
}

int main(void)
{
    char *phrase = getPhrase();
    makeCrypto(phrase);
    delete[] phrase;
    return 0;
}
