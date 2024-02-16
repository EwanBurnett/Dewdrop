#include <gtest/gtest.h>
#include <Dewdrop/Version.h>

TEST(Dewdrop, VersionAssertion){
	EXPECT_EQ(Dewdrop::DEWDROP_VERSION_MAJOR, 0);
	EXPECT_EQ(Dewdrop::DEWDROP_VERSION_MINOR, 0);
	EXPECT_EQ(Dewdrop::DEWDROP_VERSION_PATCH, 0);
	EXPECT_EQ(Dewdrop::DEWDROP_VERSION_BUILD, 0);
}
