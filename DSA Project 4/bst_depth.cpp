
/** QUESTION 5: DEPTH AND PATH 

// EFFECTS: Returns the depth of the target node. Modifies the path vector
//          so that it contains the node values in the path from the root to
//          the target node.
// 
// PSEUDOCODE:
// algorithm GetDepthAndPath
//   Input: tree (vector ints), target node, vector of the path to get to target
//   Output: returns depth level, but also changes path vector

   make int of level
   make int to store tree size_t

   add root to path

   for loop from 0 to size
     if (target = bst index)
       return depth int
     else if (target is less than bst index)
       add one to leve
       i = left node index
       add bst index to path
     else if (target is greater than bst index)
       add one to leve
       i = right node index
       add bst index to path

   return level
**/
int GetDepthAndPath(std::vector<int> &bst, int target, std::vector<int> &path) 
{
  int level = 0;
  int size = bst.size();

  path.push_back(bst.at(0));

  for(int i = 0; i < size;){
    if(target == bst[i]){
      return level;
    } else if(target < bst[i]){
      level++;
      i = (2 * i) + 1;
      path.push_back(bst[i]);
    } else if(target > bst[i]){
      level++;
      i = (2 * i) + 2;
      path.push_back(bst[i]);
    }
  }

  return level;
}
