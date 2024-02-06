#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>

using namespace std;

int main() {
    string aspectRatio;
    int knownSide;
    char knownDimension;

    cout << "Enter the aspect ratio (e.g., 16:9): ";
    getline(cin, aspectRatio);

    size_t colonPos = aspectRatio.find(':');
    if (colonPos == string::npos || colonPos == 0 || colonPos == aspectRatio.length() - 1) {
        cout << "Invalid aspect ratio format. Please use the format W:H." << endl;
        cin.get();
        return 1;
    }

    int widthRatio, heightRatio;
    try {
        widthRatio = stoi(aspectRatio.substr(0, colonPos));
        heightRatio = stoi(aspectRatio.substr(colonPos + 1));
    }
    catch (const std::exception& e) {
        cout << "Invalid aspect ratio values. Please make sure to use integers." << endl;
        cin.get();
        return 1;
    }

    if (widthRatio <= 0 || heightRatio <= 0) {
        cout << "Aspect ratio values must be positive." << endl;
        cin.get();
        return 1;
    }

    cout << "Enter 'w' if you know the width or 'h' if you know the height: ";
    cin >> knownDimension;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (knownDimension != 'w' && knownDimension != 'W' && knownDimension != 'h' && knownDimension != 'H') {
        cout << "Invalid input for dimension. Please enter 'w' for width or 'h' for height." << endl;
        cin.get();
        return 1;
    }

    cout << "Enter the known side length: ";
    if (!(cin >> knownSide) || knownSide <= 0) {
        cout << "Invalid input. Known side length must be a positive integer." << endl;
        cin.get();
        return 1;
    }

    int unknownSide;

    if (knownDimension == 'w' || knownDimension == 'W') {
        unknownSide = (knownSide * heightRatio) / widthRatio;
        cout << "The resolution is: " << knownSide << "x" << unknownSide << endl;
    }
    else {
        unknownSide = (knownSide * widthRatio) / heightRatio;
        cout << "The resolution is: " << unknownSide << "x" << knownSide << endl;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(); 

    return 0;
}
