//Jose Arellano
//5/13/25
//Final project

#include <iostream>
#include <cstdlib> //For Rand(), combat algorthm
#include <ctime> //for time()
#include <fstream> // For reading story files
#include <string> // For handling text (story and dialogue)
#include <vector> // For storing future cases
#include <limits> // For numeric_limits
using namespace std;

// Global variable for alignment score
int alignmentScore = 0;
string ignore;

// Function to display possible future cases
void FutureCases() {
    vector<string> cases = {
        "The Neon Butcher: A serial killer leaves messages written in neon paint.",
        "The Phantom Courier: Illegal shipments vanish without a trace in Dockside.",
        "The Viper’s Nest: An underground fight club becomes a front for human trafficking.",
        "The Whispering Shadows: A string of disappearances tied to an old cult.",
        "The Vanished Heiress: A wealthy socialite vanishes, leaving only a bloody glove."
    };

    cout << "\n--- Future Cases to Investigate ---\n";
    for (int i = 0; i < cases.size(); i++) {
        cout << i + 1 << ". " << cases[i] << endl;
    }

    int choice;
    cout << "\nChoose a case to preview (1-" << cases.size() << "): ";
    cin >> choice;

    if (choice >= 1 && choice <= cases.size()) {
        cout << "\n--- Case Preview ---\n";
        cout << cases[choice - 1] << endl;
        cout << "A chilling mystery awaits you...\n";
    } 
    else {
        cout << "\nInvalid choice. Please choose a valid case number.\n";
        FutureCases(); // Restart the choice if invalid
    }
}


//comabt alogrthm
void CombatSystem() {
    // Setting up player and enemy stats
    int playerHP = 100;
    int enemyHP = 100;
    int playerDamage = 15;
    int enemyDamage = 12;

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    cout << "\n--- Combat Begins! ---\n";
    cout << "You are facing Elias, the vengeful killer.\n";

    // Combat loop
    while (playerHP > 0 && enemyHP > 0) {
        // Player's turn
        int choice;
        cout << "\nYour HP: " << playerHP << " | Elias's HP: " << enemyHP << endl;
        cout << "1. Attack\n";
        cout << "2. Defend\n";
        cout << "Choose an action: ";
        cin >> choice;

        if (choice == 1) {
            // Player attacks
            cout << "You strike Elias for " << playerDamage << " damage!\n";
            enemyHP -= playerDamage;
        } else if (choice == 2) {
            // Player defends (reduces damage)
            cout << "You brace yourself, reducing incoming damage.\n";
        } else {
            cout << "Invalid choice. You waste your turn.\n";
        }

        // Check if the enemy is defeated
        if (enemyHP <= 0) {
            cout << "\nYou have defeated Elias!\n";
            break;
        }

        // Enemy's turn (random choice)
        int enemyAction = rand() % 2 + 1;
        if (enemyAction == 1) {
            // Enemy attacks
            if (choice == 2) {
                cout << "Elias attacks, but your defense reduces the damage!\n";
                playerHP -= (enemyDamage / 2);
            } else {
                cout << "Elias strikes you for " << enemyDamage << " damage!\n";
                playerHP -= enemyDamage;
            }
        } else {
            // Enemy defends (no action)
            cout << "Elias prepares himself, watching you carefully.\n";
        }

        // Check if the player is defeated
        if (playerHP <= 0) {
            cout << "\nElias has defeated you...\n";
            break;
        }
    }

    // End of combat
    if (playerHP > 0) {
        cout << "\nYou have survived the fight!\n";
    } else {
        cout << "\nYou have fallen...\n";
    }
}

// Function to show the player's final alignment
//morality algorthm
//will show at the epilogue portion of the game
void ShowFinalAlignment() {
    cout << "\n=== Final Moral Alignment ===\n";
    if (alignmentScore > 0) {
        cout << "You are a Compassionate Detective.\n";
        cout << "You chose empathy and understanding over violence.\n";
    } 
    else if (alignmentScore < 0) {
        cout << "You are a Ruthless Hunter.\n";
        cout << "You believed that justice requires strength and sacrifice.\n";
    } 
    else {
        cout << "You are a Grey Investigator.\n";
        cout << "You walked the line between justice and vengeance.\n";
    }
}



// Function to read and display the content of a text file
void readStoryFile(const string& filename) {
    ifstream storyFile(filename);
    string line;

    if (storyFile.is_open()) {
        while (getline(storyFile, line)) {
            if (line == "<<PAUSE>>") {
                cout << "\n-- Press Enter to continue --\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
            } else {
                cout << line << endl;
            }
        }
        storyFile.close();
    } else {
        cout << "Error: Could not open story file: " << filename << endl;
    }
}





//Epilogue function
void Epilogue() {
    readStoryFile("Epilogue.txt");
    ShowFinalAlignment();
    
    
}


void Act_Three03(){

    readStoryFile("Act_Three03.txt");
    readStoryFile("Epilogue.txt");
    ShowFinalAlignment();
    FutureCases();

}

void Act_threetwo() {
    alignmentScore -= 1;
    cout << "\n--- Act 3: Confronting Elias - Fight ---\n";
    readStoryFile("Act_threetwo.txt");
        readStoryFile("Epilogue.txt");
        ShowFinalAlignment();
        FutureCases();

}

// Function for Act 3 - Path 1 (Convince Elias to Surrender)
void Act_three01() {
    alignmentScore += 1;

    readStoryFile("Act_three01.txt");
    getline(cin, ignore);
    readStoryFile("Epilogue.txt");
    getline(cin, ignore);
    ShowFinalAlignment();
    FutureCases();

}

// Function for Act 3 - Path 2 (Fight Elias)
void Act_three04() {
    alignmentScore -= 1;
    cout << "\n--- Act 3: Confronting Elias - Fight ---\n";
    readStoryFile("Act_three04.txt");
    CombatSystem();
    Epilogue();
    ShowFinalAlignment();
    FutureCases();
}

// This is the path for Act 2 (Good Path - Investigating the Hooded Figure)
void Act_two01() {
    cout << "\n-- Act 2 (Route One: Investigating the Hooded Figure) --\n";
    cout << "The team decides to track down the witness who saw the hooded figure.\n";
    cout << "They learn that the witness is hiding in the old market district, fearing for their life.\n";
    cout << "Claire: \"We need to convince them to talk...\"\n";
    
    // Display Act 2 Scene
    cout << "\nPress Enter to continue..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    readStoryFile("Act_two01.txt");

    // Dialogue choice for Act 3
    int Choice_2;
    cout << "\n=== Dialogue Choice ===\n";
    cout << "Elias stands before you, his grief twisting into anger.\n";
    cout << "1. Try to convince Elias to surrender peacefully.\n";
    cout << "2. Prepare for a fight — he’s too far gone.\n";
    cout << "Choose an option (1 or 2): ";
    cin >> Choice_2;

    if (Choice_2 == 1) {
        alignmentScore += 1; // Compassionate choice
        cout << "\nYou have chosen to try to convince Elias to surrender.\n";
        Act_three01(); // Peaceful Ending
       
    }
    else if (Choice_2 == 2) {
        alignmentScore -= 1;
        cout << "\nYou have chosen to prepare for a fight.\n";
        Act_three04(); // Fight Ending

    }
    else {
        cout << "Invalid choice. Please choose 1 or 2.\n";
        Act_two01(); // Restart the choice if invalid
    }
}

// This is the path for Act 2 (Bad Path - Accepting Razor's Offer)
void Act_two02() {
    cout << "\n-- Act 2 (Route Two: Accepting Razor's Offer) --\n";
    readStoryFile("Act_two02.txt");
    
    // Here you can add a dialogue choice for Razor's route (Act 3)
    cout << "\n=== Moral Choice ===\n";
    cout << "Elias fights with desperate fury. Razor’s men fall back.\n";
    cout << "1. Fight with Razor. Help him kill Elias.\n";
    cout << "2. Turn against Razor. Help Elias destroy the gang.\n";
    cout << "Choose an option (1 or 2): ";;
    
    int Choice_3;
    cin >> Choice_3;

    if (Choice_3 == 1) {
        cout << "\nYou have chosen to fight with Razor.\n";
        Act_threetwo();
      
    } 
    else if (Choice_3 == 2) {
        cout << "\nTurn against razor and help Elias.\n";
        Act_Three03(); 
         
    }
    else {
        cout << "Invalid choice. Please choose 1 or 2.\n";
        Act_two02(); // Restart the choice if invalid
    }
}

// This function handles the critical decision in Act 2
void Act2Choice() {
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
        Act_two02();
    } 
    else {
        cout << "Invalid choice. Please choose 1 or 2.\n";
        Act2Choice(); // Re-runs the function for a valid choice
    }
}

// This function contains the main story sequence
void Overallstory() {
    // Display Act 1
    cout << "-- Act 1 --" << endl;
    readStoryFile("Act_one.txt");  

    // Pause for player to continue
    cout << "\nPress Enter to continue..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Trigger the player's decision in Act 2
    Act2Choice();
}

// Main function
int main() {
    string Response;

    // Game introduction
    cout << "-- C.A.T Investigations --" << endl;
    cout << "Are you ready to play? (Yes/No)\n";
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
