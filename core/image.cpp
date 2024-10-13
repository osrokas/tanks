#include "image.h"
#include <string>

class Image{
    public:
        std::string img_path;
        void printPath(){
            std::cout << img_path << std::endl;
        }
}