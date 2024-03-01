/** QUESTION 4: BST VALIDATOR 

// EFFECTS: Returns true if the tree is a valid BST, or false otherwise.
// 
// PSEUDOCODE:
// algorithm IsBST
//   Input: vector of ints
//   Output: bool of whether its a bst or not

  get size of of tree vector

  for loop from 0 - size
    if (left index is < size (valid node)) {
      if (current index is more than right) {
        return false
      }
    if (right index is < size (valid node)) {
      if (current index is less than left) {
        return false
      }
    }
  }

   return true (if nothing was wrong)
**/

bool IsBST(std::vector<int> &binary_tree)
{
  int size = binary_tree.size();

  for (int i=0; i<size; i++) {
     if ((2*i) + 1 < size) {
       if (binary_tree[i] > binary_tree[(i*2) + 1]) {
         return false;
       }
     } 
    if ((2*i) + 2 < size) {
       if (inary_tree[i] < binary_tree[(i*2) + 1]) {
         return false;
       }
     }
   }

  return true;
}
