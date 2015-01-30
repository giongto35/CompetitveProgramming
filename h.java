import java.io.*;
import java.util.*;
public class h {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader( new InputStreamReader(new FileInputStream("h.inp")) );
        HashSet<Long> hashset = new HashSet<Long>();
		System.out.println("Bat dau");
		Integer abc = 5;
		System.out.println(abc.hashcode());
        for (String x = in.readLine(); x != null ; x = in.readLine()) 
            hashset.add( Long.parseLong(x) );
		System.out.println("ketthuc");
    }
}
