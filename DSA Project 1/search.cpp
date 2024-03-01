/**
PSEUDOCODE:

algorithm LinearSearch

  Input: integer array, array size, and number to search for

  Output: return array index of specified number
                        or
    return -1 if number doesn't exist in array

  Your pseudocode goes here:

  for loop from 0 to length
        if current index equals search number
            return current index

  (if not found)
  return -1
**/
int LinearSearch(int numbers[], int length, int n)
{

  for (int i = 0; i < length; i++){
    if (numbers[i] == n) {
        return i;
    }
  }


  return -1;
}

/**
PSEUDOCODE:

algorithm BinarySearch

  Input: integer array sorted into ascending order, array size, and number to search for

  Output: return array index of specified number
                        or
    return -1 if number doesn't exist in array

  Your pseudocode goes here:

  start is 0
  make int middle
  stop = length minus 1

  do while middle doesn't equal n and start is not greater than stop
    middle equals length-1 divided by 2

    if middle equals n
      return middle
    else if middle is less than n
      start is middle + 1
    else if middle is greater than n
      stop = middle minus 1

  (if not found)
  return -1
**/
int BinarySearch(int numbers[], int length, int n)
{
  int start = 0;
  int stop = length;
  int middle;

  while (start <= stop){

    middle = (start + stop) / 2;

    if (numbers[middle] == n) {
        return middle;
    } else if (numbers[middle] < n) {
        start = middle - 1;
    } else if (numbers[middle] > n) {
        stop = middle + 1;
    }

  };

  return -1;
}
