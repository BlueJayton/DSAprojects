
/**
PSEUDOCODE:

algorithm ApproxSqrt

  Input: number to find sqrt of, number of iterations

  Output: approx of sqrt stopping at a number of iterations

  Your pseudocode goes here:

  float start = 0
  float middle = input num
  float stop = input num
  int count = 0;

  do while middle squared is not n, start is less than or equal to stop and count is less than iterations
    middle = middle divided by two

    if middle squared is greater than input
      stop = middle
    else if middle squared is less than input
      start = middle

    counts + 1


    string square root = call function to convert to string and set precision to 5, input is middle

    return square root
**/
std::string ApproxSqrt(int n, int iterations)
{
  float start = 0.0;
  float middle = n;
  float stop = n;
  int counts = 0;

  do {
    middle = middle / 2;

    if (middle * middle > n) {
        stop = middle;
    } else if (middle * middle < n) {
        start = middle;
    }

    counts++;

  } while (middle * middle != n && start <= stop && counts < iterations);

  std::string sqrt = ConvertFloatToStr (middle, 5);

  return sqrt;
}
