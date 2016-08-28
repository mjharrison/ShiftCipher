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

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string>

enum MODE
{
    NONE,
    ENCRYPT,
    DECRYPT,
    EXIT
};

void        Clean_Input_Stream();
bool        Check_File(std::ifstream& file, std::string path);
bool        Check_File(std::ofstream& file, std::string path);
void        Display_Message(MODE user_selection);
void        Display_Information();
std::string Get_Input_Path();
std::string Get_Output_Path(std::string input_path);
MODE        Get_Selection();
int         Get_Shift();

#endif