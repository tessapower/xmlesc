//
// Created by Tessa Power on 12/09/21.
//

#include "gtest/gtest.h"
#include "../include/utf8_utils.h"

// 1 byte: < (0x003C) > (0x003E) & (0x0026)
TEST(num_utf8_bytes, one_byte) {
    const uint8_t str[] = "<>&";
    const uint8_t* input_0 = &str[0];
    EXPECT_EQ(1, num_utf8_bytes(*input_0));

    const uint8_t* input_1 = &str[1];
    EXPECT_EQ(1, num_utf8_bytes(*input_1));

    const uint8_t* input_2 = &str[2];
    EXPECT_EQ(1, num_utf8_bytes(*input_2));
}

// 2 bytes: ¢ (0x00A2) Ѿ (0x047E) Ͳ (0x0372)
TEST(num_utf8_bytes, two_bytes) {
    const uint8_t str_1[] = "¢";
    const uint8_t* input_1 = &str_1[0];
    EXPECT_EQ(2, num_utf8_bytes(*input_1));

    const uint8_t str_2[] = "Ѿ";
    const uint8_t* input_2 = &str_2[0];
    EXPECT_EQ(2, num_utf8_bytes(*input_2));

    const uint8_t str_3[] = "Ͳ";
    const uint8_t* input_3 = &str_3[0];
    EXPECT_EQ(2, num_utf8_bytes(*input_3));
}

// 3 bytes: ह (0x0939) € (0x20AC) ⭐ (0x2B50) ✌ (0x270C)
TEST(num_utf8_bytes, three_bytes) {
    const uint8_t str_1[] = "ह";
    const uint8_t* input_1 = &str_1[0];
    EXPECT_EQ(3, num_utf8_bytes(*input_1));

    const uint8_t str_2[] = "€";
    const uint8_t* input_2 = &str_2[0];
    EXPECT_EQ(3, num_utf8_bytes(*input_2));

    const uint8_t str_3[] = "⭐";
    const uint8_t* input_3 = &str_3[0];
    EXPECT_EQ(3, num_utf8_bytes(*input_3));

    const uint8_t str_4[] = "✌";
    const uint8_t* input_4 = &str_4[0];
    EXPECT_EQ(3, num_utf8_bytes(*input_4));
}

// 4 bytes: 🂱 (0x1F0B1) 🍟 (0x1F35F) 🍪 (0x1F36A) 𝄞 (0x1D11E)
TEST(num_utf8_bytes, four_bytes) {
    const uint8_t str_1[] = "🂱";
    const uint8_t* input_1 = &str_1[0];
    EXPECT_EQ(4, num_utf8_bytes(*input_1));

    const uint8_t str_2[] = "🍟";
    const uint8_t* input_2 = &str_2[0];
    EXPECT_EQ(4, num_utf8_bytes(*input_2));

    const uint8_t str_3[] = "🍪";
    const uint8_t* input_3 = &str_3[0];
    EXPECT_EQ(4, num_utf8_bytes(*input_3));

    const uint8_t str_4[] = "𝄞";
    const uint8_t* input_4 = &str_4[0];
    EXPECT_EQ(4, num_utf8_bytes(*input_4));
}
