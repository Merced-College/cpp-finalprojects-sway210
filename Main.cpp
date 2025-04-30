#include <iostream>
using namespace std;

// Displays the introduction and world setup
void introScene() {
    cout << "C.A.T. Investigations has recently opened its office in the heart of Nebcity.\n";
    cout << "The team—Claire, Tom, and Apser—have been tackling strange and dangerous cases.\n";
    cout << "From haunted alleyways to twisted human crimes, they’ve seen it all.\n";
    cout << "But nothing has prepared them for what’s coming next...\n\n";
}

// Introduces the first major case
void firstCase() {
    cout << "=== CASE FILE #001: THE JOKER'S CALLING CARD ===\n";
    cout << "Location: Central Park, East Gate\n";
    cout << "Victim: Unidentified Male\n";
    cout << "Condition: No external injuries. No blood. No struggle.\n";
    cout << "Clue: A Joker playing card, neatly placed in the victim’s mouth.\n\n";

    // Character dialogue
    cout << "Claire: \"This isn't just a murder... this is a message.\"\n";
    cout << "Tom:    \"This feels like District 12 all over again. Same signature.\"\n";
    cout << "Apser:  \"If it’s the same guy, we don’t have much time. We need to move.\"\n\n";
}

int main() {
    // Game Title
    cout << "====== C.A.T. Investigations ======\n";
    cout << "A Text-Based Mystery/Detective Game\n";
    cout << "===================================\n\n";

    // Start the story
    introScene();
    firstCase();

    // Placeholder for future content
    cout << "To be continued...\n";
    return 0;
}
