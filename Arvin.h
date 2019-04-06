// int query(int p ,int t){
//  	if (p > t) return 1;
//  	if (p < t) return -1;
//  	if (p == t) return 0; 	
//  }
int query(int pancake_seq, int tea_seq){
    int p_sugar = pancake_seq;
    int t_sugar = tea_seq+1;
    if(p_sugar>t_sugar)
        return 1;
    if(p_sugar==t_sugar)
        return 0;
    if(p_sugar<t_sugar)
        return -1;
}