#include <iostream>

using namespace std;
struct Currency {
	int gal, stc, knut;
} a, b;

int main() {
	scanf("%d.%d.%d %d.%d.%d", &a.gal, &a.stc, &a.knut, &b.gal, &b.stc, &b.knut);
	a.gal += b.gal;
	a.stc += b.stc;
	a.knut += b.knut;
	
	a.stc += a.knut / 29;
	a.knut %= 29;
	
	a.gal += a.stc / 17;
	a.stc %= 17;
	
	printf("%d.%d.%d", a.gal, a.stc, a.knut);
	return 0; 
}
