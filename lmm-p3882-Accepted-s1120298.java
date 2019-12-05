import java.util.*;

public class Freckles {

    static int padre[] = new int[2005];

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        int n = leer.nextInt(), l = leer.nextInt(), x, y, dist, pos;
        long suma = Long.MAX_VALUE;
        int ini = leer.nextInt(), fin = leer.nextInt();
        arista[] cola = new arista[l];
        for (int i = 0; i < l; i++) {
            x = leer.nextInt();
            y = leer.nextInt();
            dist = leer.nextInt();
            cola[i] = new arista(x, y, dist);
        }
        Arrays.sort(cola);
        int max, min, t = n, u, v;

        for (int i = 0; i < l; i++) {
            n = t;
            pos = i;
            for (int j = 0; j <= n; j++) {
                padre[j] = j;
            }
            max = 0;
            min = 2000000005;
            while (n > 1 && pos < l) {
                if (find(ini) == find(fin)) {
                    n = 0;
                } else {
                    arista aux = cola[pos];
                    pos++;
                    u = find(aux.a);
                    v = find(aux.b);
                    if (u != v) {
                        padre[u] = v;
                        n--;
                        max = Math.max(max, aux.peso);
                        min = Math.min(min, aux.peso);

                    }
                }
            }
            if (find(ini) == find(fin)) {
                suma = Math.min(suma, max - min);
            }
        }
        if (suma == Long.MAX_VALUE) {
            System.out.println("NO PATH");
        } else {
            System.out.println(suma);
        }
    }

    public static class arista implements Comparable<arista> {

        public int a, b, peso;

        public arista(int x, int y, int peso) {
            this.a = x;
            this.b = y;
            this.peso = peso;
        }

        @Override
        public int compareTo(arista o) {
            if (this.peso > o.peso) {
                return 1;
            }
            if (this.peso < o.peso) {
                return -1;
            }
            return 0;
        }
    }

    public static int find(int x) {
        if (padre[x] != x) {
            padre[x] = find(padre[x]);
        }
        return padre[x];
    }
}
