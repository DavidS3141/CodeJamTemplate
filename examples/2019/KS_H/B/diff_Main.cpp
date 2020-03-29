669a670,672
> ll N;
> v(v(bool)) grid;
> 
670a674,684
>     cin >> N;
>     grid.clear();
>     grid.resize(N);
>     forn(i,N){
>         str t;
>         cin >> t;
>         grid[i].resize(N);
>         forn(j,N){
>             grid[i][j] = t[j] == '#';
>         }
>     }
674a689,732
>     ll result_diag = 0;
>     ll result_offdiag = 0;
> 
>     // first diag
>     forn(i, N){
>         if(!grid[i][i]){
>             result_diag++;
>             grid[i][i]=!grid[i][i];
>             ll k = 1;
>             while(i+k<N && i-k>=0){
>                 grid[i+k][i-k]=!grid[i+k][i-k];
>                 grid[i-k][i+k]=!grid[i-k][i+k];
>                 k++;
>             }
>         }
>     }
>     forn(i, (N+1)/2 - 1){
>         if(!grid[0][2*i+2])
>             result_diag++;
>         if(!grid[2*i+2][0])
>             result_diag++;
>     }
>     // now offdiag
>     ll off = N%2;
>     forn(i,N-off){
>         if(!grid[i][N-1-i-off]){
>             result_offdiag++;
>             ll k=max(-i,off+i+1-N);
>             while(i+k<N && k<1+i+off){
>                 grid[i+k][N-1-i-off+k]=!grid[i+k][N-1-i-off+k];
>                 k++;
>             }
>         }
>     }
>     forn(i, N-1){
>         if(!grid[i][i+1])
>             result_offdiag++;
>     }
> 
>     ll n_diag = 2 * N - 1 + (N%2);
>     ll n_offdiag = 2 * N - 1 - (N%2);
>     result_diag = min(result_diag, n_diag - result_diag);
>     result_offdiag = min(result_offdiag, n_offdiag - result_offdiag);
>     result = result_diag + result_offdiag;
