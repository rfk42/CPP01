#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <string>

// Lit tout le contenu d’un fichier
std::string readFile(const std::string& filename) {
    std::ifstream in(filename);
    assert(in && "Unable to open file for reading.");
    std::string content((std::istreambuf_iterator<char>(in)),
                         std::istreambuf_iterator<char>());
    in.close();
    return content;
}

// Écrit un contenu dans un fichier
void writeFile(const std::string& filename, const std::string& content) {
    std::ofstream out(filename);
    assert(out && "Unable to open file for writing.");
    out << content;
    out.close();
}

// Test normal : on remplace s1 par s2 et on compare au résultat attendu
void test(const std::string& input, const std::string& s1, const std::string& s2, const std::string& expected) {
    assert(!s1.empty() && "s1 must not be empty for valid tests.");

    const std::string filename = "test_input.txt";
    const std::string outputname = filename + ".replace";

    writeFile(filename, input);

    std::string command = "./replace " + filename + " \"" + s1 + "\" \"" + s2 + "\"";
    int result = std::system(command.c_str());
    assert(result == 0 && "Program exited with error.");

    std::string resultContent = readFile(outputname);
    assert(resultContent == expected && "Output content does not match expected.");

    std::cout << "Test passed." << std::endl;
}

// Test pour les cas qui doivent échouer
void testFailure(const std::string& command) {
    int result = std::system(command.c_str());
    assert(result != 0 && "Program should have failed.");
    std::cout << "Failure test passed." << std::endl;
}

int main() {
    std::cout << "Running valid tests..." << std::endl;

    // Tests valides
    test("bonjour apple et apple", "apple", "orange", "bonjour orange et orange\n");
    test("il n'y a pas ce mot ici", "test", "truc", "il n'y a pas ce mot ici\n");
    test("aaa aaa aaa", "aaa", "b", "b b b\n");
    test("abcabc", "abc", "", "\n"); // Remplacer par rien = suppression

    std::cout << "Running failure tests..." << std::endl;

    // Cas invalide : s1 vide
    testFailure("./replace test_input.txt \"\" \"x\"");

    // Cas invalide : trop peu d’arguments
    testFailure("./replace test_input.txt apple");

    // Cas invalide : fichier inexistant
    testFailure("./replace file_not_exist.txt a b");

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
