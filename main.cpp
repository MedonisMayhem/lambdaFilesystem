#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
auto recursiveGetFileNamesByExtension =
[](fs::path path, const std::string extension)
{
    for (auto& p : fs::recursive_directory_iterator(path))
    {
        if (p.is_regular_file() && !p.path().extension().compare("." + extension))
        {
            std::cout << p.path().stem() << "\n";
        }
    }
};
auto main() -> int {
    fs::path p("D:\\images");
    
    recursiveGetFileNamesByExtension(p, "jpg");
}
