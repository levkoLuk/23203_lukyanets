#include "flatmap.h"
#include <gtest/gtest.h>

Value createValue(unsigned age, unsigned weight) {
    Value val;
    val.age = age;
    val.weight = weight;
    return val;
}

TEST(FlatMapTest, DefaultConstructor) {
    FlatMap map;
    EXPECT_EQ(map.size(), 0);
    EXPECT_TRUE(map.empty());
}

TEST(FlatMapTest, CopyConstructor) {
    FlatMap map;
    map.insert("key1", createValue(25, 70));

    FlatMap mapCopy(map);
    EXPECT_EQ(mapCopy.size(), 1);
    EXPECT_TRUE(mapCopy.contains("key1"));
    EXPECT_EQ(mapCopy.at("key1").age, 25);
}

TEST(FlatMapTest, MoveConstructor) {
    FlatMap map;
    map.insert("key1", createValue(25, 70));

    FlatMap mapMove(std::move(map));
    EXPECT_EQ(mapMove.size(), 1);
    EXPECT_TRUE(mapMove.contains("key1"));
    EXPECT_EQ(mapMove.at("key1").age, 25);
}

TEST(FlatMapTest, CopyAssignment) {
    FlatMap map;
    map.insert("key1", createValue(25, 70));

    FlatMap mapAssign;
    mapAssign = map;
    EXPECT_EQ(mapAssign.size(), 1);
    EXPECT_TRUE(mapAssign.contains("key1"));
    EXPECT_EQ(mapAssign.at("key1").age, 25);
}

TEST(FlatMapTest, MoveAssignment) {
    FlatMap map;
    map.insert("key1", createValue(25, 70));

    FlatMap mapAssign;
    mapAssign = std::move(map);
    EXPECT_EQ(mapAssign.size(), 1);
    EXPECT_TRUE(mapAssign.contains("key1"));
    EXPECT_EQ(mapAssign.at("key1").age, 25);
}

TEST(FlatMapTest, Swap) {
    FlatMap map1, map2;
    map1.insert("key1", createValue(25, 70));
    map2.insert("key2", createValue(30, 80));

    map1.swap(map2);
    EXPECT_TRUE(map1.contains("key2"));
    EXPECT_TRUE(map2.contains("key1"));
}

TEST(FlatMapTest, Clear) {
    FlatMap map;
    map.insert("key1", createValue(25, 70));
    map.clear();
    EXPECT_EQ(map.size(), 0);
    EXPECT_TRUE(map.empty());
}

TEST(FlatMapTest, Erase) {
    FlatMap map;
    map.insert("key1", createValue(25, 70));
    EXPECT_TRUE(map.erase("key1"));
    EXPECT_FALSE(map.contains("key1"));
    EXPECT_FALSE(map.erase("nonexistent_key")); // Erasing non-existing key
}

TEST(FlatMapTest, InsertAndContains) {
    FlatMap map;
    EXPECT_TRUE(map.insert("key1", createValue(25, 70)));
    EXPECT_FALSE(map.insert("key1", createValue(30, 80))); // Duplicate insert should fail
    EXPECT_TRUE(map.contains("key1"));
}

TEST(FlatMapTest, SubscriptOperator) {
    FlatMap map;
    map["key1"] = createValue(25, 70);
    EXPECT_EQ(map["key1"].age, 25);

    map["key1"].age = 30; // Modify existing key
    EXPECT_EQ(map["key1"].age, 30);
}

TEST(FlatMapTest, AtMethod) {
    FlatMap map;
    map.insert("key1", createValue(25, 70));

    EXPECT_EQ(map.at("key1").age, 25);

    EXPECT_THROW(map.at("nonexistent_key"), std::runtime_error);
}

TEST(FlatMapTest, ConstAtMethod) {
    const FlatMap map = [] {
        FlatMap tmp;
        tmp.insert("key1", createValue(25, 70));
        return tmp;
    }();

    EXPECT_EQ(map.at("key1").age, 25);
}

TEST(FlatMapTest, SizeAndEmpty) {
    FlatMap map;
    EXPECT_TRUE(map.empty());

    map.insert("key1", createValue(25, 70));
    EXPECT_EQ(map.size(), 1);
    EXPECT_FALSE(map.empty());
}

TEST(FlatMapTest, EqualityOperators) {
    FlatMap map1, map2;
    map1.insert("key1", createValue(25, 70));
    map2.insert("key1", createValue(25, 70));

    EXPECT_TRUE(map1 == map2);
    map2["key1"].age = 30;
    EXPECT_FALSE(map1 == map2);
    EXPECT_TRUE(map1 != map2);
}
