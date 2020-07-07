#include <iostream>
#include <string>
#include <BookConstructor.hpp>

/**
 * Declaration of main function.
 *
 * @file main.cpp
 */

/**
 * main
 *
 * Interface to use the BookRecustruction Class
 * WARNING: this is lightweight and do not perform checks for file existence, good formatting
 * of inputs ecc..
 *
 * @param[in] argc An integer argument count of the command line arguments
 * @param[in] argv An argument vector of the command line arguments:
 * @param[in] path to the unzipped ITCH raw data binary file
 * @param[in] path to the directory to which the output book csv file will be written to (add trailing backslash!)
 * @param[in] path to the directory to which the output message csv file will be written to (add trailing backslash!)
 * @param[in] integer this is the depth of the orderbook, for bid and ask side
 * @param[in] name string of the stock you want the reconstruct the book
 *
 */

int main(int argc, char * argv[]){

    if(argc<6){
        std::cerr << "The program should be called with: ./BookConstructor path_input_file dir_book dir_messages levels stock" << std::endl;
        return 1;
    }

    std::string pathFile = argv[1];                   // input file
    std::string outBookDirectory = argv[2];           // book output folder
    std::string outMessageDirectory = argv[3];        // message output folder
    size_t levels = std::stoul(argv[4]);              // level
    std::string stock = argv[5];                      // stock ticker
    std::string market = argv[6];                     // market abbreviation
    std::string date = argv[7];                       // date string
//    std::string nameFile = getFileName(pathFile);
    std::string outBookFileName = outBookDirectory+date+"_"+stock+"_"+market+"_book_"+std::to_string(levels)+".csv";
    std::string outMessageFileName = outMessageDirectory+date+"_"+stock+"_"+market+"_message.csv";
    std::string stockPadded = stock;
    stockPadded.insert(stockPadded.end(), 8 - stockPadded.size(), ' ');

    BookConstructor BookConstructor(pathFile,
        outMessageFileName,
        outBookFileName,
        stockPadded,
        levels);

    BookConstructor.start();

    return 0;
}
