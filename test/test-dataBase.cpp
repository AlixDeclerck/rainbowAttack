/**
 * Author: Dochot.be
 * Depot: Github ()
 * Encoding: UTF-8
 * Language: C++
 * Source(s):
 **/

#include <iostream>
#include <string>
#include "../resources/sha256.h"
#include "../resources/passwd-utils.hpp"
using namespace std;


/*name of file output*/
static string CLEAR_PATH = "_clear.test";
static string HASH_PATH = "_hash.test";


/**
 * Create two files with clear password and hash password
 * @param path_in : path to dataBase
 * @param path_out : path to output
 * @param number_to_test_mash : number to generate
 * @param number_to_test_noMatch : number to generate false password
 * @param sizePassword : size of password
 */
void createFile(const string& path_in, const string& path_out, int number_to_test_mash, int number_to_test_noMatch, int sizePassword)
{
    string line;
    int j,i = 0;
    ifstream inputFile(path_in);
    ofstream clearPwd(path_out + CLEAR_PATH);
    ofstream hashPwd(path_out + HASH_PATH);

    while (getline(inputFile, line) && i < number_to_test_mash)
    {
        j = ::rand();
        if (j%2 == 0)
        {
            clearPwd << line.substr(sizePassword + 1,2 * sizePassword + 1) << endl;
            hashPwd  << sha256( line.substr(sizePassword + 1,2 * sizePassword + 1) ) << endl;
            ++i;
        }
    }

    inputFile.close();
    clearPwd.close();
    hashPwd.close();
}


/**
 * Launch create test
 */
int main(int argc, char **argv)
{
    string dataBase = "/tmp/rainbow_table.db";
    string outPut = "/tmp/test_rainbow";
    int sizePwd = 10;
    int testNb = 100;
    int testFalse = 0;

    if (argc == 6)
    {
        dataBase  = argv[1];
        outPut    = argv[2];
        sizePwd   = ::strtol(argv[3], NULL, 10);
        testNb    = ::strtol(argv[4], NULL, 10);
        testFalse = ::strtol(argv[5], NULL, 10);;
    }

    cout << "Generate file to attack with dataBase" << endl;
    ::printf("dataBase->%s | path_output->%s | size_password->%i | number_to_test-> %i | number_to_false-> %i\n", dataBase.c_str(), outPut.c_str(), sizePwd, testNb, testFalse);

    createFile(dataBase, outPut, testNb,testFalse, sizePwd);

    return 1;
}