import java.lang.reflect.Array;
import java.util.Arrays;


public class Matrix {
	private int l, c;
	private double [][] own;


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
		return l;
	}
	
	public Matrix mult(Matrix m){
		Matrix result = new Matrix(l, c);
		for(int i=0; i<m.getLineSize(); i++){ // linha
			for(int j=0; j<l; j++){
				double temp = 0;
				for(int k=0; k<l; k++){
					temp += own[i][k] * m.get(k,j);
				}
				result.set(i,j, temp);
			}
		}
			
	}
	
	public void set(int l, int c, double value){
		own[l][c] = value;
	}
	
	public double get(int l, int c){
		return own[l][c];
	}
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
