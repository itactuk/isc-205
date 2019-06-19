
int suma_rec_pos(int n){
    if (n==0){
        return 0;
    }
    if (n%2){
        return  suma_rec_pos(n-1);
    } else{
        return  n + suma_rec_pos(n-1);
    }
}

// suma_rec_pos2 es una funcion más abreviada que suma_rec_pos
int suma_rec_pos2(int n){
    if (n==0){
        return 0;
    }
    return  (n%2?0:n) + suma_rec_pos2(n-1);
}

int suma_rec_pos_a(int n, int i){
    if (i>n){
        return 0;
    }
    if (i%2){
        return suma_rec_pos_a(n, i+1);
    }else{
        return i+suma_rec_pos_a(n, i+1);
    }
}


int suma_rec_pos_mejor(int n){
    if (n<=0){
        return 0;
    }
    if (n%2){
        return  suma_rec_pos_mejor(n-1);
    } else{
        return  n + suma_rec_pos_mejor(n-2);
    }
}