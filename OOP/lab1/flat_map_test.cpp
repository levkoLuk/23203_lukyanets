#include <gtest/gtest.h>
#include "flatmap.h"

TEST(FlatMapTest, BasicOperations) {
    FlatMap map;
    EXPECT_TRUE(map.empty());
    EXPECT_EQ(map.size(), 0);

    map.insert("John", {25, 70});
    EXPECT_FALSE(map.empty());
    EXPECT_EQ(map.size(), 1);
    EXPECT_TRUE(map.contains("John"));
    EXPECT_FALSE(map.contains("Jane"));

    auto& value = map["John"];
    EXPECT_EQ(value.age, 25);
    EXPECT_EQ(value.weight, 70);

    map.erase("John");
    EXPECT_TRUE(map.empty());
    EXPECT_EQ(map.size(), 0);
}

TEST(FlatMapTest, AtAndOperator) {
    FlatMap map;
    map.insert("John", {25, 70});

    auto& value = map.at("John");
    EXPECT_EQ(value.age, 25);
    EXPECT_EQ(value.weight, 70);

    EXPECT_THROW(map.at("Jane"), std::out_of_range);

    auto& defaultValue = map["Jane"];
    EXPECT_EQ(defaultValue.age, 0);
    EXPECT_EQ(defaultValue.weight, 0);
}

TEST(FlatMapTest, SwapAndAssignment) {
    FlatMap map1;
    map1.insert("John", {25, 70});

    FlatMap map2;
    map2.insert("Jane", {30, 60});

    map1.swap(map2);
    EXPECT_TRUE(map1.contains("Jane"));
    EXPECT_TRUE(map2.contains("John"));

    FlatMap map3 = map1;
    EXPECT_TRUE(map3.contains("Jane"));

    FlatMap map4;
    map4 = std::move(map2);
    EXPECT_TRUE(map4.contains("John"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
