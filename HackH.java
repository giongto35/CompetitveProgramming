import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;
 
public class HackH implements Runnable {
 
    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");
 
    public static void main(String[] args) {
        new Thread(null, new HackH(), "", 256 * (1L << 20)).start();
    }
 
    public void run() {
        try {
            long t1 = System.currentTimeMillis();
            if (System.getProperty("ONLINE_JUDGE") != null) {
                in = new BufferedReader(new InputStreamReader(System.in));
                out = new PrintWriter("h.inp");
            } else {
                in = new BufferedReader(new FileReader("input.txt"));
                out = new PrintWriter("h.inp");
            }
            Locale.setDefault(Locale.US);
            solve();
            in.close();
            out.close();
            long t2 = System.currentTimeMillis();
            System.err.println("Time = " + (t2 - t1));
        } catch (Throwable t) {
            t.printStackTrace(System.err);
            System.exit(-1);
        }
    }
 
    String readString() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }
 
    int readInt() throws IOException {
        return Integer.parseInt(readString());
    }
 
    long readLong() throws IOException {
        return Long.parseLong(readString());
    }
 
    double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }
 
    // solution
 
    int hashinv(int h) {
        h ^= (h >>> 4) ^ (h >>> 7) ^ (h >>> 8) ^ (h >>> 14) ^ (h >>> 15)
                ^ (h >>> 18) ^ (h >>> 19) ^ (h >>> 20) ^ (h >>> 21)
                ^ (h >>> 23) ^ (h >>> 26) ^ (h >>> 28);
        return h;
    }
 
    int bitreverse(int h) {
        int res = 0;
        for (int i = 0; i < 31; i++)
            if ((h & (1 << i)) != 0)
                res |= (1 << (30 - i));
        return res;
    }
 
    void solve() throws IOException {
        final int size = 50000;
        int[] s = new int[size];
        for (int i = 0, val = 0; i < size; i++) {
            s[i] = Integer.MAX_VALUE;
            while (s[i] > 1000000000)
                s[i] = hashinv(bitreverse(val++));
        }
 
Arrays.sort(s);
/*
List<Integer> list = new ArrayList<Integer>();
for (int i = 0; i < size; i++) list.add(s[i]);
Collections.shuffle(list, new Random(System.currentTimeMillis()));
for (int i = 0; i < size; i++) s[i] = list.get(i);
*/
       
        //out.println(size);
        for (int i = 0; i < size; i++) {
                out.println(s[i]);
                //if (i == size-1) out.println(); else o ut.print(' ');
        }
       
        long startTime = System.currentTimeMillis();
        HashSet<Integer> h = new HashSet<Integer>(size);
        for (int i = 0; i < size; i++)
                h.add(s[i]);
        System.out.println("HashSet adding time = " + (System.currentTimeMillis() - startTime));
    }
 
}
