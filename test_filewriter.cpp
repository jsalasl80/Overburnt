#include <gtest/gtest.h>
#include "FileWriter.h"

TEST(FileWriterTest, AppendLine) {
    FileWriter writer("test.txt");
    writer.appendLine("Test line");
    // Verify that the line was appended correctly
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
