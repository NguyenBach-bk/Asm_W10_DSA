#include <iostream>

// Khai bao cau truc node
struct Node
{
  int data;
  Node *next;
};

// Ham tao node moi
Node *
make_node (int x)
{
  Node *p = new Node ();
  p->data = x;
  p->next = nullptr;
  return p;
}

// Ham them node vao cuoi danh sach
void
add_node (Node *&head, int x)
{
  Node *new_node = make_node (x);
  if (head == nullptr)
    {
      head = new_node;
    }
  else
    {
      Node *temp = head;
      while (temp->next != nullptr)
        {
          temp = temp->next;
        }
      temp->next = new_node;
    }
}

// Ham in danh sach
void
print_list (Node *node)
{
  Node *p = node;
  std::cout << "\nDanh sach: ";
  while (p != nullptr)
    {
      std::cout << p->data << " ";
      p = p->next;
    }
}

// Ham xoa phan tu dau tien
Node *
del_first (Node *node)
{
  if (node == nullptr)
    {
      std::cout << "\nDanh sach rong!";
      return nullptr;
    }
  Node *p = node;
  node = node->next;
  delete p;
  return node;
}

// Ham xoa phan tu cuoi cung
Node *
del_last (Node *node)
{
  if (node == nullptr)
    {
      std::cout << "\nDanh sach rong!";
      return nullptr;
    }

  if (node->next == nullptr)
    {
      delete node;
      return nullptr;
    }

  Node *p = node;
  while (p->next->next != nullptr)
    {
      p = p->next;
    }
  delete p->next;
  p->next = nullptr;
  return node;
}

// Ham xoa sau node q
Node *
del_after (Node *node, int x)
{
  if (node == nullptr)
    {
      std::cout << "\nDanh sach rong!";
      return nullptr;
    }

  Node *p = node;
  while (p != nullptr && p->data != x)
    {
      p = p->next;
    }

  if (p == nullptr || p->next == nullptr)
    {
      std::cout << "\nKhong tim thay node can xoa hoac khong co node sau!";
      return node;
    }

  Node *q = p->next;
  p->next = q->next;
  delete q;
  return node;
}

int
main ()
{
  Node *node = nullptr;

  add_node (node, 5);
  add_node (node, 10);
  add_node (node, 15);
  add_node (node, 20);
  add_node (node, 25);

  print_list (node);

  std::cout << "\n\nXoa dau:";
  node = del_first (node);
  print_list (node);

  std::cout << "\n\nXoa cuoi:";
  node = del_last (node);
  print_list (node);

  std::cout << "\n\nXoa sau node co gia tri 15:";
  node = del_after (node, 15);
  print_list (node);

  std::cout << "\n";
  return 0;
}
