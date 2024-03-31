
#include "s21_test.h"

/**
 * main function for initializing Google Test and running all tests.
 *
 * @param argc number of command line arguments
 * @param argv array of command line arguments
 *
 * @return integer indicating the result of running all tests
 */
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
