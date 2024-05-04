#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Elem {
    Elem* link;
    string info;
};

void push(Elem*& top, const string& value) {
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = top;
    top = tmp;
}

string pop(Elem*& top) {
    if (top == nullptr) {
        cerr << "Stack is empty" << endl;
        return "";
    }
    Elem* tmp = top->link;
    string value = top->info;
    delete top;
    top = tmp;
    return value;
}

void printStack(Elem* top) {
    Elem* current = top;
    while (current != nullptr) {
        cout << current->info << ' ';
        current = current->link;
    }
    cout << endl;
}

void readFileAndFilter(const char* fname, int wordLength, Elem*& originalStack, Elem*& filteredStack) {
    ifstream file(fname);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << fname << endl;
        return;
    }

    string word;
    while (file >> word) {
        // Remove punctuation
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        // Check if word length matches the required length
        if (word.length() == wordLength) {
            push(filteredStack, word);
        }
        push(originalStack, word);
    }

    file.close();
}

int main() {
    Elem* originalStack = nullptr;
    Elem* filteredStack = nullptr;

    int wordLength;
    cout << "Enter the length of the words you want to filter: ";
    cin >> wordLength;

    readFileAndFilter("input.txt", wordLength, originalStack, filteredStack);

    cout << "Original Stack: ";
    printStack(originalStack);

    cout << "Filtered Stack (words of length " << wordLength << "): ";
    printStack(filteredStack);

    // Cleanup
    while (originalStack != nullptr) {
        pop(originalStack);
    }
    while (filteredStack != nullptr) {
        pop(filteredStack);
    }

    return 0;
}
