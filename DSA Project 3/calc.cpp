
// EFFECTS: performs + operation
void DoAdd(Dlist<double> &stack)
{
    if(!stack.IsEmpty()) {
        double firnum = stack.RemoveFront();

        if (!stack.IsEmpty()) {
            double secnum = stack.RemoveFront();
            double total = firnum;
            total = firnum + secnum;
            stack.InsertFront(total);
        } else {
             stack.InsertFront(firnum);
             throw emptyList();
        }
    } else {
       throw emptyList();
      }
}

// EFFECTS: performs - operation
void DoSub(Dlist<double> &stack)
{
    if(!stack.IsEmpty()) {
        double firnum = stack.RemoveFront();

        if (!stack.IsEmpty()) {
            double secnum = stack.RemoveFront();
            double total = firnum;
            total = secnum - firnum;
            stack.InsertFront(total);
        } else {
             stack.InsertFront(firnum);
             throw emptyList();
        }
    } else {
       throw emptyList();
    }
}

// EFFECTS: performs * operation
void DoMult(Dlist<double> &stack)
{
    if(!stack.IsEmpty()) {
        double firnum = stack.RemoveFront();

        if (!stack.IsEmpty()) {
            double secnum = stack.RemoveFront();
            double total = firnum;
            total = firnum * secnum;
            stack.InsertFront(total);
        } else {
             stack.InsertFront(firnum);
             throw emptyList();
        }
    } else {
       throw emptyList();
    }
}

// EFFECTS: performs / operation
void DoDiv(Dlist<double> &stack)
{
    if(!stack.IsEmpty()) {
        double firnum = stack.RemoveFront();

        if (!stack.IsEmpty()) {
            double secnum = stack.RemoveFront();
            double total = firnum;
            total = secnum / firnum;
            stack.InsertFront(total);
        } else {
             stack.InsertFront(firnum);
             throw emptyList();
        }
    } else {
       throw emptyList();
    }
}

// EFFECTS: performs n operation
void DoNeg(Dlist<double> &stack)
{
  if (!stack.IsEmpty()) {
    double num = stack.RemoveFront();
    double neg = num * -1;
    stack.InsertFront(neg);
  } else {
      throw emptyList();
  }
}

// EFFECTS: performs d operation
void DoDup(Dlist<double> &stack)
{
  if (!stack.IsEmpty()) {
    double num = stack.RemoveFront();
    stack.InsertFront(num);
    stack.InsertFront(num);
  } else {
      throw emptyList();
  }
}

// EFFECTS: performs r operation
void DoRev(Dlist<double> &stack)
{
    if(!stack.IsEmpty()) {
        double firnum = stack.RemoveFront();

        if (!stack.IsEmpty()) {
            double secnum = stack.RemoveFront();
            stack.InsertFront(secnum);
            stack.InsertFront(firnum);
        } else {
             stack.InsertFront(firnum);
             throw emptyList();
        }
    } else {
       throw emptyList();
    }
}

// EFFECTS: performs p operation
void DoPrint(Dlist<double> &stack)
{
  if (!stack.IsEmpty()) {
    double num = stack.RemoveFront();
    std::cout << num << std::endl;
    stack.InsertFront(num);
  } else {
      throw emptyList();
  }
}

// EFFECTS: performs c operation
void DoClear(Dlist<double> &stack)
{
  while (!stack.IsEmpty()) {
    stack.RemoveFront();
  }
  return;
}

// EFFECTS: performs a operation
void DoPrintAll(Dlist<double> &stack)
{
  if (!stack.IsEmpty()) {
    while (stack.IsEmpty()) {
        double num = stack.RemoveFront();
        std::cout << num << " ";
    }
  } else {
     throw emptyList();
  }
  std::cout << std::endl;
}
