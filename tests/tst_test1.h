#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

/* using namespace testing; */
extern "C" {
#include "root.h"
}

TEST(Root, no_roots){

    ans cur = root(4,1,4);
    EXPECT_EQ(cur.count, 0);
}

TEST(Root, one_root){

    ans cur = root(4, 4, 1);
    EXPECT_EQ(cur.count, 1);
    EXPECT_DOUBLE_EQ(cur.x, -0.5);

}

TEST(Root, two_roots){

    ans cur = root(1, 1, -6);
    EXPECT_EQ(cur.count, 2);
    EXPECT_DOUBLE_EQ(cur.x, 2);
    EXPECT_DOUBLE_EQ(cur.y, -3);

}

TEST(Root, two_roots_precision){

    ans cur = root(1, 6, 3);
    EXPECT_EQ(cur.count, 2);
    EXPECT_NEAR(cur.x, -0.551, 0.001);
    EXPECT_NEAR(cur.y, -5.449, 0.001);

}

TEST(Root, double_input){

    ans cur = root(1.123, 6.431, 3.99999);
    EXPECT_EQ(cur.count, 2);
    EXPECT_NEAR(cur.x, -0.710, 0.001);
    EXPECT_NEAR(cur.y, -5.017, 0.001);
}

TEST(Root, non_square){
    ans cur = root(0, 1, 2);
    EXPECT_DOUBLE_EQ(cur.x, -2);
}

TEST(Root, zero){
    ans cur = root(0, 0, 0);
    EXPECT_EQ(cur.count, 3);
}

TEST(Root, zero_1){

    ans cur = root(0, 0, 1);
    EXPECT_EQ(cur.count, 0);
}

TEST(Root, output_no_root){

    testing::internal::CaptureStdout();

    root(4, 1, 4);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("no roots\n", output);
}

TEST(Root, output_one_root){

    testing::internal::CaptureStdout();

    root(4, 4, 1);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("x = -0.500\n", output);
}

TEST(Root, output_two_roots){

    testing::internal::CaptureStdout();

    root(1, 6, 3);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("x = -0.551, y = -5.449\n", output);
}

TEST(Root, output_zero){

    testing::internal::CaptureStdout();

    root(0, 0, 0);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("any solution\n", output);
}


TEST(Root, string_input){

    freopen("string.txt", "r", stdin);
    double a,b,c;
    std::cin >> a >> b >> c;
    root(a,b,c);
    FAIL();

}

TEST(Root, char_input){

    freopen("char.txt", "r", stdin);
    double a,b,c;
    std::cin >> a >> b >> c;
    root(a,b,c);
    FAIL();

}


TEST(Root, bound){

    freopen("bound.txt", "r", stdin);
    double a,b,c,x,y;
    int k;
    while(std::cin >> a >> b >> c >> k >> x >> y){
        ans cur = root(a,b,c);
        EXPECT_NEAR(x, cur.x, 0.001);
        EXPECT_NEAR(y, cur.y, 0.001);
        EXPECT_EQ(k, cur.count);

    }
}

