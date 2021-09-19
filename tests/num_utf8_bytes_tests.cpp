//
// Created by Tessa Power on 12/09/21.
//

#include "gtest/gtest.h"
#include "../include/utf8_utils.h"

// 1 byte: < (60) > (62) & (38)
// 2 bytes: ¢ (162) Ѿ (d1be) Ͳ (cdb2)
// 3 bytes: ह (e0a4b9) € (e282ac) ⭐ (e2ad90) ✌ (e29c8c)
// 4 bytes: 🂱 (f09f82b1) 🍟 (f09f8d9f) 🍪 (f09f8daa) 𝄞 (f09d849e)

TEST(test, test1) {
    ASSERT_EQ(42, 42);
}

//TEST(num_utf8_bytes, one_byte) {
//    std::string str = "$";
//    const char* str_ptr = &(str[0]);
//    const uint8_t* ptr = (const uint8_t*)str_ptr;
//    EXPECT_EQ(1, num_utf8_bytes(*ptr));
//}

//TEST(num_utf8_bytes, one_byte) {
//
//    EXPECT_EQ(1, num_utf8_bytes());
//}
//
//TEST(num_utf8_bytes, one_byte) {
//
//    EXPECT_EQ(1, num_utf8_bytes());
//}
//
//TEST(num_utf8_bytes, one_byte) {
//
//    EXPECT_EQ(1, num_utf8_bytes());
//}
