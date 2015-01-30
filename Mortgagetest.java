/*
 * CTU Open Contest 2011
 *
 * Sample solution: Mortgage
 * Author: Martin Kacer
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
      	public static class System {
		public static java.io.InputStream in;
		public static java.io.PrintWriter out;

		static {
		  try {
		    in = new java.io.FileInputStream("j.in");
		    out = new java.io.PrintWriter("j.out");
		  } catch (Exception e) {
		    throw new RuntimeException(e);
		  }
		  java.lang.Runtime.getRuntime().addShutdownHook(new java.lang.Thread(new java.lang.Runnable() { public void run() { System.close(); } }));
		}

		public static void close() {
		  try {
		  in.close();
		  out.close();
		  } catch (Exception e) {
		    throw new RuntimeException(e);
		  }
		}
	}

	StringTokenizer st = new StringTokenizer("");
	BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[] args) throws Exception {
		Main instance = new Main();
		while (instance.run()) {/*repeat*/}
	}
	String nextToken() throws Exception {
		while (!st.hasMoreTokens()) st = new StringTokenizer(input.readLine());
		return st.nextToken();
	}
	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}
	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}
	
	boolean checkMortgage(double debt, double monthly, int years, double rate) {
		double rate1 = rate + 1.0;
		double rateALL = Math.pow(rate1, 12*years);
		double debtALL = debt * rateALL;
		double paidALL = rate < 1E-6
				? monthly * 12*years
				: monthly * (rateALL - 1.0) / rate;
		//System.out.println(" DBG: " + paidALL + " x " + debtALL);
		if (paidALL > 5E24 || debtALL > 5E24)
			System.out.println("numbers too high, inaccuracy danger!");
		return (paidALL > debtALL - 1E-5);
	}

	boolean run() throws Exception {
		double debt = nextDouble();
		if (debt < 1E-10) return false;
		double monthly = nextDouble();
		int years = nextInt();
		double rate = nextDouble() / 1200;
		boolean res = checkMortgage(debt, monthly, years, rate);
		boolean res2 = checkMortgage(debt, monthly, years, res ? rate + 2.5E-10 : rate - 2.5E-10);
		System.out.println(res ? "YES" : "NO");
		if (res != res2)
			System.out.println("rate too close to boundary: floating point inaccuracy danger!");
		return true;
	}
}
