/*
 * Author:          Matthew James Harrison
 * Class:           CSI-140-01
 * Assignment:      Final Project: Cipher
 * Date Assigned:   30/11/15
 * Due Date:        11/12/15 at 5:00pm
 *
 * Description:
 *    A program which uses a shift (AKA Caesar) cipher to create encrypted or
 *    decrypted copies of text files.
 *
 * Certification of Authenticity:
 *    I certify that this is entirely my own work, except where I have given
 *    fully - documented references to the work of others. I understand the
 *    definition and consequences of plagiarism and acknowledge that the assessor
 *    of this assignment may, for the purpose of assessing this assignment:
 *      -   Reproduce this assignment and provide a copy to another member of
 *          academic staff; and/or
 *      -   Communicate a copy of this assignment to a plagiarism checking
 *          service (which may then retain a copy of this assignment on its
 *          database for the purpose of future plagiarism checking)
 */

#include "header.h"

/* Purpose:  Clean the input stream
 * Pre:      None
 * Post:     Input stream is cleaned
 *********************************************************/
void Clean_Input_Stream()
{
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

/* Purpose:  Check that an ifstream file can be found and opened
 * Pre:      File must be loaded
 * Post:     Returns true if file can be found and opened, or else returns false
 *********************************************************/
bool Check_File(std::ifstream& file, std::string path)
{
    if (!file)
    {
        std::cout << "\n  Error: File not found.\n";

        return false;
    }
    else if (file.fail())
    {
        std::cout << "\n  Error: Could not open file.\n";

        return false;
    }
    else
    {
        std::cout << "  Using path: " << path << "\n\n";

        return true;
    }
}

/* Purpose:  Check that an ofstream file can be found and opened
 * Pre:      File must be loaded
 * Post:     Returns true if file can be found and opened, or else returns false
 *********************************************************/
bool Check_File(std::ofstream& file, std::string path)
{
    if (!file)
    {
        std::cout << "\n  Error: File not found.\n";

        return false;
    }
    else if (file.fail())
    {
        std::cout << "\n  Error: Could not open file.\n";

        return false;
    }
    else
    {
        std::cout << "  Using path: " << path << "\n\n";

        return true;
    }
}

/* Purpose:  Inform the user that their task is complete
 * Pre:      User must have made a selection and the task should be complete
 * Post:     Messsage noting completed task is printed to the console
 *********************************************************/
void Display_Message(MODE user_selection)
{
    switch (user_selection)
    {
        case ENCRYPT:
            std::cout << "Encryption complete.\n\n";
            return;
        case DECRYPT:
            std::cout << "Decryption complete.\n\n";
            return;
        case EXIT:
            std::cout << "\nPress return to exit.\n\n";
    }
}

/* Purpose:  Describe the program and display initial instructions
 * Pre:      None
 * Post:     Description and instructions are displayed in the console
 *********************************************************/
void Display_Information()
{
    std::cout << "SHIFT CIPHER\n\n"
              << "This program encrypts and decrypts text files via a shift\n"
              << "cipher. Shift ciphers, also called Caesar ciphers, work by\n"
              << "shifting each letter in a secret message along the alphabet\n"
              << "by a certain amount.\n\n";
}

/* Purpose:  Get the path for an input file from the user
 * Pre:      None
 * Post:     Returns a string containing the file path
 *********************************************************/
std::string Get_Input_Path()
{
    std::string path;

    std::cout << "Enter the input file path (include extension):  ";

    std::cin >> path;

    return path;
}

/* Purpose:  Get the path for an output file from the user
 * Pre:      None
 * Post:     Returns a string containing the file path
 *********************************************************/
std::string Get_Output_Path(std::string input_path)
{
    std::string path;

    std::cout << "Enter the output file path (include extension):  ";

    for (;;)
    {
        std::cin >> path;

        if (!(path == input_path))
        {
            return path;
        }
        std::cout << "\nError: File paths must be different."
                  << "\nPlease try again:  ";
    }
}

/* Purpose:  Display menu options and get the user's choice
 * Pre:      None
 * Post:     Returns the user's choice
 *********************************************************/
MODE Get_Selection()
{
    char user_input;

    /* display instructions */
    std::cout << "Please choose one of the following modes:\n"
              << "  [A/a]. Encryption\n"
              << "  [B/b]. Decryption\n"
              << "  [C/c]. Exit\n"
              << "\nEnter the letter of your selection:  ";

    /* repeat until valid input is received */
    for (;;)
    {
        std::cin >> user_input;
        Clean_Input_Stream();

        switch (user_input)
        {
        case 'A':
        case 'a':
            std::cout << "  Encryption Mode selected.\n\n";
            return ENCRYPT;
        case 'B':
        case 'b':
            std::cout << "  Decryption Mode selected.\n\n";
            return DECRYPT;
        case 'C':
        case 'c':
            return EXIT;
        default:
            std::cout << "Invalid entry. Please try again:  ";
        }
    }
}

/* Purpose:  Get the shift amount from the user
 * Pre:      None
 * Post:     Returns an int containing the shift amount
 *********************************************************/
int Get_Shift()
{
    int shift = 0;

    do
    {
        std::cout << "Enter the shift amount (e.g. 3):  ";

        std::cin >> shift;

        Clean_Input_Stream();
    }
    while (shift == 0);

    std::cout << "  Using shift amount: " << shift << "\n"
              << "  Write this down so you can decrypt later!\n\n";

    return shift;
}