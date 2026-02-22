////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                            ***   DATA STRUCTURES  ***                                                                     
//                                                                                                                   
//                            Group Members:                                                                                 //                                                                                                          //
//                            1: Umaima Hashmi   (22i-1984)                                                                 //
//                            2: Nooran Ishtiaq  (22i-2010)                                                                //
//                                                                                                                                        
//                                                    
                     //________________________________________________//
                     //                                                //
                     //         EMERGENCY  TRAVELING PLAN              //
                     //                                                //
                     //------------------------------------------------//
#include <iostream>
#include <climits>
using namespace std;
//--------------------------------------------------------------------------------
//-----------------------------LINKED LIST----------------------------------------
//      node1:                        node2:
//      __________________________    __________________________ 
//      |     data (int)         |    |     data (int)         |
//      |     aerial_root (bool) |    |     aerial_root (bool) |
//      |     node* next---------|--->|     node* next---------|--->NULL
//      --------------------------    --------------------------
class node {
public:
    int data;
    bool aerial_root;
    node* next;
    node() {
        data = 0;
        aerial_root = false;
        next = nullptr;
    }
};
class linkedlist {
public:
    node* head;
    linkedlist() {
        head = new node();
    }
};
//---------------------------------------------------------------------------------------------
//---------------------------------------------QUEUE-------------------------------------------
//               __________________________    __________________________ 
//               |     data (int)         |    |     data (int)         |
//  front -----> |     aerial_root (bool) |    |     aerial_root (bool) |  <------------  rear
//               |     node* next---------|--->|     node* next---------|--->NULL
//               --------------------------    --------------------------
class Queue {
    node* front;
    node* rear;
public:
    Queue(){
        front = NULL;
        rear = NULL;
    }
    // enqueue () Inserts the element at the rear of the queue.
    void enqueue(int value){
        node* newNode = new node;
        newNode->data = value;
        newNode->next = NULL;
        if ((front == NULL) && (rear == NULL)){
            front = newNode;
            rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeue(){
        if (front == NULL){
            cout << "List is empty" << endl;
        }
        else if (front == rear){
            node* p = front;
            front = rear = NULL;
            delete p;
        }
        else{
            node* p = front;
            front = front->next;
            delete p;
        }
    }
    //Front() Returns the value of the element at front of the queue.
    int Front(){
        return front->data;
    }
    //isEmpty () Returns True if the queue is empty else returns False.
    bool isEmpty(){
        if (front == NULL){
            return true;
        }
        else{
            return false;
        }
    }
};
//---------------------------------------------------------------------------------------
//--------------------GRAPH (ADJACENCY LIST IMPLEMENTATION)------------------------------
//          ___________________     ______________________
// arr[0]:  | data=1 (city 1)  |     |  data=2 (city2)    |
//          | aerial_root=false|     | aerial_root=false  |
//          | head pointer-----|-->  |  next pointer------| -->null
//          -------------------     -----------------------     ______________________
// arr[1]:  | data=2 (city 2)  |     |  data=7 (city7)    |     |  data=3 (city3)    |
//          | aerial_root=false|     | aerial_root=true   |     | aerial_root=false  |
//          | head pointer-----|-->  |  next pointer------| --->|  next pointer------| -->null
//          -------------------     -----------------------     ----------------------- 
int roundToInt(double value) {
    return static_cast<int>(value + 0.5);
}
class graph {
public:
    int vertices;
    linkedlist* array;
    graph(int vertex) {
        this->vertices = vertex;
        this->array = new linkedlist[vertices]; //dynamically creation of the array
        for (int i = 0; i < vertices; i++) {    //initializing the value of the array
            array[i].head->data = i + 1;
        }
    }
    void add_edge(int city1, int city2) {
        //edge is from first city1 to the second city2
        //we have directed graph so gonna add in only one direction
        if (city1 > vertices || city2 > vertices) {
            cout << "invalid vertices" << endl;
            return;
        }
        for (int i = 0; i < vertices; i++) {
            if (array[i].head->data == city1) {
                node* new_node = new node;   //creation of new node
                new_node->data = city2;
                //insertion at the start
                new_node->next = array[city1 - 1].head->next; // Store current head's next as new_node's next
                array[city1 - 1].head->next = new_node; // Make new_node the new head
            }
        }
    }
    void add_adjacent_edges() {
        //adding one directed edges between the cities
        for (int i = 0; i < vertices; i++) {
            add_edge(i, i + 1);
        }
    }
    void add_aerial_root(int city1, int city2) {
        //edge is from first city1 to the second city2
        //we have directed graph so gonna add in only one direction
        if (city1 > vertices || city2 > vertices) {
            cout << "invalid vertices" << endl;
            return;
        }
        for (int i = 0; i < vertices; i++) {
            if (array[i].head->data == city1) {
                //creation of new node
                node* new_node = new node;
                new_node->data = city2;
                new_node->aerial_root = true;
                //insertion at the start
                new_node->next = array[city1 - 1].head->next; // Store current head's next as new_node's next
                array[city1 - 1].head->next = new_node; // Make new_node the new head
            }
        }
    }
    void print_aerial_roots() {
        for (int i = 0; i < vertices; i++) {
            cout << array[i].head->data << " is connected with: ";
            node* temp = array[i].head->next;
            while (temp != nullptr) {
                if (temp->aerial_root == true) {
                    cout << temp->data << " ";
                }
                temp = temp->next;
            }
            cout << endl;
        }
    }
    void print_graph() {
        for (int i = 0; i < vertices; i++) {
            cout << array[i].head->data << " is connected with: ";
            node* temp = array[i].head->next;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    //------------------------------------------------------------------
    //-----------Bredth First Traversal
        // ***** Algorithmic steps for breadth-first traversal 
    // 1: Create queue to store city vertices for breadth first traversal 
    // 2: created visitied array to keep track of visited cities
    // 3: Create an array distances to store the shortest distances from the city 1 to each city .
    // 4: enqueue first city vertex and visit all the connected cities and mark it visited
    // 5: While queue is not empty , dequeue first element of queue and mark all the neighbour cities visited
    // 6: if any city is not visited enqueue it and then mark it visited 
    // 7: Update the distance to the neighbor as the sum of the distance to the current city vertex and time in hours.

        //*****Logic for shortest distance 
    // In one day ,user can travel maximum 6 cities in one day  
    // distance to reach from one city vertex to its adjacent city vertex is 4 hours 
    // if there is an aerial root at any city vertex then it will take 24 hours to tavel from one city to another city
    int breadth_first_traversal() {
        const float NORMAL_TIME = 4.0; // Time taken for normal route
        const float AERIAL_TIME = 24.0; // Time taken for aerial route

        float* distances = new float[vertices]; // Store shortest distances
        for (int i = 0; i < vertices; ++i)
            distances[i] = INT_MAX; // Initialize distances to maximum

        Queue q;
        bool* visited = new bool[vertices] { false };
        visited[0] = true;
        distances[0] = 0; // Distance to the starting vertex is 0
        q.enqueue(0); // Starting traversal from vertex 1

        while (!q.isEmpty()) {
            int current = q.Front(); 
            q.dequeue();

            node* temp = array[current].head->next;
            while (temp != nullptr) {
                float time = 0.0;
                //when you find a aerial route
                if (temp->aerial_root == true) { 
                    if (temp->data > current) { time = AERIAL_TIME; }
                }
                else { time = NORMAL_TIME; }
                if (!visited[temp->data-1]) {
                    visited[temp->data-1] = true;
                    distances[temp->data-1] = distances[current] + time;
                    q.enqueue(temp->data-1);
                }
                temp = temp->next;
            }
        }
        int hours = distances[vertices - 1];
        float days = (hours / 24.0);
        days = roundToInt(days);
        return days;
    }
};
int main() {
    int cities;
    int from_city;
    int to_city;
    int no_of_aerial_root;

        cout << "enter the no of test cases: ";
        int test_cases = 0; cin >> test_cases;
        if (test_cases < 0)
        {
            cout << "Invalid input" << endl;
            return 0;
        }
        for (int i = 0; i <test_cases; i++) {
            cout << "Enter the total number of cities:";
            cin >> cities;
            graph g1(cities);
            //**Creation of graph 
            g1.add_adjacent_edges();
            //**Adding aerial roots
            cout << "Enter the number of aerial root :";
            cin >> no_of_aerial_root;
            for (int i = 1; i <= no_of_aerial_root; i++) {
                while (1) {
                    cout << "Enter the aerial root" << i << ":" << endl;
                    cout << "from city:"; cin >> from_city;
                    cout << "to city:";   cin >> to_city;
                    if (((from_city < 0) || (from_city > cities)) || ((to_city < 0) || (to_city > cities)))
                    {
                        cout << "Invalid input " << endl;
                        continue;
                    }
                    break;
                }
                g1.add_aerial_root(from_city, to_city);
            }
            cout << "-----------------------------------------------------------------------" << endl;
            cout <<"shortest distance is: "<< g1.breadth_first_traversal()<<" days" << endl;
            cout << "-----------------------------------------------------------------------" << endl;
            continue;
        }
    return 0;
}