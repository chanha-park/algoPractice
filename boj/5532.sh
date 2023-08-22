read l; read a; read b; read c; read d; e=$(( a / c + (a % c != 0))); f=$(( b / d + (b % d != 0))); echo $(( l - (e > f ? e : f)));
