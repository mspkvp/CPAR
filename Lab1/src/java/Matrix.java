import java.util.Arrays;
import java.util.Scanner;


public class Matrix {
	private int l, c;
	private double [][] own;
	private long startTime;
	private long endTime;


	public Matrix(int l, int c){
		this.l = l;
		this.c = c;
		own = new double [l][c];
		for(int i = 0; i<l; i++){
			Arrays.fill(own[i], 1.0);
		}
	}
	
	public int getLineSize(){
		return l;
	}
	
	public int getColumnSize(){
		return c;
	}
	
	public Matrix mult(Matrix m){
		Matrix result = new Matrix(l, c);
		
		startTime = System.currentTimeMillis();
		
		for(int i=0; i<m.getLineSize(); i++){ // linha
			for(int j=0; j<l; j++){
				double temp = 0;
				for(int k=0; k<l; k++){
					temp += own[i][k] * m.get(k,j);
				}
				result.set(i,j, temp);
			}
		}
		
		endTime = System.currentTimeMillis();
		
		return result;
	}
	
	public Matrix multOptimized(Matrix m){
		Matrix result = new Matrix(l, c);
		
		startTime = System.currentTimeMillis();
		
		for(int i=0; i<m.getLineSize(); i++){ // linha
			for(int k=0; k<l; k++){
				for(int j=0; j<l; j++){
                    result.set(i,j, own[i][k] * m.get(k,j) + result.get(i,j));
				}
			}
		}
		
		endTime = System.currentTimeMillis();
		
		return result;
	}
	
	public void set(int l, int c, double value){
		own[l][c] = value;
	}
	
	public double get(int l, int c){
		return own[l][c];
	}
	
	public static void main(String args[]){
		System.out.print( "Lines x Columns ? > " );
		
		Scanner in = new Scanner(System.in);
		
		int lines = in.nextInt();
		
		int cols = in.nextInt();         
			
		System.out.println( "\n1. Normal." );
		System.out.println( "2. Optimized." );
		System.out.print( "Selection ? > " );
		
		//in = new Scanner(System.in);
		
		int selection = in.nextInt();
		in.close();  
		
		Matrix m1 = new Matrix(lines, cols);
		Matrix m2 = new Matrix(lines, cols);
		
		if(selection == 2){
			System.out.println("\n::::: Optimized Algorithm");
			m1.multOptimized(m2);
		}
		else {
			System.out.println("\n::::: Normal Algorithm");
			m1.mult(m2);
		}
			
		
		double totalTime = (m1.endTime - m1.startTime)/1000.0;
		
		System.out.println("Processing time: " + totalTime + " seconds");
	}
	
}
