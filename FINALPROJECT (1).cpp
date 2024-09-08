#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;

class Graph
{
public:
	//part1: constructor initializes adjacency matrix
	Graph(int numVertex)
	{
		numVertices = numVertex;
		adj_matrix = new int* [numVertex];
		for (int i = 0; i < numVertex; i++)
		{
			adj_matrix[i] = new int[numVertex];
		}
		for (int i = 0; i < numVertex; i++)
		{
			for (int j = 0; j < numVertex; j++)
			{
				adj_matrix[i][j] = 0;
			}
		}
	}
	//part2: returns the number of vertices in the graph
	int GetNumVertices()
	{
		return numVertices;
	}
	//part3: returns the number of edges in the graph
	int numberOfEdges()
	{
		int sum = 0;
		for (int i = 0; i < numVertices; i++)
		{
			for (int j = 0; j < numVertices; j++)
			{
				sum = adj_matrix[i][j] + sum;
			}
		}
		return sum/2;
	}
	//part4: inserts edge going from one vertex to another
	void insertEdge(int frmVertex, int toVertex, int wieght)
	{
		adj_matrix[frmVertex][toVertex] = wieght;
	}
	//part5: removes edge going from one vertex to another
	void removeEdge(int frmVertex, int toVertex)
	{
		adj_matrix[frmVertex][toVertex] = 0;
	}
	//part6: returns the degree of the node passed
	int degree(int vertex)
	{
		int sum = 0;
		for (int i = 0; i < numVertices; i++)
		{
			sum = sum + adj_matrix[vertex][i];
		}
		return sum;
	}
	//part7: outputs the order in which vertices are visited during DFS
	//Starting from node s.
	void depthfirstSearch(int s, int t)
	{
		bool* visited = new bool[numVertices];
		for (int i = 0; i < numVertices; i++)
		{
			visited[i] = false;
		}
		stack<int>st;
		st.push(s);
		while (!st.empty())
		{
			int visiting = st.top();
			st.pop();
			if (!visited[visiting])
			{
				visited[visiting] = true;
				cout << char(visiting + 65) << "->";
				if (visiting == t)
					break;
			}
			for (int i = numVertices - 1; i >= 0; i--)
			{
				if (adj_matrix[visiting][i] >= 1)
				{
					if (!visited[i])
					{
						st.push(i);
					}
				}
			}
		}
	}
	//part8: outputs the order in which vertices are visited during BFS
	//Starting from node s.
	void breadthfirstSearch(int s,int t)
	{
		bool* visited = new bool[numVertices];
		for (int i = 0; i < numVertices; i++)
		{
			visited[i] = false;
		}
		queue<int>q;
		visited[s] = true;
		q.push(s);
		while (!q.empty())
		{
			int visiting = q.front();
			q.pop();
			cout << char(visiting+65) << "->";
			if (visiting == t)
				break;
			for (int i = 0; i < numVertices; i++)
			{
				if (adj_matrix[visiting][i] >= 1)
				{
					if (!visited[i])
					{
						q.push(i);
						visited[i] = true;
					}
				}
			}
		}
	}
	int minimum(int* status, int* dis, int n) {
		int i, min, index=0;
		min = 0;

		for (i = 0; i < n; i++)
			if (dis[i] < min && status[i] == 1) {
				min = dis[i];
				index = i;
			}

		if (status[index] == 1)
			return index; //minimum unconsidered vertex distance
		else
			return -1;    //when all vertices considered
	}
	void dijkstra(int n, int s) {
		int status[16];
		int u, v;
		int dist[16];
		int next[16];
		//initialization
		for (u = 0; u < n; u++) {
			status[u] = 1;               //unconsidered vertex
			dist[u] = adj_matrix[u][s];     //distance from source
			next[u] = s;
		}

		//for source vertex
		status[s] = 2; dist[s] = 0; next[s] = -1; //-1 for starting vertex

		while ((u = minimum(status, dist[], n)) > -1) {
			status[u] = 2;//now considered
			for (v = 0; v < n; v++)
				if (status[v] == 1)
					if (dist[v] > dist[u] + adj_matrix[u][v]) {
						dist[v] = dist[u] + adj_matrix[u][v];   //update distance
						next[v] = u;
					}
		}
		for (int i = 0 ; i<16 ; i++)
		{
			cout <<dist[i]<<" ";
		}
	}
private:
	int** adj_matrix;
	int numVertices;
};
//SUBCLASS 1
class Continental
{
private:
	string c1;
	string c2;
	string c3;
	string c4;

public:
	int total_continental = 0;
	Continental()
	{
		c1 = "1) Continental Fish";
		c2 = "2) Continental Meat";
		c3 = "3) Continental Eggs";
		c4 = "4) Continental Fruits";
		total_continental = 0;
	}
	void ConInput() {
		cout << "Available Continental Dishes : \n\n" << c1 << endl << c2 << endl << c3 << endl << c4 << endl << endl;
		cout << "No. Of CONTINENTAL Dishes You Want ? ";
		cin >> total_continental;
		cout << endl;
	}
};
//SUBCLASS 2
class Chinese
{
private:
	string c1;
	string c2;
	string c3;
	string c4;
public:
	int total_Chinese = 0;
	Chinese()
	{
		c1 = "1) Chinese Fish";
		c2 = "2) Chinese Meat";
		c3 = "3) Chinese Eggs";
		c4 = "4) Chinese Fruits";
		total_Chinese = 0;
	}
	void ChinInput()
	{
		cout << "Available Chinese Dishes : \n\n" << c1 << endl << c2 << endl << c3 << endl << c4 << endl << endl;
		cout << "No. Of CHINESE Dishes You Want ? ";
		cin >> total_Chinese;
		cout << endl;
	}
};
//SUBCLASS 3
class Thai
{
private:
	string c1;
	string c2;
	string c3;
	string c4;
public:
	int total_Thai = 0;
	Thai()
	{
		c1 = "1) Thai Fish";
		c2 = "2) Thai Meat";
		c3 = "3) Thai Eggs";
		c4 = "4) Thai Fruits";
		total_Thai = 0;
	}
	void ThInput()
	{
		cout << "Available Thai Dishes : \n\n" << c1 << endl << c2 << endl << c3 << endl << c4 << endl << endl;
		cout << "No. Of THAI Dishes You Want ? ";
		cin >> total_Thai;
		cout << endl;
	}
};
//SUBCLASS 4
class Italian
{
private:
	string c1;
	string c2;
	string c3;
	string c4;
public:
	int total_Italian = 0;
	Italian()
	{
		c1 = "1) Italian Fish";
		c2 = "2) Italian Meat";
		c3 = "3) Italian Eggs";
		c4 = "4) Italian Fruits";
		total_Italian = 0;
	}
	void ItaInput() 
	{
		cout << "Available Italian Dishes : \n\n" << c1 << endl << c2 << endl << c3 << endl << c4 << endl << endl;
		cout << "No. Of ITALIAN Dishes You Want ? ";
		cin >> total_Italian;
		cout << endl;
	}
};
//SUBCLASS 5
class Indian
{
private:
	string c1;
	string c2;
	string c3;
	string c4;
public:
	int total_Indian = 0;
	Indian()
	{
		c1 = "1) Indian Fish";
		c2 = "2) Indian Meat";
		c3 = "3) Indian Eggs";
		c4 = "4) Indian Fruits";
		total_Indian = 0;
	}
	void IndInput()
	{
		cout << "Available Indian Dishes : \n\n" << c1 << endl << c2 << endl << c3 << endl << c4 << endl << endl;
		cout << "No. Of INDIAN Dishes You Want ? ";
		cin >> total_Indian;
		cout << endl;
	}
};
//MAIN CLASS
class Order 
{
public:
	string name;
	char address;
	string phone_number;
	string email;
	int choice; int order_no = 0; int total_time;

	Continental* con;
	Chinese* chi;
	Thai* tha;
	Italian* ital;
	Indian* ind;

	int cont_time = 20;
	int chin_time = 25;
	int thai_time = 30;
	int ital_time = 25;
	int indi_time = 15;
	Order()
	{
		name = " ";
		address = ' ';
		phone_number = " ";
		email = " ";
	}
	void Display()
	{
		cout << endl << "----------" << order_no << "----------" << endl;
		cout << "NAME -> " << name << endl;
		cout << "ADDRESS -> " << address << endl;
		cout << "PHONE NO. -> " << phone_number << endl;
		cout << "EMAIL -> " << email << endl;
		cout << "--------------------------------------" << endl;
		if (total_continental_dishes() != 0)
			cout << "CONTINENTAL DISHES -> " << total_continental_dishes() << endl;
		if (total_Chinese_dishes() != 0)
			cout << "CHINESE DISHES -> " << total_Chinese_dishes() << endl;
		if (total_Thai_dishes() != 0)
			cout << "THAI DISHES -> " << total_Thai_dishes() << endl;
		if (total_Italian_dishes() != 0)
			cout << "ITALIAN DISHES -> " << total_Italian_dishes() << endl;
		if (total_Indian_dishes() != 0)
			cout << "INDIAN DISHES -> " << total_Indian_dishes() << endl << endl;
		cout << "--------------------------------------";
	}
	void Input(queue<Order*> que)
	{
		char ichoice;
		con = new Continental(); chi = new Chinese(); tha = new Thai();	ital = new Italian(); ind = new Indian();
		cout << endl;
		cout << "ENTER NAME : ";
		cin >> name;
		cout << endl;
		cout << "ENTER ADDRESS : ";
		cin >> address;
		cout << endl;
		cout << "ENTER PHONE NO. : ";
		cin >> phone_number;
		cout << endl;
		cout << "ENTER EMAIL : ";
		cin >> email;
		cout << endl;
		system ("cls");
		for (int i = 0;;)
		{
			cout << "		CATEGORIES\n" << endl;
			cout << "	-----------------------\n";
			cout << "	1) CONTINENTAL" << endl << "	2) CHINESE" << endl << "	3) THAI" << endl << "	4) ITALIAN" << endl << "	5) INDIAN\n" << endl;
			cout << " CHOOSE DESIRED CATEGORY FROM ABOVE -> ";
			cin >> choice;
			if (choice == 1)
			{
				cout << endl;
				con->ConInput();
				total_time = total_time + cont_time;
			}
			if (choice == 2)
			{
				cout << endl;
				chi->ChinInput();
				total_time = total_time + chin_time;
			}
			if (choice == 3)
			{
				cout << endl;
				tha->ThInput();
				total_time = total_time + thai_time;
			}
			if (choice == 4)
			{
				cout << endl;
				ital->ItaInput();
				total_time = total_time + ital_time;
			}
			if (choice == 5)
			{
				cout << endl;
				ind->IndInput();
				total_time = total_time + indi_time;
			}
			cout << " DO YOU WANT TO ORDER MORE FOOD ? [ Y / N ]";
			cin >> ichoice;
			if (ichoice == 'n' || ichoice == 'N')
				break;
		}
	    order_no = que.size() + 101;
	    //total_time = total_continental_dishes() * cont_time + total_Chinese_dishes() * chin_time + total_Thai_dishes() * thai_time + total_Italian_dishes() * ital_time + total_Indian_dishes() * indi_time;
		cout << "\n	THANK YOU FOR YOUR ORDER, ORDER NO. -> (" << order_no << ")" ;
		cout << "\n	TOTAL TIME FOR THIS ORDER -> " << order_no << " IS : " << total_time << " MINUTES ! " << endl;;
		
	}
	int total_continental_dishes()
	{
		return con->total_continental;
	}
	int total_Chinese_dishes()
	{
		return chi->total_Chinese;
	}
	int total_Thai_dishes()
	{
		return tha->total_Thai;
	}
	int total_Italian_dishes()
	{
		return ital->total_Italian;
	}
	int total_Indian_dishes()
	{
		return ind->total_Indian;
	}
};
int main() 
{
	Graph* g = new Graph(16);
	int temp;
				ifstream fin;
				fin.open("GraphR.txt");
				if (fin)
				{
					for (int i = 0; i < 16; i++)
					{
						for (int j = 0; j < 16; j++)
						{
							fin >> temp;
							g->insertEdge(i, j, temp);
						}
					}
				}

				int start = 7;
			g->dijkstra(3, start);


	queue<Order*> que;  
	int count = 0; char opt, optdisplay;
	int chefs = 4, riders = 4;

	cout << "\n AVAILABLE CHEFS -> " << chefs << endl;
	for (int i = 0;;)
	{
		Order* r = new Order();
		cout << "\nDO YOU WANT TO ORDER ? [ Y / N ] : ";
		cin >> opt;
		cout << endl;
		if (opt == 'y' || opt == 'Y')
		{
			if (chefs > 0)
			{
				r->Input(que);
				que.push(r);
				count++;
				chefs--;
				cout << "	REMAINING CHEFS -> " << chefs << endl;
				cout << "	AVAILABLE RIDERS : " << riders << endl;
				riders--;
				cout << "	RIDER IS ASSIGNED SUCCESFULLY,  REMAINING RIDERS : " << riders << endl;
				cout << "	ORDERS PRESENT IN QUEUE : " << count << endl;
			}
			else
			{
				cout << "FIRST DISPATCH OTHER ORDERS THAN START PREPARING !!!";
			}
		}
		if (opt == 'n' || opt == 'N')
		{
			cout << "DO YOU WANT TO SEE DISPATCHING ORDERS ? [ Y / N ]";
			cin >> optdisplay;
			cout << endl;
			if (optdisplay == 'y' || optdisplay == 'Y')
			{
				system("cls");
				while (!que.empty())
				{
					que.front()->Display();
					cout << "\nBEFORE DISPATCH AVAILABLE CHEFS -> " << chefs << endl;
					cout << "--------------------------------------" << endl;
					cout << "ORDER **" << que.front()->order_no << "** HAS BEEN DISPATCHED WITHIN " << que.front()->total_time << " MINUTES !! " << endl;
					int x = char(que.front()->address);
					chefs++;
					cout << "--------------------------------------";
					cout << "\nAFTER PREPARING FOOD AVAILABLE CHEFS -> " << chefs << endl;
					cout << "--------------------------------------" << endl;
					cout << "     DESIRED LOCATION : H->" << char(x) << endl;
					cout << "1st ALTERNATE PATH FOR RIDER :  "; g->depthfirstSearch(7, x - 65); cout << endl;
					cout << "2nd ALTERNATE PATH FOR RIDER :  "; g->breadthfirstSearch(7, x - 65); cout << endl;
					cout << "--------------------------------------" << endl;
					cout << "ORDER DELIVERED SUCCESFULLY !!! ";
					que.pop();
					riders++;
					cout << "NOW AVAILABLE RIDERS : " << riders << endl;
					cout << "--------------------------------------" << endl << endl;
				}
			}
			if (optdisplay == 'n' || optdisplay == 'N')
			{
				break;
			}
		}
	}
	return 0;
}
