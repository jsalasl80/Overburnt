#include <gtest/gtest.h>
#include "RecipeReader.h"

TEST(RecipeReaderTest, ReadRecipes) {
    RecipeReader reader;
    reader.readRecipes("bin/recetas.csv");
    // Verify that the recipes were read correctly
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
