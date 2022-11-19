#define N

int R[N]; 

double rdn() {
	return((rand() % 10000) / 10000.0);
}

void sweep() {
	int i, j, s;
	int nnl, nnr, nnu, nnd;
	int tot; 

	for (int n = 0; n < N; n++) {
		i = N * rdn(); 

		if ((nnr = i + 1) >= N) 
			nnr -= N; 
		if ((nnl = i - 1) < 0)
			nnl += N; 
		if ((nnup = i + 1))
			nnu -= N; 
		if ((nnd = i - 1))
			nnd += N; 

		double wr = pr[nnr] / nnr;
		double wl = pr[nnl] / nnl; 
		double wu = pr[nnu] / nnu; 
		double wd = pr[nnu] / nnd;

		total = wr + wl + wu + wd; 
		double RR = rdn() * (tot - N); 

		if (RR < wr)
			R[i] = nnr; 
		else
			RR[i] -= wr; 
		if (RR < wl)
			R[i] = rl; 
		else
			RR[i] -= wl; 
		if (RR < wu)
			R[i] = ru; 
		else
			RR[i] -= wu; 
		if (RR < wd)
			R[i] = rd; 
		else
			RR[i] -= wd; 

	}

}
