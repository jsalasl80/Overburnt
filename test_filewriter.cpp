#include <gtest/gtest.h>
#include "FileWriter.h"
#include <fstream>
#include <cstdio> // For std::remove

class FileWriterTest : public ::testing::Test {
protected:
    std::string testFilename = "test_report.txt";
    FileWriter* fileWriter;

    void SetUp() override {
        fileWriter = new FileWriter(testFilename);
    }

    void TearDown() override {
        delete fileWriter;
        std::remove(testFilename.c_str()); // Remove the test file after tests
    }

    std::string readFileContent(const std::string& filename) {
        std::ifstream file(filename);
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }
};

TEST_F(FileWriterTest, AppendLine) {
    std::string line = "This is a test line.\n";
    fileWriter->appendLine(line);

    std::string content = readFileContent(testFilename);
    EXPECT_EQ(content, line);
}

TEST_F(FileWriterTest, WipeAndRestartFile) {
    std::string openingLine = "Opening line.\n";
    fileWriter->wipeAndRestartFile(openingLine);

    std::string content = readFileContent(testFilename);
    EXPECT_EQ(content, openingLine);

    // Append another line to ensure the file was wiped correctly
    std::string line = "Another test line.\n";
    fileWriter->appendLine(line);
    content = readFileContent(testFilename);
    EXPECT_EQ(content, openingLine + line);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
