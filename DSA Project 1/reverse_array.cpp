/**
PSEUDOCODE:

algorithm ReverseArray

  Input: array of ints, array size

  Output: array of integers reveersed

  Side Effect:

  Your pseudocode goes here:

  int mid equals size of array divided by 2
  int temp

  for loop from 0 to mid
    temp = array[i]
    array[i] = array[size - i]
    array [size - i] = temp;
**/
void ReverseArray(int arr[], int length)
{
  int stop = length - 1;
  int middle = stop / 2;
  int temp;

  for (int i = 0; i < middle; i++) {
      temp = arr[i];
      arr[i] = arr[stop - i];
      arr[stop - i] = temp;
  }
}
