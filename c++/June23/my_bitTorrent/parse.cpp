#include <fstream>
#include <iostream>
#include <memory>
#include "include/bencoding/bencoding.h"
#include "include/bencoding/PrettyPrinter.h"
#include "include/bencoding/Decoder.h"

void fileParser(std::string& filePath){
    std::ifstream fileStream(filePath, std::ifstream::binary);
    std::shared_ptr <bencoding::BItem> decodedTorrentFile = bencoding::decode(fileStream);
    std::shared_ptr<bencoding::BDictionary> rootDict =
            std::dynamic_pointer_cast<bencoding::BDictionary>(decodedTorrentFile);
    std::shared_ptr<bencoding::BDictionary> root = rootDict ;
        std::string prettyRepr = bencoding::getPrettyRepr(decodedTorrentFile);
        std::cout << prettyRepr << std::endl;
        return;
}

int main(){
    std::string filePath = "./files/sample.torrent";
    fileParser(filePath);
    return 1;
}