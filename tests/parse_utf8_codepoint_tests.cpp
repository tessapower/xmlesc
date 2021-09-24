//
// Created by Tessa Power on 19/09/21.
//

#include <gtest/gtest.h>
#include <utf8_utils/utf8_utils.h>

// 1 byte: < (0x003C) > (0x003E) & (0x0026)
TEST(parse_utf8_codepoint, one_byte_utf8) {
    const uint8_t str[] = "<>&";
    const uint8_t* input_0 = &str[0];
    EXPECT_EQ(0x003C, parse_utf8_codepoint(input_0).codepoint);

    const uint8_t* input_1 = &str[1];
    EXPECT_EQ(0x003E, parse_utf8_codepoint(input_1).codepoint);

    const uint8_t* input_2 = &str[2];
    EXPECT_EQ(0x0026, parse_utf8_codepoint(input_2).codepoint);
}

// 2 bytes: ¢ (0x00A2) Ѿ (0x047E) Ͳ (0x0372)
TEST(parse_utf8_codepoint, two_byte_utf8) {
    const uint8_t str_1[] = "¢";
    const uint8_t* input_1 = &str_1[0];
    EXPECT_EQ(0x00A2, parse_utf8_codepoint(input_1).codepoint);

    const uint8_t str_2[] = "Ѿ";
    const uint8_t* input_2 = &str_2[0];
    EXPECT_EQ(0x047E, parse_utf8_codepoint(input_2).codepoint);

    const uint8_t str_3[] = "Ͳ";
    const uint8_t* input_3 = &str_3[0];
    EXPECT_EQ(0x0372, parse_utf8_codepoint(input_3).codepoint);
}

// 3 bytes: ह (0x0939) € (0x20AC) ⭐ (0x2B50) ✌ (0x270C)
TEST(parse_utf8_codepoint, three_byte_utf8) {
    const uint8_t str_1[] = "ह";
    const uint8_t* input_1 = &str_1[0];
    EXPECT_EQ(0x0939, parse_utf8_codepoint(input_1).codepoint);

    const uint8_t str_2[] = "€";
    const uint8_t* input_2 = &str_2[0];
    EXPECT_EQ(0x20AC, parse_utf8_codepoint(input_2).codepoint);

    const uint8_t str_3[] = "⭐";
    const uint8_t* input_3 = &str_3[0];
    EXPECT_EQ(0x2B50, parse_utf8_codepoint(input_3).codepoint);

    const uint8_t str_4[] = "✌";
    const uint8_t* input_4 = &str_4[0];
    EXPECT_EQ(0x270C, parse_utf8_codepoint(input_4).codepoint);
}

// TODO: Test these when we are able to handle unicode characters with multiple
//   codepoints!
// 4 bytes: 🂱 (0x1F0B1) 🍟 (0x1F35F) 🍪 (0x1F36A) 𝄞 (0x1D11E)
//TEST(parse_utf8_codepoint, four_byte_utf8) {
//    const uint8_t str_1[] = "🂱";
//    const uint8_t* input_1 = &str_1[0];
//    EXPECT_EQ(0x1F0B1, parse_utf8_codepoint(input_1).codepoint);

//    const uint8_t str_2[] = "🍟";
//    const uint8_t* input_2 = &str_2[0];
//    EXPECT_EQ(0x1F35F, parse_utf8_codepoint(input_2).codepoint);
//
//    const uint8_t str_3[] = "🍪";
//    const uint8_t* input_3 = &str_3[0];
//    EXPECT_EQ(0x1F36A, parse_utf8_codepoint(input_3).codepoint);
//
//    const uint8_t str_4[] = "𝄞";
//    const uint8_t* input_4 = &str_4[0];
//    EXPECT_EQ(0x1D11E, parse_utf8_codepoint(input_4).codepoint);
//}
