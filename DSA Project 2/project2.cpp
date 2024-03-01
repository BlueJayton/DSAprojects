
/** QUESTION 1: SUM AND PRODUCT **/

/** EFFECTS: returns the sum of each element in list, or zero if the list is
//          empty
// Your implementation of Sum should NOT be tail recursive and should NOT
// use a helper function.
//
// PSEUDOCODE:
// algorithm Sum

    check if list is empty
        if it is return 0

    return this function with next node element plus current element
**/
int Sum(RecursiveList list)
{
    if (ListIsEmpty(list) == true) {
        return 0;
    }
    return ListFirst(list) + Sum(ListRest(list));
}

/** EFFECTS: returns the product of each element in list, or one if the list is
//          empty
//
// PSEUDOCODE:
// algorithm Product
    In parent function:
        if list is empty
            return 0

        int prod = 1 (setting it to 0 would make the end be 0)
        return helper function

    In helper function (list and prod as inputs)
        if list is empty
            return prod

        return helper with next element, and current element times prod
**/
int ProductHelper (RecursiveList list, int prod)
{
    if (ListIsEmpty(list) == true) {
        return prod;
    }

    return ProductHelper(ListRest(list), ListFirst(list) * prod);
}

int Product(RecursiveList list)
{
    if (ListIsEmpty(list) == true) {
        return 0;
    }
    int prod = 1;
    return ProductHelper(list, prod);
}

/** QUESTION 2: TAIL RECURSIVE SUM **/

/** EFFECTS: adds the next element in the list to the sum so far
// Your implementation of TailRecursiveSumHelper MUST be tail recursive.
//
// PSEUDOCODE:
// algorithm TailRecursiveSumHelper

    check if element is non existent
        if it is return sum
        else
            return this function with next element and sum + current element
**/
int TailRecursiveSumHelper(RecursiveList list, int sum_so_far)
{
    if (ListIsEmpty(list) == true) {
        return sum_so_far;
    } else {
        return TailRecursiveSumHelper (ListRest(list), sum_so_far + ListFirst(list));
    }
}

// EFFECTS: returns the sum of each element in list, or zero if the list is
//          empty
// THIS FUNCTION IS PROVIDED AS PART OF THE STARTER CODE.
// DO NOT MODIFY THIS FUNCTION.
//
// PSEUDOCODE:
// algorithm TailRecursiveSum
//   return TailRecursiveSumHelper(list, 0)
int TailRecursiveSum(RecursiveList list) {
  return TailRecursiveSumHelper(list, 0);
}


/** QUESTION 3: FILTER ODD AND FILTER EVEN **/

/** EFFECTS: returns a new list containing only the elements of the original list
//          which are odd in value, in the order in which they appeared in list
// For example, FilterOdd(( 4 1 3 0 )) would return the list ( 1 3 )
//
// PSEUDOCODE:
// algorithm FilterOdd
    In parent function
        make a new list for odds

        return helper (pass list and new list)

    In helper function
        if list is empty
            return reversed oddlist (make list adds to front of list so must reverse)
        else if first element is not even
            add element to oddlist
            return helper with next element
        else (if element is even)
            return helper with next element
**/
RecursiveList FilterOddHelper (RecursiveList list, RecursiveList Oddlist)
{
    if (ListIsEmpty(list) == true) {
        return Reverse(Oddlist);
    } else if (ListFirst(list) % 2 != 0) {
        Oddlist = MakeList(ListFirst(list), Oddlist);
        return FilterOddHelper(ListRest(list), Oddlist);
    } else {
        return FilterOddHelper(ListRest(list), Oddlist);
    }
}

RecursiveList FilterOdd(RecursiveList list)
{
    RecursiveList Oddlist = MakeList();

    return FilterOddHelper(list, Oddlist);
}

/** EFFECTS: returns a new list containing only the elements of the original list
//          which are even in value, in the order in which they appeared in list
// For example, FilterEven(( 4 1 3 0 )) would return the list ( 4 0 )
//
// PSEUDOCODE:
// algorithm FilterEven

    In parent function
        make a new list for evens

        return helper (pass list and new list)

    In helper function
        if list is empty
            return reversed evenlist (make list adds to front of list so must reverse)
        else if first element is even
            add element to evenlist
            return helper with next element
        else (if element is odd)
            return helper with next element
**/
RecursiveList FilterEvenHelper (RecursiveList list, RecursiveList Evenlist)
{
    if (ListIsEmpty(list) == true) {
        return Reverse(Evenlist);
    } else if (ListFirst(list) % 2 == 0) {
        Evenlist = MakeList(ListFirst(list), Evenlist);
        return FilterEvenHelper(ListRest(list), Evenlist);
    } else {
        return FilterEvenHelper(ListRest(list), Evenlist);
    }
}

RecursiveList FilterEven(RecursiveList list)
{
    RecursiveList Evenlist = MakeList();

    return FilterEvenHelper(list, Evenlist);
}

/** QUESTION 4: REVERSE **/

/** EFFECTS: returns the reverse of list
// For example, the reverse of ( 3 2 1 ) is ( 1 2 3 )
//
// PSEUDOCODE:
// algorithm Reverse
    In parent function
        make new list for reverse
        return helper (pass list and new list)

    In helper
        if list is empty
            return reverse

        add current element to reversed (make list add new element
                                         to the FRONT of the list,
                                         making it reversed)
            return helper function with next element
**/
RecursiveList ReverseHelper (RecursiveList list, RecursiveList reverselist)
{
    if (ListIsEmpty(list) == true) {
        return reverselist;
    }

    reverselist = MakeList(ListFirst(list), reverselist);

    return ReverseHelper (ListRest(list), reverselist);
}

RecursiveList Reverse(RecursiveList list)
{
    RecursiveList reverselist = MakeList();

    return ReverseHelper (list, reverselist);
}


/** QUESTION 5: APPEND **/

/** EFFECTS: returns the list (first_list second_list)
// For example, if first_list is ( 1 2 3 ) and second_list is ( 4 5 6 ), then
// returns ( 1 2 3 4 5 6 )
//
// PSEUDOCODE:
// algorithm Append
    In parent function
        make a new list for all elements
        reverse list one
        reverse list two (make list adds to front, so must reverse to
                          go back forward when adding elements)

        return helper (pass first, second, and new list)

    In helper function
        if second list is not empty (must start with second because reversal)
            add element to new list
            return helper with next element in second list
        else if first list is not empty
            add element to new list
            return helper with next element in first list
        else
            return new list
**/
RecursiveList AppendHelper (RecursiveList first_list, RecursiveList second_list,
                            RecursiveList Appendlist)
{
    if (ListIsEmpty(second_list) == false) {
        Appendlist = MakeList(ListFirst(second_list), Appendlist);
        return AppendHelper(first_list, ListRest(second_list), Appendlist);
    } else if (ListIsEmpty(first_list) == false) {
        Appendlist = MakeList(ListFirst(first_list), Appendlist);
        return AppendHelper(ListRest(first_list), second_list, Appendlist);
    } else {
        return Appendlist;
    }
}

RecursiveList Append(RecursiveList first_list, RecursiveList second_list)
{

    RecursiveList Appendlist = MakeList();

    first_list = Reverse(first_list);
    second_list = Reverse(second_list);

    return AppendHelper(first_list, second_list, Appendlist);

}


/** QUESTION 6: CHOP **/

/** REQUIRES: list has at least n elements
// EFFECTS: returns the list equal to list without its last n elements
//
// PSEUDOCODE:
// algorithm Chop
    In parent function
        make new chopped list
        make new reversed list (must reverse because makelist)
        reversedlist = the main list reversed (dont want to change main list)

        return helper function (pass both new lists and n)

    In helper function
        if statement
            count through n moving to next element in list
            return helper
        else if list is not empty
            add current element to chopped list
            return helper
        else
            return chopped
**/
RecursiveList ChopHelper (RecursiveList list, RecursiveList Choppedlist,
                          unsigned int n)
{
    if (n > 0) {
        n--;
        return ChopHelper(ListRest(list), Choppedlist, n);
    } else if (ListIsEmpty(list) != true) {
        Choppedlist = MakeList(ListFirst(list), Choppedlist);
        return ChopHelper(ListRest(list), Choppedlist, n);
    } else {
        return Choppedlist;
    }


}

RecursiveList Chop(RecursiveList list, unsigned int n)
{
    RecursiveList Choppedlist = MakeList();
    RecursiveList Reverselist = MakeList();
    Reverselist = Reverse(list);

    return ChopHelper(Reverselist, Choppedlist, n);
}


/** QUESTION 7: ROTATE **/

/** EFFECTS: returns a list equal to the original list with the
//          first element moved to the end of the list n times.
// For example, Rotate(( 1 2 3 4 5 ), 2) yields ( 3 4 5 1 2 )
//
// PSEUDOCODE:
// algorithm Rotate
    In parent function
        make two lists

        return helper (pass list, n, and both new lists)

    In helper function
        if statement
            count through n
            add current element to first list
            return helper with next element of list
        else if list is not empty (after ns)
            add current element to second list
            return helper with next element in list
        else
            use append function to attach reversed lists together
            (reversed because of makelist)
**/
RecursiveList RotateHelper (RecursiveList list, unsigned int n,
                            RecursiveList first_list, RecursiveList second_list)
{
    if (n > 0) {
        n--;
        first_list = MakeList (ListFirst(list), first_list);
        return RotateHelper (ListRest(list), n, first_list, second_list);
    } else if (ListIsEmpty(list) != true) {
        second_list = MakeList (ListFirst(list), second_list);
        return RotateHelper (ListRest(list), n, first_list, second_list);
    } else {
        return Append (Reverse(second_list), Reverse(first_list));
    }
}

RecursiveList Rotate(RecursiveList list, unsigned int n)
{
    RecursiveList first_list = MakeList();
    RecursiveList second_list = MakeList();

    return RotateHelper (list, n, first_list, second_list);
}


/** QUESTION 8: INSERT LIST **/

/** REQUIRES: n <= the number of elements in first_list
// EFFECTS: returns a list comprising the first n elements of first_list,
//          followed by all elements of second_list, followed by any remaining
//          elements of "first_list"
// For example, InsertList (( 1 2 3 ), ( 4 5 6 ), 2) returns ( 1 2 4 5 6 3 )
//
// PSEUDOCODE:
// algorithm InsertList
    In parent function
        make list for start (middle will be second list)
        make list for end

        return helper (pass first list, second list, startlist, endlist, and n)

    In helper function
        if statement
            count through n
            add current first list element to start list
            return helper with next first list element
        else if first list is not empty
            add current first list element to endlist
            return helper with next first list element
        else if second list is not empty (after first is empty)
            add current second list element to start list (fill gap)
            return helper with next second list element

        return append function with reversed start and end list
        (reversed because of makelist)
**/
RecursiveList InsertListHelper (RecursiveList first_list, RecursiveList second_list,
                                RecursiveList Startlist, RecursiveList Endlist,
                                unsigned int n)
{
    if (n > 0) {
        n--;
        Startlist = MakeList (ListFirst(first_list), Startlist);
        return InsertListHelper (ListRest(first_list), second_list, Startlist,
                                  Endlist, n);
    } else if (ListIsEmpty(first_list) != true) {
        Endlist = MakeList (ListFirst(first_list), Endlist);
        return InsertListHelper (ListRest(first_list), second_list, Startlist,
                                  Endlist, n);
    } else if (ListIsEmpty(second_list) != true)  {
        Startlist = MakeList (ListFirst(second_list), Startlist);
        return InsertListHelper (first_list, ListRest(second_list), Startlist,
                                  Endlist, n);
    }


    return Append(Reverse(Startlist), Reverse(Endlist));
}

RecursiveList InsertList(RecursiveList first_list, RecursiveList second_list,
                         unsigned int n)
{
    RecursiveList Startlist = MakeList();
    RecursiveList Endlist = MakeList();


    return InsertListHelper (first_list, second_list, Startlist, Endlist, n);
}
