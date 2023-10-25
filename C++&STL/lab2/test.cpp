void recursiveFunction(int i, int m, int n, std::unique_ptr<licznik[]> &Counter){
    if(m == 0) return;
    for(int j = 0; j < n; j++){
        if(rand() % 2 == 0)
            Counter[j].count += i;
    }
    rec_inc(i+1, m-1, n, Counter);
}