#include <iostream>
#include <fstream>
#include <string>
using namespace std;


// This is the path for Act 2 (Good Path - Investigating the Hooded Figure)
void Act_two01() {
    cout << "\n-- Act 2 (Route One: Investigating the Hooded Figure) --\n";
    cout << "The team decides to track down the witness who saw the hooded figure.\n";
    cout << "They learn that the witness is hiding in the old market district, fearing for their life.\n";
    cout << "Claire: \"We need to convince them to talk...\"\n";

    // Continue the story for this path
    cout << "\nPress Enter to continue..." << endl;
    cin.ignore();
    cin.get();
    //readStoryFile("Act_two_01.txt");
}

// This is the path for Act 2 (Bad Path - Accepting Razor's Offer)
void Act_two02() {
    cout << "\n-- Act 2 (Route Two: Accepting Razor's Offer) --\n";
    cout << "The team agrees to protect Razor's gang in exchange for their help.\n";
    cout << "Razor: \"You keep my boys safe, and I’ll tell you everything you want to know.\"\n";
    cout << "But in Nebcity, alliances are as sharp as a knife’s edge...\n";


}


// This function reads and displays the content of a text file
void readStoryFile(const string& filename) {
    ifstream storyFile(filename);  // Opens the file
    string line;

    if (storyFile.is_open()) {
        // Reads and prints each line of the file
        while (getline(storyFile, line)) {
            cout << line << endl;
        }
        storyFile.close();
    } else {
        // Error message if file cannot be opened
        cout << "Error: Could not open story file: " << filename << endl;
    }
}

// This function handles the critical decision in Act 2
int Dialogue_Algorithm() {
    int Choice_one;

    cout << "\n=== Dialogue Choice ===\n";
    cout << "Claire: \"We have two leads... but we can't follow both. What should we do next?\"\n";
    cout << "1. Investigate the hooded figure. Find the witness and learn who the killer is.\n";
    cout << "2. Accept Razor’s offer. Protect his gang and get their help.\n";
    cout << "Choose an option (1 or 2): ";

    cin >> Choice_one;

    if (Choice_one == 1) {
        cout << "\nYou have chosen to investigate the hooded figure.\n";
        Act_two01();
    }
    else if (Choice_one == 2) {
        cout << "\nYou have chosen to accept Razor's offer.\n";
        //Act_two02();
    } 
    else {
        cout << "Invalid choice. Please choose 1 or 2.\n";
        return Dialogue_Algorithm(); // Re-runs the function for a valid choice
    }

    return Choice_one;

}




// This function contains the main story sequence
void Overallstory() {
    // Display Act 1
    cout << "-- Act 1 --" << endl;
    readStoryFile("Act_one.txt");  

    // Pause for player to continue
    cout << "\nPress Enter to continue..." << endl;
    cin.ignore();
    cin.get();

    // Display Act 2
    cout << "-- Act 2 --" << endl;
    readStoryFile("Act_two.txt");

    // Trigger the player's decision in Act 2
    Dialogue_Algorithm();
}


// Main function
int main() {
    
    
    string Response;

    // Game introduction
    cout << "-- C.A.T Investigations --" << endl;
    cout << "Are you ready to play? (Yes/No)'\n'";
    cout << "" << endl;
    cin >> Response;

    // Convert response to lowercase for better matching
    for (char &c : Response) {
        c = tolower(c);
    }

    // Decision based on player's response
    if (Response == "yes") {
        Overallstory();
    } 
    else if (Response == "no") {
        cout << "Till next time then...\n";
    } 
    else {
        cout << "Please enter a valid response (Yes/No)...\n";
        return 1;
    }

    return 0;
}
