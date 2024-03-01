/**
PSEUDOCODE:

algorithm MinimumWordLength

  Input: array of words, size of array

  Output: length of word with min length

  Your pseudocode goes here:

  int for current min word length
  int for current word length
  for loop from 0 to array size
    word length equals current index word's lenght
    if min word length is less than current index word's length
        min word length equals index word's length

  return min word length
**/
int MinimumWordLength(std::string words[], int length)
{
  int minlen;
  int currlen;

  minlen = words[0].size();

  for (int i = 0; i < length; i++) {
    currlen = words[i].size();

    if (minlen > currlen) {
        minlen = currlen;
    }
  }

  return minlen;
}

/**
PSEUDOCODE:

algorithm MaximumWordLength

  Input: array of words, size of array

  Output: length of word with max length

  Your pseudocode goes here:

int for current max word length
  int for current word length
  for loop from 0 to array size
    word length equals current index word's lenght
    if max word length is greater than current index word's length
        max word length equals index word's length

  return max word length
**/
int MaximumWordLength(std::string words[], int length)
{
  int maxlen;
  int currlen;

  maxlen = words[0].size();

  for (int i = 0; i < length; i++) {
    currlen = words[i].size();

    if (maxlen < currlen) {
        maxlen = currlen;
    }
  }

  return maxlen;
}

/**
PSEUDOCODE:

algorithm RangeOfWordLengths

  Input: array of words, size of array

  Output: max length word minus min length word

  Your pseudocode goes here:

  use minlength function to find min length word

  use maxlength word to find max length word

  range equals maxlength minus minlength

  return range
**/
int RangeOfWordLengths(std::string words[], int length) {

  int minlen = MinimumWordLength (words, length);
  int maxlen = MaximumWordLength (words, length);

  int range = maxlen - minlen;

  return range;
}

/**
PSEUDOCODE:

algorithm WordLengthMean

  Input: array of words, size of array

  Output: total length of all words divided by number of words as integer

  Your pseudocode goes here:

  total length equals 0
  word count equals 0
  current word length
  int of mean

  for loop from 0 to size
    find length of word
    add length to total length
    add one to word count

  mean equals total length divided by word count
  return mean
**/
int WordLengthMean(std::string words[], int length)
{
   int totallen = 0;
   int wordcount = 0;
   int currlen;
   int mean;

   for (int i = 0; i < length; i++) {
    currlen = words[i].size();
    totallen = totallen + currlen;
    wordcount++;
   }

   mean = totallen / wordcount;

  return mean;
}

/**
PSEUDOCODE:

algorithm WordLengthMode

  Input: array of words, size of array

  Output: most common length of word

  Your pseudocode goes here:

  make array of a large number for word length counts
  make int to store index of most common word length in large array

  for loop that starts at 0 and goes through size
    add one to large array at index of word length

  for loop from 0 through large array
    if current count is larger than mode
      mode = current count

  mode equals index of current count

  return mode
**/
int WordLengthMode(std::string words[], int length)
{
    int counts[100] = {0};
    int mode = 0;
    int temp1 = 0;
    int temp2 = 0;


    for (int i = 0; i < length; i++) {
        counts[words[i].size()]++;
        temp1 = words[i].size();
        counts[temp1] = counts[temp1] + 1;

    }

    for (int j = 0; j < 100; j++) {
        if (counts[j] > mode) {
            temp2 = mode;
            mode = j;
        }
    }
    if (temp2 == mode) {
        return -1;
    }

    return mode;
}
