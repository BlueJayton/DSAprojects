
/** QUESTION 1: FINDNODE

// EFFECTS: Traverses the Tree based on the charactes in the prefix and
//          returns the TreeNode that we end at. If we cannot find a valid node,
//          we return an empty TreeNode. The index variable keeps track of what
//          character we're at in prefix.
//
// PSEUDOCODE:
// algorithm FindNode
//   Input: tree root node, prefix string, index (loop count)
//   Output: value of node equal to last letter down path

   if node is empty
    return empty node

   char request = last letter we are looking for

   if (request == current nodes value)
      return node
   else {

     new vector = getchildren

     for (auto through children)
        if (child value == next letter)
          node = child
   }

    index++;
    return FindNode (node (next node), prefix, index)
**/
TreeNode<char> FindNode(TreeNode<char> node, std::string prefix, int index)
{
  if (node.IsEmpty() == true) {
    return TreeNode<char>();
  }

  char req = prefix[prefix.size()-1];

  if (index == prefix.size()) {
    if(req == node.GetValue()) {
      return node;
      }
    }
  
  std::vector<TreeNode<char> > children = node.GetChildren();
  bool found = false;
  for (auto child : children) {
     if (child.GetValue() == prefix[index]) {
        found = true;
        node = child;
     }
  }     
     if (found == false) {
      return TreeNode<char>();
     }
  
  index++;
  return FindNode (node, prefix, index);
}

/** QUESTION 2: COLLECTWORDS

// EFFECTS: Collects all the words starting from a given TreeNode. For each word,
//          prepends the word with the prefix and adds it to the results vector.
//
// PSEUDOCODE:
// algorithm CollectWords
//   Input: first node, prefix, vector of results
//   Output: no return, just add results to front of vector

    make vector and set to get children of node

    for (auto) {
       char val = get value of child
       add val to string at index;
       index++;
    }

    for (auto child : children) {
      node = child;
      return CollectWords(node, prefix, results vector)
    }
**/
void CollectWords (TreeNode<char> node, std::string prefix, std::vector<std::string> &results)
{

  std::vector<TreeNode<char> > children = node.GetChildren();

  for(auto child : children){
      node = child;
      if(node.IsLeaf()){
        if (children.size() > 1) {
          results.push_back(prefix);
        } else {
          results.push_back(prefix);
          return;
        }
      }

      prefix += node.GetValue();
      CollectWords(node, prefix, results);

      prefix.pop_back();
   }
  
}


/** QUESTION 3: GETCANDIDATES **/

/** // EFFECTS: Returns the list of all possible words that can be made starting with
//          the letters in prefix, based on traversing the tree with the given root.
//
// PSEUDOCODE:
// algorithm GetCandidates
//   Input: root, starting letter
//   Output: all words made with letter give

    create vector of all words
    if (prefix is empty) {
      create vector of children

      for each
        FindNode of child
        CollectWords of child into words vector
    } else {
      FindNode of root
      Collect words of root into words vector
    }

   return words vector
**/
std::vector<std::string> GetCandidates(TreeNode<char> root, std::string prefix) 
{
  std::vector<std::string> words;
  if (prefix == "") {
    std::vector<TreeNode<char> > children = root.GetChildren();

    for (auto child : children) {
     prefix = child.GetValue();
     CollectWords(child, prefix, words);  
    }
  } else {
     root = FindNode(root, prefix, 0);
     CollectWords(root, prefix, words);
  }
  return words;
}
