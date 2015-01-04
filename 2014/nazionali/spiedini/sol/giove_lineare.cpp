#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

int solve(int N, int K, int* s) {

	// printf("N=%d, K=%d\n", N, K);

	int meglio = 0;

	int somma = 0;
	int cont = 0;	// escluso
	int zeri = 0;
	while ( ( cont < N-1 ) && ( somma + s[cont] <= K ) ) {
		somma += s[cont];
		if ( s[cont] == 0 ) zeri++;
		cont++;
	}

	meglio = zeri;

	int dcont = N-1;	// escluso
	for (; cont >= 0; cont--) {
		while ( ( dcont >= cont ) && ( somma + s[dcont] <= K ) ) {
			// printf("--- cont=%d, dcont=%d, somma + s[dcont] = %d\n", cont, dcont, somma+s[dcont]);
			somma += s[dcont];
			if ( s[dcont] == 0 ) zeri++;
			dcont--;
		}

		// printf("cont=%d, dcont=%d, somma=%d, zeri=%d\n", cont, dcont, somma, zeri);

		meglio = max( meglio, zeri );

		somma -= s[cont-1];
		if ( s[cont] == 0 ) zeri--;
	}

	return meglio;
}

