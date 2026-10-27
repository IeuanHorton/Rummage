#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    try {
        fs::path current = fs::current_path();

        std::cout << "Directory: " << current << "\n\n";

        for (const auto& entry : fs::directory_iterator(current)) {
            if (entry.is_directory()) {
                std::cout << "[DIR]  ";
            } else {
                std::cout << "[FILE] ";
            }

            std::cout << entry.path().filename().string()
                      << '\n';
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: "
                  << e.what() << '\n';
        return 1;
    }

    return 0;
}
