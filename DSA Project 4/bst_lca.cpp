/** QUESTION 6: LOWEST COMMON ANCESTOR 

// EFFECTS: Returns the value of the lowest common ancestor of nodes l and m.
// 
// PSEUDOCODE:
// algorithm GetLCA
//   Input: tree, two targets
//   Output: the first shared parent of targets

  create vector for path of target one
  create vector for path of target two
  create int to hold ancestor

  call helper for first target path (used code from depth and path)
  call helper for second target path (used code from depth and path)

  for loop from 0 to path l size
    for loop from 0 to path m size
      compare every element of pathl to every one of pathm, if there is a similar element
        ancestor == that similar element

  return element
**/
std::vector<int> GetLCAPathHelper (std::vector<int> &bst, int target) 
{
  int size = bst.size();
  std::vector<int> path;

  path.push_back(bst.at(0));

  for(int i = 0; i < size;){
    if(target == bst[i]){
      return path;
    }

    else if(target < bst[i]){
      i = (2 * i) + 1;
      path.push_back(bst[i]);
    }

    else if(target > bst[i]){
      i = (2 * i) + 2;
      path.push_back(bst[i]);
    }
  }
  return path;
}
int GetLCA(std::vector<int> &bst, int l, int m)
{
  std::vector<int> pathl;
  std::vector<int> pathm;
  int ancestor;

  pathl = GetLCAPathHelper (bst, l);
  pathm = GetLCAPathHelper (bst, m);

  for (int i=0; i<pathl.size(); i++) {
     for (int j=0; j<pathm.size(); j++) {
       if (pathl[i] == pathm[j]) {
         ancestor = pathl[i];
       }
    }
  }

  return ancestor;
}
