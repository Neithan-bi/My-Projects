#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string originalFilename = "original.txt";
    std::string copyFilename = "copy.txt";

    if (originalFilename == copyFilename) {
        std::cerr << "Error: original and copy filenames must differ.\n";
        return 1;
    }

    std::ifstream inFile(originalFilename, std::ios::binary);
    if (!inFile) {
        std::cerr << "Error: Could not open the original file: " << originalFilename << std::endl;
        return 1;
    }

    std::ofstream outFile(copyFilename, std::ios::binary);
    if (!outFile) {
        std::cerr << "Error: Could not create the copy file: " << copyFilename << std::endl;
        inFile.close();
        return 1;
    }

    std::cout << "Copying content from " << originalFilename << " to " << copyFilename << "..." << std::endl;
    outFile << inFile.rdbuf();
    outFile.flush();

    if (inFile.fail() || outFile.fail()) {
        std::cerr << "Error occurred during file copy." << std::endl;
        inFile.close();
        outFile.close();
        return 1;
    }

    inFile.close();
    outFile.close();

    std::cout << "File copy successful." << std::endl;

    std::cout << "Truncating (deleting contents of) " << originalFilename << "..." << std::endl;
    std::ofstream truncFile(originalFilename, std::ios::out | std::ios::trunc | std::ios::binary);
    if (!truncFile) {
        std::cerr << "Error: Could not open original file for truncation." << std::endl;
        return 1;
    }
    truncFile.close();

    std::cout << "Operation complete. " << originalFilename << " is now empty." << std::endl;
    return 0;
}

