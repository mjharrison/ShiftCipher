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
#include <fstream>

int main()
{
    std::ifstream input_file;
    std::ofstream output_file;

    std::string   input_path,
                  output_path;

    bool          file_valid;

    int           shift = 0;

    MODE user_selection = NONE;

    Display_Information();

    do
    {
        user_selection = Get_Selection();

        if (user_selection == ENCRYPT || user_selection == DECRYPT)
        {
            shift = Get_Shift(); /* negatives are allowed */

            /* open the input file */
            do
            {
                file_valid = false;

                input_path = Get_Input_Path();
                input_file.open(input_path.c_str(), std::ios::in);

                file_valid = Check_File(input_file, input_path);

            }
            while (file_valid == false);

            /* open the output file */
            do
            {
                file_valid = false;

                output_path = Get_Output_Path(input_path);
                output_file.open(output_path.c_str(), std::ios::out);

                file_valid = Check_File(output_file, output_path);
            }
            while (file_valid == false);

            /* read input and write encrypted copy to output */
            if (user_selection == ENCRYPT)
            {
                char character;

                /* encrypt a copy of the file */
                while (!input_file.eof())
                {
                    input_file >> std::noskipws >> character;

                    character = character + shift;

                    output_file << character;
                }
            }
            /* read input and write decrypted copy to output */
            else if (user_selection == DECRYPT)
            {
                char character;

                /* decrypt a copy of the file */
                while (!input_file.eof())
                {
                    input_file >> std::noskipws >> character;

                    character = character - shift;

                    output_file << character;
                }
            }
            /* close both files before looping back to initial menu */
            input_file.close();
            output_file.close();
        }
        Display_Message(user_selection);
    }
    while (user_selection != EXIT);

    std::cin.get();

    return 0;
}