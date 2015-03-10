import java.lang.reflect.Array;
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
		
		/*for(int i=0; i<m.getLineSize(); i++){ // linha
			for(int j=0; j<l; j++){
				double temp = 0;
				for(int k=0; k<l; k++){
					temp += own[i][k] * m.get(k,j);
				}
				result.set(i,j, temp);
			}
		}*/
		
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
		System.out.println( "Lines x Columns ?" );
		
		Scanner in = new Scanner(System.in);
		
		int lines = in.nextInt();
		
		int cols = in.nextInt();
		in.close();          
		
		Matrix m1 = new Matrix(lines, cols);
		Matrix m2 = new Matrix(lines, cols);
		
		m1.mult(m2);
		
		double totalTime = (m1.endTime - m1.startTime)/1000.0;
		
		System.out.println("Processing time: " + totalTime + " seconds");
	}
	
	/*public void Update(double buffer, int l, int c){
		
	}
		
	public double Buffer(){
		
	}
		
	public double operator() (int l, int c){
		
	}
		
	public void operator() (int l, int c, double v){
		
	}
	
	public double Address(int l, int c){
		
	}
	
	public double SomaCol(int c){
		
	}
	
	public double SomaLin(int l){
		
	}
	
	public double SomaAll(){
		
	}*/
}
