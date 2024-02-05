#include<iostream>
#include<string>

using namespace std;

int main() {
    string aspectRatio;
    int knownSide;
    char knownDimension;

    cout << "Enter the aspect ratio (e.g., 16:9): ";
    getline(cin, aspectRatio);

    cout << "Enter 'w' if you know the width or 'h' if you know the height: ";
    cin >> knownDimension;

    cout << "Enter the known side length: ";
    cin >> knownSide;

    size_t colonPos = aspectRatio.find(':');
    int widthRatio = stoi(aspectRatio.substr(0, colonPos));
    int heightRatio = stoi(aspectRatio.substr(colonPos + 1));

    int unknownSide;

    if (knownDimension == 'w' || knownDimension == 'W') {
        unknownSide = (knownSide * heightRatio) / widthRatio;
        cout << "The resolution is: " << knownSide << "x" << unknownSide << endl;
    }
    else if (knownDimension == 'h' || knownDimension == 'H') {
        unknownSide = (knownSide * widthRatio) / heightRatio;
        cout << "The resolution is: " << unknownSide << "x" << knownSide << endl;
    }
    else {
        cout << "Invalid input for dimension. Please enter 'w' for width or 'h' for height." << endl;
    }

    return 0;
}
