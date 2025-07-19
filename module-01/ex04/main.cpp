#include <fstream>
#include <iostream>
#include <string>

// result.replace(pos, target.length(), replacement) but .replace is a forbidden
// function
std::string replaceInLine(const std::string &line, const std::string &target,
                          const std::string &replacement) {
  std::string result = line;
  std::size_t pos = 0;

  while ((pos = result.find(target, pos)) != std::string::npos) {
    result.erase(pos, target.length());
    result.insert(pos, replacement);
    pos += replacement.length();
  }
  return result;
}

bool isFileValid(const std::string &filename, std::ifstream &file) {
  if (!file.good()) {
    std::cout << "Error: Cannot open file " << filename << std::endl;
    return false;
  }
  if (file.peek() == std::ifstream::traits_type::eof()) {
    std::cout << "Error: Empty file" << std::endl;
    return false;
  }
  return true;
}

void processFile(const std::string &filename, const std::string &target,
                 const std::string &replacement) {
  std::ifstream inputFile(filename);

  if (!isFileValid(filename, inputFile)) {
    return;
  }
  std::string outputFileName = filename + ".replace";
  std::ofstream outputFile(outputFileName);

  if (!outputFile) {
    std::cout << "Error: Cannot create output file" << std::endl;
    return;
  }

  std::string line;
  while (std::getline(inputFile, line)) {
    std::string processedLine = replaceInLine(line, target, replacement);
    outputFile << processedLine << std::endl;
  }
  inputFile.close();
  outputFile.close();
  std::cout << "Replacement complete. Output savd to: " << outputFileName
            << std::endl;
}

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cout << "Error: Usage: ./replace <filename> <target> <replacement>"
              << std::endl;
    std::cout << "Note: <target> will be replaced with <replacement>"
              << std::endl;
    return 1;
  }

  std::string filename(argv[1]);
  std::string target(argv[2]);
  std::string replacement(argv[3]);

  processFile(filename, target, replacement);
  return (0);
}