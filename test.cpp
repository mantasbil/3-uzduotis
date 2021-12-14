#include "pch.h"
#include "../V2.0/studentas.h"

TEST(simpleTest, test1) {
    Studentas stud;
    stud.setGalutinis(6.2);
    bool expectedValue = true;
    bool actualValue = islaike(stud);
    EXPECT_EQ(expectedValue, actualValue);
}
TEST(simpleTest, test2) {
    Studentas a;
    Studentas b;
    a.setVardas("Petras");
    a.setPavarde("Petraitis");
    b.setVardas("Jonas");
    b.setPavarde("Petraitis");
    EXPECT_EQ(false, compare_alphabet(a, b));
}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
}