#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll MOD = 1000000007;

/* Iterative Function to calculate (x^y) in O(log y) */
ll power(ll x, ll y, ll m = 1)
{
    
    // Initialize answer
    ll res = 1;
     
    // Check till the number becomes zero
    while (y)
    {
         
        // If y is odd, multiply x with result
        if (y % 2 == 1)
        {
            res = (res * x);
            res = res % m;
        }     
        // y = y/2
        y = y >> 1;
         
        // Change x to x^2
        x = (x * x);
        x = x % m;
    }
    return res % m;
}

bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 

ll sumOfGP(ll a, long double r, ll n)
{
    return (a * (power(r, n) - 1) / (r - 1) + 0.000001);
}

ll fact(ll n) 
{ 
    ll res = 1; 
    for (ll i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
} 

ll nCr(ll n, ll r) 
{ 
    return fact(n) / (fact(r) * fact(n - r)); 
}

// this will store the binary number in an array and then print.
void decToBinary(ll n)   
{ 
    // array to store binary number 
    ll binaryNum[64] = {0}; 
  
    // counter for binary array 
    ll i = 0; 
    while (n > 0) { 
  
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
  
    // printing binary array in reverse order 
    for (ll j = i - 1; j >= 0; j--) 
        cout << binaryNum[j]; 
} 

//this can sort 2d VECTOR based on column where compleete row moves together
bool sortcol( const vector<ll>& v1, const vector<ll>& v2 ) { 
 return v1[1] < v2[1]; 
} 

// Function to check if x is power of 2
bool isPowerOfTwo(ll n)
{
    // edge case
    // check for n = 1

    if (n == 0)
        return false;

    return (ceil(log2(n)) == floor(log2(n)));
}


// fibonacci series
ll fib[1000000];
void fib_ ()
{
    ll i, n = 1000000;
    fib[0] = 0;
    fib[1] = 1;
    for (i = 2; i < n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

  
// Function to find modular inverse of a under modulo m 
// Assumption: m is prime 
ll modInverse(ll a, ll m) 
{ 

    
        // If a and m are relatively prime, then 
        // modulo inverse is a^(m-2) mode m 
        return power(a, m - 2, m);  
} // To compute x^y under modulo m 
ll power(ll x, ll y, ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y / 2, m) % m; 
    p = (p * p) % m; 
  
    return (y % 2 == 0) ? p : (x * p) % m; 
}

// this will take input two strings and multiply them return the answer as a string
string multiply(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
    return "0";
 
    // will keep the result number in vector
    // in reverse order
    vector<int> result(len1 + len2, 0);
 
    // Below two indexes are used to find positions
    // in result.
    int i_n1 = 0;
    int i_n2 = 0;
     
    // Go from right to left in num1
    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
 
        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0;
         
        // Go from right to left in num2            
        for (int j=len2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';
 
            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position.
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
 
            // Carry for next iteration
            carry = sum/10;
 
            // Store result
            result[i_n1 + i_n2] = sum % 10;
 
            i_n2++;
        }
 
        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
 
        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }
 
    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;
 
    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
    return "0";
 
    // generate the result string
    string s = "";
     
    while (i >= 0)
        s += std::to_string(result[i--]);
 
    return s;
}

// A iterative binary search function. It returns
// location of x in given array arr[l..r] if present,
// otherwise -1
ll binarySearch(ll arr[], ll l, ll r, ll x)
{
    r--;
    while (l <= r) {
        ll m = l + (r - l) / 2;
 
        // Check if x is present at mid
        if (arr[m] == x)
            return m;
 
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // if we reach here, then element was
    // not present
    return -1;
}


// Graph class represents a undirected graph
// using adjacency list representation
class Graph {
    // No. of vertices
    int V;
 
    // Pointer to an array containing adjacency lists
    list<int>* adj;
 
    // A function used by DFS
    void DFSUtil(int v, bool visited[])
    {
        // Mark the current node as visited
        visited[v] = true;
    
        // Recur for all the vertices
        // adjacent to this vertex
        list<int>::iterator i;
        // cout << v << endl;
        for (i = adj[v].begin(); i != adj[v].end(); ++i) {
            
            if (!visited[*i]) {
                DFSUtil(*i, visited);
            }
        }
    }

public:
    // Constructor
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    // Add an undirected edge
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    // Function to return the number of
    // connected components in an undirected graph
    int NumberOfconnectedComponents()
    {
        // Mark all the vertices as not visited
        bool* visited = new bool[V];
    
        // To store the number of connected components
        int count = 0;
        for (int v = 0; v < V; v++)
            visited[v] = false;
    
        for (int v = 0; v < V; v++) {
            if (visited[v] == false) {
                DFSUtil(v, visited);
                count += 1;
            }
        }
        return count;
    }

    void removeEdge(int v, int w) 
    {
        if (*adj[v].end() == w)
        {
            adj[v].pop_back();
        }
        if (*adj[w].end() == v)
        {
            adj[w].pop_back();
        }
        if (adj[v].front() == w)
        {
            adj[v].pop_front();
        }
        if (adj[w].front() == v)
        {
            adj[w].pop_front();
        }
    }
};
 
 
int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n,i;
        cin >> n;
        
        cout << endl;
    }
}