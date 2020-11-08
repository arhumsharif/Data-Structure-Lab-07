#include<iostream>
using namespace std;
const int s = 5;
class node
{
public:
	int data;
	node* right;
	node* left;
	node()
	{
		data = 0;
		right = NULL;
		left = NULL;
	}
};
class Binary_Search_Tree
{
public:
	node* root;
	int check;
	int count;
	Binary_Search_Tree()
	{
		root = NULL;
		check = 0;
		count = 0;
	}
	node* get_root()
	{
		return root;
	}
	int get_check()
	{
		return check;
	}
	void set_count()
	{
		count = 0;
	}
	int counter()
	{
		return count;
	}
	void insertion(int val)
	{
		node* ptr = new node;
		ptr->data = val;
		if (root == NULL)
		{
			root = ptr;
			cout << " Node Inserted on Root " << endl;
			return;
		}
		else
		{
			node* temp = root;
			while (temp != NULL)
			{
				if (temp->data == ptr->data)
				{
					cout << " This Data already Exists! " << endl;
					return;
				}
				else if (ptr->data < temp->data && temp->left == NULL)
				{
					temp->left = ptr;
					cout << " Node inserted to the Left! " << endl;
					return;
				}
				else if (ptr->data < temp->data)
				{
					temp = temp->left;
				}
				else if (ptr->data > temp->data && temp->right == NULL)
				{
					temp->right = ptr;
					cout << " Node inserted to the Right! " << endl;
					return;
				}
				else if (ptr->data > temp->data)
				{
					temp = temp->right;
				}
			}
		}
	}
	node* Search(int num)
	{
		int count = 0;
		if (root == NULL)
		{
			cout << " Tree is Empty " << endl;
			return NULL;
		}
		else
		{
			node* temp = root;
			node* ptr = NULL;
			while (temp != NULL)
			{
				if (temp->data == num)
				{
					ptr = temp;
					return ptr;
				}
				else if (num < temp->data)
				{
					temp = temp->left;
				}
				else if (num > temp->data)
				{
					temp = temp->right;
				}
			}
			if (ptr == NULL)
			{
				return ptr;
			}
		}
	}
	void Display(node* r, int space)
	{
		if (r == NULL)
		{
			return;
		}
		space = space + s;
		Display(r->right, space);
		cout << endl;
		for (int i = s; i < space; i++)
		{
			cout << " ";
		}
		cout << r->data << endl;
		Display(r->left, space);
	}
	void Height(node* r)
	{
		if (r == NULL)
		{
			return;
		}
		Height(r->right);
		count++;
		Height(r->left);
	}
	void Number_of_Nodes(node* r)
	{
		if (r == NULL)
		{
			return;
		}
		Number_of_Nodes(r->right);
		count++;
		Number_of_Nodes(r->left);
	}
	void IsLeaf(node* r)
	{
		if (r == NULL)
		{
			cout << " Data is Not on Tree , Try Again! " << endl;
			return;
		}
		else
		{
			if (r->left == NULL && r->right == NULL)
			{
				cout <<r->data<< " is a Leaf Node " << endl;
			}
		}
	}
	void IsNonLeaf(node* r)
	{
		if (r == NULL)
		{
			cout << " Data is Not on Tree , Try Again! " << endl;
			return;
		}
		else
		{
			if (r->left != NULL || r->right != NULL || (r->left != NULL && r->right != NULL))
			{
				cout <<r->data<< " is a Non Leaf Node " << endl;
			}
		}
	}
	void IsParent(node* p, node* c)
	{
		if (p == NULL || c == NULL)
		{
			cout << "One of the Nodes Does Not Exist! " << endl;
			return;
		}
		else
		{
			if (p->left == c || p->right == c)
			{
				cout << p->data << " is the Parent of " << c->data << " Node " << endl;
			}
			else
			{
				cout << p->data << " is not the Parent of " << c->data << " Node " << endl;
			}
		}
	}
	void IsChild(node* c, node* p)
	{
		if (p == NULL || c == NULL)
		{
			cout << "One of the Nodes Does Not Exist! " << endl;
			return;
		}
		else
		{
			if (p->left == c || p->right == c)
			{
				cout << c->data << " is the Child of " << p->data << " Node " << endl;
			}
			else
			{
				cout << c->data << " is not the Child of " << p->data << " Node " << endl;
			}
		}
	}
	void IsDescendent(node* r, node* d)
	{
		if (r == NULL)
		{
			return;
		}
		IsDescendent(r->left, d);
		if (r->left == d || r->right == d)
		{
			count++;
			return;
		}
		IsDescendent(r->right, d);
	}
	void IsSuccessor(node* d, node* r)
	{
		if (r == NULL)
		{
			return;
		}
		IsSuccessor(d, r->left);
		if (r->left == d || r->right == d)
		{
			count++;
			return;
		}
		IsSuccessor(d,r->right);
	}
	int Degree(node* r)
	{
		int count1 = -1;
		if (r == NULL)
		{
			cout << " Node Does Not Exist " << endl;
			return 0;
		}
		if (r->right == NULL && r->left == NULL)
		{
			count1 = 0;
		}
		else if (r->right != NULL && r->left == NULL || r->right == NULL && r->left != NULL)
		{
			count1 = 1;
		}
		else
		{
			count1 = 2;
		}
		return count1;
	}
	void IsSibling(node* r,node* s1,node* s2)
	{
		if (r == NULL)
		{
			return;
		}
		IsSibling(r->left, s1, s2);
		if (r->left == s1 && r->right == s2 || r->left == s2 && r->right == s1)
		{
			count++;
		}
		IsSibling(r->right, s1, s2);
	}
	void LeafNodeCount(node* r)
	{
		if (r == NULL)
		{
			return;
		}
		LeafNodeCount(r->left);
		if (r->left == NULL && r->right == NULL)
		{
			count++;
		}
		LeafNodeCount(r->right);
	}
	void InternalNodesCount(node* r)
	{
		if (r == NULL)
		{
			return;
		}
		count++;
		InternalNodesCount(r->left);
		if (r->left == NULL && r->right == NULL)
		{
			count--;
		}
		InternalNodesCount(r->right);
	}
	void Level(int d)
	{
		if (root == NULL)
		{
			cout << "Tree is Empty " << endl;
			return;
		}
		else
		{
			node* temp = root;
			while (temp!=NULL)
			{
				if (temp->data == d)
				{
					cout << "Level of " << d << " Node is: " << count;
					return;
				}
				count++;
				if (d < temp->data)
				{
					temp = temp->left;
				}
				else if (d > temp->data)
				{
					temp = temp->right;
				}
			}
		}

	}
};
int main()
{
	int val;
	int d1, d2;
	Binary_Search_Tree t1;
	int a = 0;
	int space = 5;
	int choice;
	while (a != -1)
	{
		cout << "1. Insertion " << endl;
		cout << "2. Display " << endl;
		cout << "3. Height " << endl;
		cout << "4. Total Number of Nodes " << endl;
		cout << "5. IsParent " << endl;
		cout << "6. IsChild " << endl;
		cout << "7. IsLeaf " << endl;
		cout << "8. IsNonLeaf " << endl;
		cout << "9. IsDescendent " << endl;
		cout << "10. IsSuccessor " << endl;
		cout << "11. Degree of a Node " << endl;
		cout << "12. IsSibling " << endl;
		cout << "13. LeafNodeCount " << endl;
		cout << "14. InternalNodeCount " << endl;
		cout << "15. level of a Node " << endl;
		cout << "Enter: ";
		cin >> choice;
		if (choice == 1)
		{
			cout << "Enter the Value: ";
			cin >> val;
			t1.insertion(val);
		}
		else if (choice == 2)
		{
			t1.Display(t1.get_root(),space);
		}
		else if (choice == 3)
		{
			t1.set_count();
		    t1.Height(t1.get_root());
			cout << "Height of BST is: " << t1.counter() - 1 << endl;
		}
		else if (choice == 4)
		{
			t1.set_count();
			t1.Number_of_Nodes(t1.get_root());
			cout << " Total Number of Nodes are: " << t1.counter() << endl;
		}
		else if (choice == 5)
		{
			cout << " Enter the 1st Node You want to represent Parent: ";
			cin >> d1;
			cout << " Enter the 2nd Node You want to represent Child: ";
			cin >> d2;
			t1.IsParent(t1.Search(d1), t1.Search(d2));
		}
		else if (choice == 6)
		{
			cout << " Enter the 1st Node You want to represent Child: ";
			cin >> d1;
			cout << " Enter the 2nd Node You want to represent Parent: ";
			cin >> d2;
			t1.IsChild(t1.Search(d1), t1.Search(d2));
		}
		else if (choice == 7)
		{
			cout << "Enter the Data: ";
			cin >> val;
			t1.IsLeaf(t1.Search(val));
		}
		else if (choice == 8)
		{
			cout << "Enter the Data: ";
			cin >> val;
			t1.IsNonLeaf(t1.Search(val));
		}
		else if (choice == 9)
		{
			t1.set_count();
			cout << "Enter the Data You want to Represent as Descendent: ";
			cin >> d1;
			cout << "Enter the Data You want to Represent as Successor: ";
			cin >> d2;
			if (t1.Search(d1) == NULL || t1.Search(d2) == NULL || (t1.Search(d1) == NULL && t1.Search(d2) == NULL))
			{
				cout << " No Nodes with this data on Tree " << endl;
				return 0;
			}
			else
			{
				t1.IsDescendent(t1.Search(d1), t1.Search(d2));
			}

			if (t1.counter() == 0)
			{
				cout << d1 << " is not the Descendent of " << d2 << endl;
			}
			else
			{
				cout << d1 << " is the Descendent of " << d2 << endl;
			}
		}
		else if (choice == 10)
		{
			t1.set_count();
			cout << "Enter the Data You want to Represent as Successor: ";
			cin >> d1;
			cout << "Enter the Data You want to Represent as Descendent: ";
			cin >> d2;
			if (t1.Search(d1) == NULL || t1.Search(d2) == NULL || (t1.Search(d1) == NULL && t1.Search(d2) == NULL))
			{
				cout << " No Nodes with this data on Tree " << endl;
				return 0;
			}
			else
			{
				t1.IsSuccessor(t1.Search(d1), t1.Search(d2));
			}

			if (t1.counter() == 0)
			{
				cout << d1 << " is not the Successor of " << d2 << endl;
			}
			else
			{
				cout << d1 << " is the Successor of " << d2 << endl;
			}
		}
		else if (choice == 11)
		{
			cout << " Enter the data You want to Know Degree of? :";
			cin >> val;
			cout << endl;
			if (t1.Search(val) == NULL)
			{
				cout << endl << " Node is Not in Tree " << endl;
			}
			else
			{
				cout << "Degree of " << val << " Node is: " << t1.Degree(t1.Search(val));
			}
		}
		else if (choice == 12)
		{
			t1.set_count();
			cout << "Enter the Data You want to Represent 1st Sibling: ";
			cin >> d1;
			cout << "Enter the Data You want to Represent 2nd Sibling: ";
			cin >> d2;
			if (t1.Search(d1) == NULL || t1.Search(d2) == NULL)
			{
				cout << " One of Node Does Not Exist in Tree " << endl;
				return 0;
			}
			else
			{
				t1.IsSibling(t1.get_root(), t1.Search(d1), t1.Search(d2));
			}

			if (t1.counter() > 0)
			{
				cout << d1 << " is Sibling of " << d2 << endl;
			}
			else
			{
				cout << d1 << " is Not the Sibling of " << d2 << endl;
			}
		}
		else if (choice == 13)
		{
			t1.set_count();
			t1.LeafNodeCount(t1.get_root());
			cout << "Number of Leaf Nodes are: " << t1.counter();
		}
		else if (choice == 14)
		{
			t1.set_count();
			t1.InternalNodesCount(t1.get_root());
			cout << "Number of Internal Nodes are: " << t1.counter();
		}
		else if (choice == 15)
		{
			cout << " Enter the Data You want to know the Level of? : ";
			cin >> val;
			if (t1.Search(val) == NULL)
			{
				cout << "Node does not Exist in Tree " << endl;
			}
			else
			{
				t1.set_count();
				t1.Level(val);
			}
		}
		else
		{
			cout << "Invalid Choice " << endl;
		}
		cout <<endl<<endl<< "Enter -1 to Quit: ";
		cin >> a;
	}
	return 0;
}