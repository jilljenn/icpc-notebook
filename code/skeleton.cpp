#include <bits/stdc++.h>
using namespace std;

struct Struct {};
const int constant = 0;
int variable;

// pour eviter les conflits de notation entre codes du notebook
namespace notebook
{

struct Struct {};
const int constant = 0;
int variable;
void function() {}

};

void function() {}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> variable;
	printf("%d\n", notebook::variable);
}
