#include "testCpp.h"
#include <vector>
#include <memory>

void testCppMain()
{
    testSharedPtr();
}


//使用智能指针
void testSharedPtr()
{
    std::unique_ptr<int> ptr1(new int(10)); // 使用new创建
    auto ptr2 = std::make_unique<int>(20);  // 使用make_unique创建（推荐）
    std::cout << " ptr1:" << *ptr1 << " ptr2:" << *ptr2 << std::endl;
//    std::unique_ptr<int> ptr3 = ptr1;
//    std::shared_ptr<int> ptr4 = ptr1;
//    ptr1 = std::make_unique<int>(20);
//    int x = 1;
//    int* y = &x;
//    ptr1 = y;
    std::shared_ptr<int> ptr5 = std::make_shared<int>(55);
    std::shared_ptr<int> ptr6 = ptr5;
    std::shared_ptr<int> ptr7 = ptr6;
    std::cout << " ptr5:" << *ptr5 << " ptr6:" << *ptr6
              << " ptr7:" << *ptr7 << std::endl;
}

//学习这种新的写法，需要手动new [nums]的地方都可以替换vector
//读取文件，vector管理内存
int readFileVtr()
{
    std::ifstream file("example.txt", std::ios::binary | std::ios::ate);
    if (!file) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<unsigned char> fileData(fileSize);
    if (!file.read(reinterpret_cast<char*>(fileData.data()), fileSize)) {
        std::cerr << "Failed to read file." << std::endl;
        return 1;
    }

    // 使用 fileData 的逻辑

    return 0;
}

//读取文件，手动管理内存
int readFileHand()
{
    std::ifstream file("example.txt", std::ios::binary | std::ios::ate);
    if (!file) {
        std::cerr << "Failed to open file." << std::endl;
        return  1;
    }

    std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    unsigned char* fileData = new unsigned char[fileSize];
    if (!file.read(reinterpret_cast<char*>(fileData), fileSize)) {
        std::cerr << "Failed to read file." << std::endl;
        delete[] fileData;
        return  1;
    }

    // 使用 fileData 的逻辑

    delete[] fileData;
    return 0;
}


