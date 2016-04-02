#include <string>

#include <gtest/gtest.h>

#include "rot47.h"
#include "rot47_stepping.h"


class TestRot : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        sinput.str(loremIpsum);
    }

    void clearStreams()
    {
        sinput.clear();
        soutput.clear();
        soutput.str("");
        sinput.str(output);
    }

    virtual void TearDown()
    {
        sinput.clear();
        soutput.clear();
        soutput.str("");
        sinput.str("");
        output.clear();
    }

    std::stringstream sinput;
    std::stringstream soutput;
    std::string output;
    const std::string loremIpsum = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
};

TEST_F(TestRot, encode_decode)
{
    rot47::parse(sinput, soutput);
    output = soutput.str();
    ASSERT_NE(0, output.size());
    clearStreams();
    rot47::parse(sinput, soutput);
    ASSERT_EQ(loremIpsum, soutput.str());
}

TEST_F(TestRot, stepping_encode_decode)
{
    rot47::stepping::parse(sinput, soutput, rot47::stepping::Direction::Forward);
    output = soutput.str();
    ASSERT_NE(0, output.size());
    clearStreams();
    rot47::stepping::parse(sinput, soutput, rot47::stepping::Direction::Backward);
    ASSERT_EQ(loremIpsum, soutput.str());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
